import socket, threading, frida, time, subprocess, os, random, json
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
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
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Process.enumerateModules()[0].base;
Interceptor.attach(base.add(0x75e8b),{onEnter:function(a){
  var rcx=this.context.rcx, rdx=this.context.rdx, r8=this.context.r8;
  send({rcx:hx(rcx,16),rdx:hx(rdx,16),r8:r8.toString()});
  // dump rdx buffer as READY plaintext if it starts with READY
  var head=hx(rdx,5);
  if(head=='5245414459'){ var n=r8.toInt32(); if(n<0||n>200000)n=248; send({PT:hx(rdx,n),len:n}); }
}});
send({log:'hook 75e8b'});
"""
PT=[]
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'PT' in p: PT.append(p['PT']); print('[PT] len=%(len)s'%p,flush=True)
        elif 'rdx' in p: print('   75e8b rcx=%(rcx)s rdx=%(rdx)s r8=%(r8)s'%p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if PT:
    pt=bytes.fromhex(PT[0]); open('my_pt1.bin','wb').write(pt)
    c=open('streams/body_49680.bin','rb').read()
    ks=bytes(pt[i]^c[i] for i in range(min(len(pt),len(c))))
    open('ks.bin','wb').write(ks)
    print('PT1 len',len(pt),'KS len',len(ks))
    print('PT1:',pt[:120])
print('done, PTs:',len(PT))
