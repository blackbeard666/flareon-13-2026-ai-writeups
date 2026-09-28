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
        time.sleep(1); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
var total=0;
Interceptor.attach(Module.getExportByName('ws2_32.dll','recv'),{onLeave:function(r){var n=r.toInt32(); if(n>0)total+=n;}});
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
rpc.exports={total:function(){return total;}, scan:function(){ var out=null;
  Process.enumerateRanges({protection:'rw-',coalesce:true}).forEach(function(r){
    if(out) return;
    try{ var ms=Memory.scanSync(r.base,r.size,'20 00 06 1a 80 01 01 01 51 0b 0c 12'); if(ms.length){ out=ms[0].toString(); } }catch(e){}
  }); return out; }};
send({log:'ok'});
"""
def on_msg(m,d):
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
addr=None
t0=time.time()
while time.time()-t0<18:
    time.sleep(1.2)
    try:
        a=scr.exports_sync.scan()
        if a: addr=a; print('[found] message_b1 at',a,flush=True); break
    except: pass
try: tot=scr.exports_sync.total(); print('total recv bytes:',tot,flush=True)
except: pass
msg=None
if addr:
    try: msg=bytes(scr.exports_sync.__getattr__('read')(addr)) if False else None
    except: pass
    # read via a read export
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
