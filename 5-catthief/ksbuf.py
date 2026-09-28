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
['kernel32.dll','kernelbase.dll'].forEach(function(dll){try{Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){try{var p=a[0].readUtf16String();if(p&&p.indexOf('flare')>=0){a[0].writeUtf16String(NEW);}}catch(e){}}});}catch(e){}});
rpc.exports={scan:function(){ var out=[];
  Process.enumerateRanges({protection:'rw-',coalesce:true}).forEach(function(r){
    try{ var ms=Memory.scanSync(r.base,r.size,'c7 28 a7 15 70 8a 98 84 0d ae 29 0d'); ms.forEach(function(m){ out.push([m.address.toString(), m.address.readByteArray(300)]); }); }catch(e){}
  });
  return out;
}};
send({log:'ok'});
"""
hits=[]
def on_msg(m,d): 
    if m['type']=='send' and 'log' in m.get('payload',{}): print('[f] ok',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
t0=time.time()
while time.time()-t0<25:
    time.sleep(2)
    try:
        r=scr.exports_sync.scan()
        if r:
            print('[scan] KS buffer candidates:',len(r),flush=True)
            for addr,data in r:
                b=bytes(data); print('  at',addr,b[:40].hex(),flush=True)
            hits=r; break
    except Exception as e: print('e',e,flush=True)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
# if a hit is a long KS buffer, save it
for addr,data in hits:
    b=bytes(data)
    # verify it decrypts responses
    resp0=open('resps/r0.bin','rb').read()
    dec=bytes(resp0[i]^b[i] for i in range(min(len(resp0),len(b))))
    print('decrypt resp0 with candidate:',dec[:40],flush=True)
