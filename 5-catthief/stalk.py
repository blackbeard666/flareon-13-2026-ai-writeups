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
var lo=base, hi=base.add(0x145000);
var following=false; var calls={};
var bodyBuf=null;
// start stalking on connect, stop on body send
Interceptor.attach(Module.getExportByName('ws2_32.dll','connect'),{onEnter:function(a){
  if(following)return; following=true;
  Stalker.follow(this.threadId,{events:{call:true}, onReceive:function(ev){
     var p=Stalker.parse(ev,{annotate:false});
     for(var i=0;i<p.length;i++){ var tgt=p[i][1]; // [type,target,depth?] for call: [location,target,depth]
       // call event: ['call', location, target, depth]
     }
  }});
}});
// Simpler: hook the specific AES/clmul funcs
[0xa01ad,0xa07ed,0xa1050,0xa1250, 0xcb6a,0xd0c1,0xa3240,0xa33e0,0xa34a0,0xa3d00,0xa4cc0,0xa5180,0xa5400,0xa5ae0,0xa5ca0].forEach(function(off){
  try{Interceptor.attach(base.add(off),{onEnter:function(a){ calls[off]=(calls[off]||0)+1; if(calls[off]==1) send({fired:off.toString(16)}); }});}catch(e){}
});
// hook send to dump body buffers
Interceptor.attach(Module.getExportByName('ws2_32.dll','send'),{onEnter:function(a){
  var len=this.context.r8.toInt32(); var buf=a[1];
  if(len>50&&len<2000){ var b=new Uint8Array(buf.readByteArray(len)); var s='';for(var i=0;i<Math.min(len,32);i++)s+=('0'+b[i].toString(16)).slice(-2); send({sent:len,head:s}); }
}});
send({log:'set'});
"""
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'fired' in p: print('[FIRED] crypto func @',p['fired'],flush=True)
        elif 'sent' in p: print('[SEND] len=%(sent)s head=%(head)s'%p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach(); print('done')
