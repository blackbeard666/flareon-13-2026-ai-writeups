import socket, threading, frida, time
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    s.bind(('127.0.0.1',8080)); s.listen(16); print('[c2] up',flush=True)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(4)
    try:
        d=c.recv(65536); print('[c2] recv',len(d),d[:40],flush=True)
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except Exception as e: print('[c2]err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
EXE=r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js=r"""
var seen={};
function once(msg){ if(seen[msg])return; seen[msg]=1; send({log:msg}); }
function w(name){ try{ return Module.getExportByName(null,name);}catch(e){return null;} }
function hookStr(dll,fn,argidx,wide){ try{var p=Module.getExportByName(dll,fn); Interceptor.attach(p,{onEnter:function(a){ try{var s=wide?a[argidx].readUtf16String():a[argidx].readAnsiString(); send({api:fn,arg:s});}catch(e){}}});}catch(e){} }
hookStr('kernel32.dll','CreateFileW',0,true);
hookStr('kernel32.dll','CreateFileA',0,false);
hookStr('kernel32.dll','LoadLibraryW',0,true);
hookStr('kernel32.dll','GetProcAddress',1,false);
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){var sa=a[1];if(sa.readU16()==2){var port=sa.add(2).readU16(); send({api:fn,port:((port&0xff)<<8)|(port>>8)}); sa.add(4).writeU32(0x0100007f);}}});}catch(e){}});
['send','recv','WSASend','WSARecv'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){send({api:fn});}});}catch(e){}});
try{Interceptor.attach(Module.getExportByName('bcrypt.dll','BCryptGenRandom'),{onEnter:function(a){send({api:'BCryptGenRandom',len:this.context.r8.toInt32()});}});}catch(e){}
try{Interceptor.attach(Module.getExportByName('bcryptprimitives.dll','ProcessPrng'),{onEnter:function(a){send({api:'ProcessPrng'});}});}catch(e){}
send({log:'traced'});
"""
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[T]',p['log'],flush=True)
        elif 'api' in p: print('   >',p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach(); print('done')
