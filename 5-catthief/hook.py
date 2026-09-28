import frida, sys, time
EXE = r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js = r"""
function hex(ptr,n){ try{var b=new Uint8Array(ptr.readByteArray(n));var s='';for(var i=0;i<b.length;i++){s+=('0'+b[i].toString(16)).slice(-2);}return s;}catch(e){return 'ERR:'+e;} }
var base = Module.getBaseAddress('catthief.exe');
var chacha = base.add(0xa5ca0);
var seen=0;
Interceptor.attach(chacha, { onEnter: function(a){
  seen++;
  var key=this.context.r9;
  var fifth=this.context.rsp.add(0x28).readPointer();
  send({n:seen, len:this.context.r8.toString(),
        key: hex(key,32), ctr: hex(fifth,16),
        inp8: hex(this.context.rdx,16)});
}});
send({info:'hooked '+chacha});
"""
def on_msg(m,data):
    if m['type']=='send':
        p=m['payload']
        if 'info' in p: print('[*]',p['info']); return
        print('[+] chacha #%(n)s len=%(len)s'%p)
        print('    KEY  =',p['key'])
        print('    CTR16=',p['ctr'])
        print('    inp16=',p['inp8'])
    else:
        print('[error]',m.get('stack') or m)
dev=frida.get_local_device()
pid=dev.spawn([EXE])
sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load()
dev.resume(pid)
time.sleep(6)
try: dev.kill(pid)
except: pass
sess.detach()
print('done')
