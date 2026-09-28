import socket, threading, frida, time, subprocess, os, random, json
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
RESP=open('streams/body_49680.bin','rb').read()
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
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n'%len(RESP)+RESP)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Process.enumerateModules()[0].base; var ar=false;
Interceptor.attach(Module.getExportByName('ws2_32.dll','recv'),{onLeave:function(r){ar=true;}});
var seen={};
Interceptor.attach(base.add(0x75e8b),{onEnter:function(a){ if(!ar)return;
  var ps=[this.context.rcx,this.context.rdx];
  for(var k=0;k<ps.length;k++){var p=ps[k]; if(p.compare(ptr(0x10000))<0)continue; var v=hx(p,248);
    if(v&&v.indexOf('52454144')==0&&!seen[v]){seen[v]=1;send({v:v});}}
}});
send({log:'ok'});
"""
def runonce():
    got=set()
    def on_msg(m,d):
        if m['type']=='send' and 'v' in m['payload']: got.add(m['payload']['v'])
    dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
    time.sleep(9)
    try: dev.kill(pid)
    except: pass
    sess.detach(); return got
a=runonce(); b=runonce()
try: os.remove(tmp)
except: pass
common=a&b
print('run1',len(a),'run2',len(b),'common',len(common))
c1=RESP
for v in common:
    pt=bytes.fromhex(v); ks=bytes(pt[i]^c1[i] for i in range(len(pt)))
    print('CONST PT:',pt[:80]); print('  KS:',ks.hex())
    open('KS_final.bin','wb').write(ks)
