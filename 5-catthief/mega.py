import socket, threading, frida, time, subprocess, os, random
# 1) extract exe bytes to temp
rnd='svc_%d.exe'%random.randint(1000,9999)
tmp=os.path.join(os.environ.get('TEMP','.'),rnd)
p=subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True)
open(tmp,'wb').write(p.stdout)
print('wrote',len(p.stdout),'to',tmp,flush=True)
# 2) c2
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
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return 'x';}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Module.getBaseAddress(Process.enumerateModules()[0].name);
var mod=Process.enumerateModules()[0]; base=mod.base; var size=mod.size;
var following=false; var calls={};
Interceptor.attach(Module.getExportByName('ws2_32.dll','send'),{onEnter:function(a){
  var len=this.context.r8.toInt32(); var buf=a[1]; var first=buf.readU8();
  if(first==0x50 && !following){ following=true;
    Stalker.follow(this.threadId,{events:{call:true}, onCallSummary:function(sum){
      for(var addr in sum){var pp=ptr(addr); if(pp.compare(base)>=0&&pp.compare(base.add(size))<0){var off=pp.sub(base).toInt32(); calls[off]=(calls[off]||0)+sum[addr];}}
    }});
  } else if(following && len>=200 && len<100000 && first!=0x50){
    Stalker.unfollow(this.threadId); following=false;
    var arr=[]; for(var o in calls)arr.push([parseInt(o),calls[o]]); arr.sort(function(a,b){return b[1]-a[1];});
    send({calls:arr.slice(0,80)});
  }
  if(len>=200 && first!=0x50) send({body:hx(buf,Math.min(len,64)),len:len});
}});
send({log:'ready base='+base});
"""
res={'calls':None,'bodies':[]}
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'calls' in p: res['calls']=p['calls']; print('[*] captured',len(p['calls']),'callees',flush=True)
        elif 'body' in p: res['bodies'].append((p['len'],p['body'])); print('[BODY] len=%(len)s head=%(body)s'%p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device()
try:
    pid=dev.spawn([tmp]); sess=dev.attach(pid)
    scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
    time.sleep(14)
    try: dev.kill(pid)
    except: pass
    sess.detach()
except Exception as e:
    print('SPAWN ERR',e,flush=True)
import json
if res['calls']: open('callset.json','w').write(json.dumps(res['calls']))
try: os.remove(tmp)
except: pass
print('done, bodies:',len(res['bodies']))
