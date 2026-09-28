import socket, threading, frida, time, subprocess, os, random, json
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
RESP=open('streams/body_49680.bin','rb').read()
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1); s.bind(('127.0.0.1',8080)); s.listen(16)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(6)
    try:
        d=b''
        while b'\r\n\r\n' not in d:
            x=c.recv(65536)
            if not x:break
            d+=x
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n'%len(RESP)+RESP)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Process.enumerateModules()[0].base;
var recvbufs=[];
Interceptor.attach(Module.getExportByName('ws2_32.dll','recv'),{onEnter:function(a){this.buf=this.context.rdx;},onLeave:function(r){ if(this.buf) recvbufs.push(this.buf); }});
var last={};
Interceptor.attach(base.add(0x75e8b),{onEnter:function(a){
  for(var i=0;i<recvbufs.length;i++){ var b=recvbufs[i]; var v=hx(b,264); if(v && last[i]!=v){ last[i]=v; send({buf:i,v:v}); } }
}});
send({log:'ok'});
"""
snaps=[]
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'buf' in p: snaps.append(p['v'])
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(10)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
print('recv-buffer snapshots:',len(snaps))
c1=RESP
for v in dict.fromkeys(snaps):
    pt=bytes.fromhex(v)
    # skip if it's the response ciphertext itself (body_49680)
    if pt[:16]==c1[:16]: 
        print('[ct]',pt[:16].hex()); continue
    print('[changed] PT:',pt[:80])
    ks=bytes(pt[i]^c1[i] for i in range(min(len(pt),len(c1))))
    if pt[:5]==b'READY': open('KS_true.bin','wb').write(ks); print('   KS[:32]:',ks[:32].hex(),'SAVED')
