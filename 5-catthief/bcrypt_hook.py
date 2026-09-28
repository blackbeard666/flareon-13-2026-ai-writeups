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
            if not x: break
            d+=x
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except: pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
EXE=r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return 'x:'+e;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
function tryhook(dll,fn){try{return Module.getExportByName(dll,fn);}catch(e){return null;}}
// BCryptGenerateSymmetricKey(hAlg, phKey, pbKeyObject, cbKeyObject, pbSecret, cbSecret, flags)
[['bcrypt.dll','BCryptGenerateSymmetricKey'],['bcryptprimitives.dll','BCryptGenerateSymmetricKey']].forEach(function(x){
  var p=tryhook(x[0],x[1]); if(!p)return;
  Interceptor.attach(p,{onEnter:function(a){
    var pbSecret=this.context.rsp.add(0x28).readPointer();
    var cbSecret=this.context.rsp.add(0x30).readPointer().toInt32();
    send({gk:x[0],cb:cbSecret,secret:hx(pbSecret,cbSecret>0&&cbSecret<=64?cbSecret:32)});
  }});
});
// BCryptEncrypt(hKey, pbInput, cbInput, pPaddingInfo, pbIV, cbIV, pbOutput, cbOutput, pcbResult, flags)
[['bcrypt.dll','BCryptEncrypt'],['bcryptprimitives.dll','BCryptEncrypt']].forEach(function(x){
  var p=tryhook(x[0],x[1]); if(!p)return;
  Interceptor.attach(p,{onEnter:function(a){
    var pbInput=this.context.rdx, cbInput=this.context.r8.toInt32(), pad=this.context.r9;
    var pbIV=this.context.rsp.add(0x28).readPointer();
    var cbIV=this.context.rsp.add(0x30).readPointer().toInt32();
    var info={enc:x[0],cbInput:cbInput,iv:hx(pbIV,cbIV>0&&cbIV<64?cbIV:12)};
    // GCM padding info: cbSize(4),dwInfoVersion(4),pbNonce(8),cbNonce(4)...
    try{ var pbNonce=pad.add(8).readPointer(); var cbNonce=pad.add(16).readU32(); info.nonce=hx(pbNonce,cbNonce); info.cbNonce=cbNonce; }catch(e){info.paderr=''+e;}
    info.pt = hx(pbInput, cbInput>0&&cbInput<48?cbInput:32);
    send(info);
  }});
});
send({log:'bcrypt hooks set'});
"""
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'gk' in p: print('[KEY] %(gk)s cbSecret=%(cb)s SECRET=%(secret)s'%p,flush=True)
        elif 'enc' in p: print('[ENC] cbInput=%(cbInput)s cbNonce=%(cbNonce)s NONCE=%(nonce)s\n      IV=%(iv)s\n      PT=%(pt)s'%p,flush=True)
    else: print('[err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach(); print('done')
