import socket, threading, frida, time, subprocess, os, random, sys
RESPFILE=sys.argv[1] if len(sys.argv)>1 else 'streams/body_49681.bin'
RESP=open(RESPFILE,'rb').read()
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
        c.sendall(b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'+(RESP if n==0 else b''))
        time.sleep(2); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
rpc.exports={scan:function(pat){ var res=[];
  Process.enumerateRanges({protection:'rw-',coalesce:true}).forEach(function(r){
    try{ var ms=Memory.scanSync(r.base,r.size,pat); ms.forEach(function(m){ res.push([m.address.toString(), m.address.readByteArray(200000)]); }); }catch(e){}
  }); return res; }};
send({log:'ok'});
"""
def on_msg(m,d):
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
got=None
t0=time.time()
while time.time()-t0<18:
    time.sleep(1.2)
    for pat in ['ff d8 ff e0','ff d8 ff e1','66 6c 61 72 65 2d 6f 6e']:
        try:
            r=scr.exports_sync.scan(pat)
            if r: print('[found]',pat,'at',r[0][0],flush=True); got=bytes(r[0][1]); break
        except: pass
    if got: break
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if got:
    open('recovered.bin','wb').write(got)
    print('recovered',len(got),'head',got[:16].hex(),flush=True)
    idx=got.find(b'flare-on') 
    if idx<0: idx=got.lower().find(b'flare')
    if idx>=0: print('FLAG CONTEXT:',got[max(0,idx-40):idx+40],flush=True)
else: print('not found',flush=True)
