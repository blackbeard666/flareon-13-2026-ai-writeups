import socket, threading, frida, time, subprocess, os, random
NZ=3300000
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
        c.sendall(hdr+(b'\x00'*NZ if n==0 else b'')); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var ks40=[0xc7,0x28,0xa7,0x15,0x70,0x8a,0x98,0x84];
['kernel32.dll','kernelbase.dll'].forEach(function(dll){try{Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){
  try{ var b=new Uint8Array(a[0].readByteArray(8));
    if(b[0]==0xc7&&b[1]==0x28&&b[2]==0xa7&&b[3]==0x15){ send({found:a[0].toString()}, a[0].readByteArray(3300000)); }
  }catch(e){}
}});}catch(e){}});
send({log:'ok'});
"""
ks=None
def on_msg(m,d):
    global ks
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[f] ok',flush=True)
        elif 'found' in p: print('[f] KS buffer at',p['found'],'len',len(d) if d else 0,flush=True); ks=bytes(d) if d else None
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(15)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if ks:
    open('KS_real.bin','wb').write(ks); print('KS_real len',len(ks),'head',ks[:16].hex(),flush=True)
else: print('no KS',flush=True)
