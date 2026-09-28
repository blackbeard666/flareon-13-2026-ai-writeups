import socket, threading, frida, time, subprocess, os, random
NZ=200000
raw = bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
reqno=[0]
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1); s.bind(('127.0.0.1',8080)); s.listen(16)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(20)
    try:
        d=b''
        while b'\r\n\r\n' not in d:
            x=c.recv(65536)
            if not x:break
            d+=x
        n=reqno[0]; reqno[0]+=1
        print('[c2] req#%d'%n,flush=True)
        hdr=b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        if n==0: c.sendall(hdr+b'\x00'*NZ)
        else: c.sendall(hdr)
        c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var recvbufs=[];
Interceptor.attach(Module.getExportByName('ws2_32.dll','recv'),{onEnter:function(a){this.b=this.context.rdx;this.l=this.context.r8.toInt32();},onLeave:function(r){ if(this.b&&this.l>=200){ recvbufs.push([this.b,r.toInt32()]); } }});
// after all recv, on next connect(send of req#1) dump recvbufs decrypted content
rpc.exports={dump:function(){ var out=[]; recvbufs.forEach(function(rb){ out.push(hx(rb[0], Math.min(rb[1],300000))); }); return out; }};
send({log:'ok'});
"""
res=[]
def on_msg(m,d):
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(10)
try: res=scr.exports_sync.dump()
except Exception as e: print('dump err',e,flush=True)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
# test each recv buffer as KS: does it decrypt pcap request body_49680 to low-entropy/known?
c1=open('streams/body_49680.bin','rb').read()
print('recv buffers:',len(res),flush=True)
for v in res:
    b=bytes.fromhex(v)
    # if this is the decrypted zero-response, it's KS. Test: does body_49680 ^ b[skip http] give sensible?
    # find where the KS portion starts (after HTTP headers in recv buffer)
    idx=b.find(b'\r\n\r\n')
    ks = b[idx+4:] if idx>=0 else b
    if len(ks)<40: continue
    # KS should decrypt responses: check KS[0:40] vs known
    dec=bytes(c1[i]^ks[i] for i in range(min(40,len(ks))))
    print('buflen',len(b),'kslen',len(ks),'body49680^ks[:24]:',dec[:24])
    if len(ks)>=100000:
        open('KS_big.bin','wb').write(ks); print('SAVED KS_big len',len(ks),flush=True)
