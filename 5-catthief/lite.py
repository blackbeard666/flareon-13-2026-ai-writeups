import socket, threading, frida, time, subprocess, os, random, sys
CANDS=[int(x,16) for x in sys.argv[1:]]
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
        c.sendall(b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'+(resps[n] if n<len(resps) else b'')); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var NEW='C:\Users\cavila\r.jpg';
['kernel32.dll','kernelbase.dll'].forEach(function(dll){try{Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){try{var p=a[0].readUtf16String();if(p&&p.indexOf('flare')>=0){a[0].writeUtf16String(NEW);}}catch(e){}}});}catch(e){}});
var base=Process.enumerateModules()[0].base; var OFFS=OFFP; var seen={};
OFFS.forEach(function(off){ try{Interceptor.attach(base.add(off),{onEnter:function(a){
  if(seen[off])return;
  var rdx=this.context.rdx, r8=this.context.r8, r9=this.context.r9;
  [rdx,r9].forEach(function(p){ try{ if(p.compare(ptr(0x10000))<0)return; var v=hx(p,12); if(v&&(v.indexOf('2000061a')==0||v.indexOf('e728a1')==0)){ seen[off]=1; send({fn:off.toString(16),head:v}); } }catch(e){} });
}});}catch(e){} });
send({log:'ok'});
""".replace('OFFP',str(CANDS))
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: pass
        elif 'fn' in p: print('[BUF] fn=%(fn)s head=%(head)s'%p,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(18)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
