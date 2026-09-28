import socket, threading, frida, time, subprocess, os, random
KS=bytes.fromhex('c728a715708a98840dae290d0d983abe6cad44ae901586b9ae1a12deb8f35d061266a2d8c0d8fd')
MYPATH=b'C:\Users\cavila\Desktop\important.jpg'
cmd=bytes(MYPATH[i]^KS[i] for i in range(len(MYPATH)))
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
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
        n=reqno[0]; reqno[0]+=1; print('[c2] req#%d'%n,flush=True)
        hdr=b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        c.sendall(hdr+(cmd if n==0 else b'')); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function asc(p){try{return p.readUtf16String();}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
Interceptor.attach(Module.getExportByName('kernel32.dll','CreateFileW'),{onEnter:function(a){var p=asc(a[0]); if(p&&p.length>3)send({cf:p});}});
send({log:'ok'});
"""
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[f] ok',flush=True)
        elif 'cf' in p:
            s=p['cf']
            if 'jpg' in s or 'Desktop' in s or 'cavila' in s or 'important' in s: print('[CreateFileW]',s,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
print('done')
