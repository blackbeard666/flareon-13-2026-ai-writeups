import socket, threading, frida, time
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    s.bind(('127.0.0.1',8080)); s.listen(16); print('[c2] up',flush=True)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(5)
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
EXE=r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Module.getBaseAddress('catthief.exe');
var size=%d;
var lo=base, hi=base.add(size);
var following=false; var callset={};
var sendp=Module.getExportByName('ws2_32.dll','send');
Interceptor.attach(sendp,{onEnter:function(a){
  var len=this.context.r8.toInt32(); var buf=a[1];
  var first=buf.readU8();
  if(first==0x50 && !following){ // 'P' POST headers -> start stalking
    following=true;
    Stalker.follow(this.threadId,{events:{call:true}, onCallSummary:function(sum){
      for(var addr in sum){ var p=ptr(addr); if(p.compare(lo)>=0 && p.compare(hi)<0){ var off=p.sub(base).toInt32(); callset[off]=(callset[off]||0)+sum[addr]; } }
    }});
  } else if(following && len>=200 && len<400){ // body send -> stop
    Stalker.unfollow(this.threadId);
    following=false;
    // dump callset sorted by count
    var arr=[]; for(var o in callset) arr.push([parseInt(o),callset[o]]);
    arr.sort(function(a,b){return b[1]-a[1];});
    send({calls:arr.slice(0,60), bodylen:len});
  }
}});
send({log:'set'});
""" % (0x145000)
res={}
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'calls' in p:
            print('[*] body len',p['bodylen'],'unique callees:',len(p['calls']),flush=True)
            for off,cnt in p['calls']:
                print('   %#x  x%d'%(off,cnt),flush=True)
            res['calls']=p['calls']
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach()
import json; open('callset.json','w').write(json.dumps(res.get('calls',[])))
print('done')
