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
funcs=[l.strip() for l in open('cryptofuncs.txt') if l.strip()]
EXE=r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js="""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return 'x';}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Module.getBaseAddress('catthief.exe');

try{Interceptor.attach(Module.getExportByName('ws2_32.dll','send'),{onEnter:function(a){send({sent:1});}});}catch(e){}
var FL=%s;
FL.forEach(function(va){ var off=parseInt(va,16)-0x140000000; var f=base.add(off);
  Interceptor.attach(f,{onEnter:function(a){ if(stop)return;
    send({f:va, rcx:hx(this.context.rcx,32), rdx:hx(this.context.rdx,32), r8:this.context.r8.toString(), r9:hx(this.context.r9,32), st:hx(this.context.rsp.add(0x28).readPointer(),16)});
  }});
});
send({log:'hooked '+FL.length});
""" % (str(funcs).replace("'",'"'))
order=[]
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'sent' in p: print('[*] first send reached',flush=True)
        elif 'f' in p:
            order.append(p)
            print('FN %(f)s r8=%(r8)s'%p)
            print('   rcx=%(rcx)s'%p); print('   rdx=%(rdx)s'%p); print('   r9=%(r9)s st=%(st)s'%p)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach(); print('fired functions:',len(order))
