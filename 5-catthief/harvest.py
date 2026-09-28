import socket, threading, frida, time, subprocess, os, random
raw = bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
bodies=[]; reqno=[0]
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
        import re
        m=re.search(rb'Content-Length: (\d+)',d); bs=d.find(b'\r\n\r\n')+4; body=d[bs:]
        if m:
            need=int(m.group(1))
            while len(body)<need:
                x=c.recv(65536)
                if not x:break
                body+=x
        n=reqno[0]; reqno[0]+=1
        bodies.append(body); print('[c2] req#%d len=%d head=%s'%(n,len(body),body[:12].hex()),flush=True)
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 0\r\n\r\n')
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js="['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});"
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.load(); dev.resume(pid)
time.sleep(25)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
# find the biggest body (exfil of a zero file = keystream)
big=max(bodies,key=len) if bodies else b''
if len(big)>1000:
    open('KS_full.bin','wb').write(big); print('KS_full len',len(big),'head',big[:16].hex(),flush=True)
print('total reqs',len(bodies),'sizes',[len(b) for b in bodies],flush=True)
