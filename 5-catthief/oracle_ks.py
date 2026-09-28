import socket, threading, frida, time, subprocess, os, random
B1=open('exfil_bodies/b1.bin','rb').read()  # 3.2MB exfil ciphertext of known random
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
reqno=[0]
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1); s.bind(('127.0.0.1',8080)); s.listen(16)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(30)
    try:
        d=b''
        while b'\r\n\r\n' not in d:
            x=c.recv(65536)
            if not x:break
            d+=x
        n=reqno[0]; reqno[0]+=1; print('[c2] req#%d'%n,flush=True)
        hdr=b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        c.sendall(hdr+(B1 if n==0 else b'')); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var recvbufs=[];
Interceptor.attach(Module.getExportByName('ws2_32.dll','recv'),{onEnter:function(a){this.b=this.context.rdx;},onLeave:function(r){ var n=r.toInt32(); if(this.b&&n>1000){ recvbufs.push([this.b,n]); } }});
rpc.exports={dump:function(){ var out=[]; recvbufs.forEach(function(rb){ try{ out.push([rb[0].toString(), rb[0].readByteArray(rb[1])]); }catch(e){} }); return out; }};
send({log:'ok'});
"""
res=[]
def on_msg(m,d): 
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(16)
try: res=scr.exports_sync.dump()
except Exception as e: print('dumperr',e,flush=True)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
ks40=bytes.fromhex('c728a715708a98840dae290d0d983abe6cad44ae901586b9ae1a12deb8f35d061266a2d8c0d8fd')
# concatenate recv chunks per buffer; find one that XORs with B1 to give KS matching ks40
print('recv chunks:',len(res),flush=True)
# reassemble: recv buffers may be chunks of the response body. Collect all bytes after the first that look like decrypted
allbufs=[bytes(d) for a,d in res if d]
for b in allbufs:
    if len(b)<100: continue
    # if this is message_b1 (decrypted), b ^ B1 should = KS. Check ks40.
    if len(b)>=40:
        cand=bytes(b[i]^B1[i] for i in range(40))
        if cand==ks40:
            print('FOUND message_b1! len',len(b),flush=True)
            open('message_b1.bin','wb').write(b)
            ks=bytes(b[i]^B1[i] for i in range(min(len(b),len(B1))))
            open('KS_real.bin','wb').write(ks); print('KS_real len',len(ks),flush=True)
            break
else:
    print('not found; buf lens:',[len(b) for b in allbufs][:10],flush=True)
