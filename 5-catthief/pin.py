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
calls=[o for o,c in json.load(open('callset.json'))]
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
function asc(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++){var c=b[i];s+=(c>=32&&c<127)?String.fromCharCode(c):'.';}return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var mod=Process.enumerateModules()[0]; var base=mod.base;
var OFFS=OFFPLACEHOLDER;
OFFS.forEach(function(off){ try{ var f=base.add(off);
  Interceptor.attach(f,{onEnter:function(a){
    [['rcx',this.context.rcx],['rdx',this.context.rdx],['r8',this.context.r8],['r9',this.context.r9]].forEach(function(rr){
      var name=rr[0], p=rr[1];
      if(p.compare(ptr(0x1000))<0) return;
      var hexv=hx(p,16); if(!hexv) return;
      if(hexv.indexOf('e728a715')==0 || hexv.indexOf('1f8b08')==0 || hexv.indexOf('789c')==0 || hexv.indexOf('7801')==0){
        send({off:off.toString(16),reg:name,hex:hx(p,32)});
      } else {
        var s=asc(p,24);
        if(s && (s.indexOf('READY')>=0 || s.indexOf('hostname')>=0 || s.indexOf('user')>=0)) send({off:off.toString(16),reg:name,asc:s});
      }
    });
  }});
 }catch(e){}
});
send({log:'hooked '+OFFS.length});
""".replace('OFFPLACEHOLDER', json.dumps(calls))
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'hex' in p: print('[HEX] fn=%(off)s %(reg)s %(hex)s'%p,flush=True)
        elif 'asc' in p: print('[ASC] fn=%(off)s %(reg)s %(asc)s'%p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device()
pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
print('done')
