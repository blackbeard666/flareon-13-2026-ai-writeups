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
var pt=null;
Interceptor.attach(base.add(0x75e8b),{onEnter:function(a){
  var ps=[this.context.rcx,this.context.rdx];
  for(var k=0;k<ps.length;k++){var p=ps[k]; if(p.compare(ptr(0x10000))<0)continue; var v=hx(p,264); if(v&&v.indexOf('52454144')==0&&!pt){pt=v; send({pt:v});}}
}});
Interceptor.attach(Module.getExportByName('ws2_32.dll','send'),{onEnter:function(a){
  var len=this.context.r8.toInt32(); var buf=a[1];
  if(len>=200&&len<400&&buf.readU8()!=0x50) send({ct:hx(buf,len),len:len});
}});
send({log:'ok'});
"""
def run(extra_env):
    env=dict(os.environ); env.update(extra_env)
    got={}
    def on_msg(m,d):
        if m['type']=='send':
            p=m['payload']
            if 'pt' in p: got['pt']=p['pt']
            elif 'ct' in p: got.setdefault('ct',p['ct'])
    dev=frida.get_local_device(); pid=dev.spawn([tmp],env=env); sess=dev.attach(pid)
    scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
    time.sleep(9)
    try: dev.kill(pid)
    except: pass
    sess.detach()
    return got
r1=run({'FLAREX':'AAAA'})
r2=run({'FLAREX':'ZZZZZZZZZZ'})
try:
    os.remove(tmp)
except: pass
for name,r in [('run1',r1),('run2',r2)]:
    if 'pt' in r and 'ct' in r:
        pt=bytes.fromhex(r['pt'])[:248]; ct=bytes.fromhex(r['ct'])[:248]
        ks=bytes(pt[i]^ct[i] for i in range(248)); r['ks']=ks.hex()
        print(name,'pt_head',pt[:16].hex(),'ct_head',ct[:16].hex())
if 'ks' in r1 and 'ks' in r2:
    print('KS match?', r1['ks']==r2['ks'])
    print('KS1',r1['ks'][:64]); print('KS2',r2['ks'][:64])
    if r1['ks']==r2['ks']: open('KS_valid.bin','wb').write(bytes.fromhex(r1['ks']))
