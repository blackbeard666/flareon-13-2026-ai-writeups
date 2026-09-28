import socket, threading, frida, time, subprocess, os, random
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
# patch an inert byte in DOS stub message to change hash
i=raw.find(b'This program cannot')
if i>0: raw[i]=ord('t')  # 'T'->'t'
rnd='upd_%d.exe'%random.randint(10000,99999)
tmp=os.path.join(os.environ.get('TEMP','.'),rnd)
open(tmp,'wb').write(raw); print('wrote',len(raw),tmp,flush=True)
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    s.bind(('127.0.0.1',8080)); s.listen(16)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(6)
    try:
        d=b''
        while b'\r\n\r\n' not in d:
            x=c.recv(65536)
            if not x: break
            d+=x
        import re
        m=re.search(rb'Content-Length: (\d+)',d); bs=d.find(b'\r\n\r\n')+4; body=d[bs:]
        if m:
            need=int(m.group(1))
            while len(body)<need:
                x=c.recv(65536)
                if not x: break
                body+=x
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return 'x';}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var mod=Process.enumerateModules()[0]; var base=mod.base, size=mod.size;
var following=false; var calls={};
 try{Interceptor.attach(base.add(0x29aa),{onEnter:function(a){ if(following)return; following=true; Stalker.follow(this.threadId,{events:{call:true}, onCallSummary:function(sum){ for(var addr in sum){var pp=ptr(addr); if(pp.compare(base)>=0&&pp.compare(base.add(size))<0){var off=pp.sub(base).toInt32(); calls[off]=(calls[off]||0)+sum[addr];}} }}); }});}catch(e){send({err:'attach '+e});}
var dumped=false;
Interceptor.attach(Module.getExportByName('ws2_32.dll','send'),{onEnter:function(a){
  var len=this.context.r8.toInt32(); var buf=a[1]; var first=buf.readU8();
  if(following && !dumped && first!=0x50 && len>=200){ dumped=true; Stalker.flush(); Stalker.unfollow(this.threadId);
    var arr=[]; for(var o in calls)arr.push([parseInt(o),calls[o]]); arr.sort(function(a,b){return b[1]-a[1];});
    send({calls:arr.slice(0,120)});
  }
  if(first!=0x50 && len>=100) send({body:hx(buf,Math.min(len,48)),len:len});
}});
send({log:'base='+base});
"""
res={'calls':None}
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'calls' in p: res['calls']=p['calls']; print('[*] callees',len(p['calls']),flush=True)
        elif 'body' in p: print('[BODY] len=%(len)s %(body)s'%p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device()
try:
    pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
    time.sleep(14)
    try: dev.kill(pid)
    except: pass
    sess.detach()
except Exception as e: print('SPAWN ERR',e,flush=True)
import json
if res['calls']: open('callset.json','w').write(json.dumps(res['calls'])); print('saved callset')
try: os.remove(tmp)
except: pass
print('done')
