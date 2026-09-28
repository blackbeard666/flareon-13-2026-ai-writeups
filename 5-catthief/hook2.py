import frida, time
EXE = r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js = r"""
function hex(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return 'ERR';}}
var base=Module.getBaseAddress('catthief.exe');
// redirect connect() to 127.0.0.1
['connect','WSAConnect'].forEach(function(fn){
  try{ var p=Module.getExportByName('ws2_32.dll',fn);
    Interceptor.attach(p,{onEnter:function(a){
      var sa=a[1];
      var fam=sa.readU16();
      if(fam==2){ // AF_INET
        var port=sa.add(2).readU16();
        sa.add(4).writeU32(0x0100007f); // 127.0.0.1 network order LE bytes 7f 00 00 01
        send({redir:fn,port:port});
      }
    }});
  }catch(e){send({err:'noexport '+fn});}
});
var chacha=base.add(0xa5ca0); var seen=0;
Interceptor.attach(chacha,{onEnter:function(a){
  seen++;
  var key=this.context.r9; var fifth=this.context.rsp.add(0x28).readPointer();
  send({n:seen,len:this.context.r8.toString(),key:hex(key,32),ctr:hex(fifth,16),inp:hex(this.context.rdx,32)});
}});
send({info:'ready'});
"""
hits=[]
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'info' in p: print('[*] hooks ready'); return
        if 'redir' in p: print('[*] redirected %(redir)s port=%(port)s -> 127.0.0.1'%p); return
        if 'err' in p: print('[!]',p['err']); return
        if 'n' in p:
            print('[+] CHACHA #%(n)s len=%(len)s'%p)
            print('    KEY =',p['key'])
            print('    CTR =',p['ctr'])
            print('    INP =',p['inp'])
            hits.append(p)
    else: print('[error]',m.get('stack') or m)
dev=frida.get_local_device()
pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(10)
try: dev.kill(pid)
except: pass
sess.detach()
print('total chacha calls:',len(hits))
