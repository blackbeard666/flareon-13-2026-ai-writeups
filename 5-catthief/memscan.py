import socket, threading, frida, time, subprocess, os, random
resps=[open('resps/r%d.bin'%k,'rb').read() for k in range(6)]
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
        c.sendall(hdr+(resps[n] if n<len(resps) else b'')); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var NEW='C:\Users\cavila\r.jpg';
['kernel32.dll','kernelbase.dll'].forEach(function(dll){try{Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){try{var p=a[0].readUtf16String();if(p&&p.indexOf('flare')>=0&&p.indexOf('.jpg')>=0){a[0].writeUtf16String(NEW);}}catch(e){}}});}catch(e){}});
rpc.exports={scan:function(){
  var pat='20 00 06 1a 80 01 01 01 51 0b 0c 12';
  var found=[];
  Process.enumerateRanges({protection:'rw-',coalesce:true}).forEach(function(r){
    if(r.size<200000) return;
    try{ var ms=Memory.scanSync(r.base,r.size,pat); ms.forEach(function(m){ found.push(m.address.toString()); }); }catch(e){}
  });
  return found;
},read:function(addr,len){ try{return ptr(addr).readByteArray(len);}catch(e){return null;} }};
send({log:'ok'});
"""
def on_msg(m,d):
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
found=[]; msg=None
t0=time.time()
while time.time()-t0<35:
    time.sleep(1.5)
    try:
        f=scr.exports_sync.scan()
    except Exception as e:
        print('scanerr',e,flush=True); continue
    if f:
        found=f; print('[scan] found at',f,flush=True)
        try:
            data=scr.exports_sync.read(f[0],3300000)
        except Exception as e:
            print('readerr',e,flush=True); data=None
        if data:
            msg=bytes(data); open('message_b1.bin','wb').write(msg); print('read message_b1 len',len(msg),flush=True); break
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if msg:
    b1=open('exfil_bodies/b1.bin','rb').read()
    ks=bytes(b1[i]^msg[i] for i in range(min(len(b1),len(msg))))
    open('KS_real.bin','wb').write(ks); print('KS_real len',len(ks),'head',ks[:16].hex(),flush=True)
