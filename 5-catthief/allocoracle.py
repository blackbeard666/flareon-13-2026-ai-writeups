import socket, threading, frida, time, subprocess, os, random
B1=open('exfil_bodies/b1.bin','rb').read()
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
        c.sendall(b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'+(B1 if n==0 else b''))
        time.sleep(3); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var bufs=[];
// hook allocations of ~3.3MB
['RtlAllocateHeap'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ntdll.dll',fn),{onEnter:function(a){this.sz=this.context.r8.toInt32();},onLeave:function(r){ if(this.sz>3000000&&this.sz<7000000){ bufs.push([r.toString(),this.sz]); } }});}catch(e){}});
rpc.exports={ dump:function(){ var out=[]; bufs.forEach(function(b){ try{ var p=ptr(b[0]); var head=new Uint8Array(p.readByteArray(12)); out.push([b[0],b[1], p.readByteArray(12)]); }catch(e){} }); return out; },
  read:function(a){ try{return ptr(a).readByteArray(3300000);}catch(e){return null;} } };
send({log:'ok'});
"""
def on_msg(m,d):
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
found=None
t0=time.time()
while time.time()-t0<20:
    time.sleep(1)
    try:
        d=scr.exports_sync.dump()
        for a,sz,head in d:
            hh=bytes(head)
            if hh[:4]==bytes.fromhex('2000061a'): print('[found alloc]',a,sz,hh.hex(),flush=True); found=a; break
        if found: break
    except Exception as e: pass
msg=None
if found:
    try: msg=bytes(scr.exports_sync.read(found))
    except: pass
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if msg:
    open('message_b1_real.bin','wb').write(msg)
    ks=bytes(B1[i]^msg[i] for i in range(min(len(B1),len(msg))))
    open('KS_real.bin','wb').write(ks); print('KS_real len',len(ks),'head',ks[:16].hex(),flush=True)
else: print('not captured',flush=True)
