import socket, threading, frida, time, os
BODY_LOG=[]
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    s.bind(('127.0.0.1',8080)); s.listen(16)
    print('[c2] up',flush=True)
    while True:
        c,_=s.accept(); threading.Thread(target=handle,args=(c,),daemon=True).start()
def handle(c):
    c.settimeout(4); data=b''
    try:
        while b'\r\n\r\n' not in data: 
            ch=c.recv(65536)
            if not ch: break
            data+=ch
        # read declared body
        import re
        m=re.search(rb'Content-Length: (\d+)',data)
        if m:
            need=int(m.group(1)); bstart=data.find(b'\r\n\r\n')+4
            body=data[bstart:]
            while len(body)<need:
                ch=c.recv(65536)
                if not ch: break
                body+=ch
            BODY_LOG.append(body)
            print('[c2] got body len',len(body),'head',body[:16].hex(),flush=True)
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except Exception as e:
        print('[c2] err',e,flush=True)
    finally:
        try: c.close()
        except: pass
threading.Thread(target=serve,daemon=True).start()
time.sleep(0.5)

EXE=r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js=r"""
function hex(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return 'ERR';}}
var base=Module.getBaseAddress('catthief.exe');
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2){a[1].add(4).writeU32(0x0100007f);}}});}catch(e){}});
// dump send buffers
['send','WSASend'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){
  if(fn=='send'){var buf=a[1],len=this.context.r8.toInt32();if(len>0&&len<64)send({snd:hex(buf,len),l:len});}
}});}catch(e){}});
[0xa5ca0,0xa196d,0xa242d].forEach(function(off){var f=base.add(off);Interceptor.attach(f,{onEnter:function(a){
  send({cc:off.toString(16),r9:hex(this.context.r9,32),rcx:hex(this.context.rcx,16),rdx:hex(this.context.rdx,16),r8:this.context.r8.toString(),st:hex(this.context.rsp.add(0x28).readPointer(),16)});
}});});
send({info:'ready'});
"""
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'info' in p: print('[f] hooks ready',flush=True)
        elif 'cc' in p: print('[f] cryptofn @%(cc)s r8=%(r8)s r9=%(r9)s'%p,'st=',p['st'],flush=True)
        elif 'snd' in p: print('[f] send len=%(l)s %(snd)s'%p,flush=True)
    else: print('[f-err]',m.get('stack') or m,flush=True)
dev=frida.get_local_device()
pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach()
# compare first body to pcap
if BODY_LOG:
    pcap=open('streams/body_49680.bin','rb').read()
    b=BODY_LOG[0]
    n=min(len(b),len(pcap),32)
    print('MYSEND head',b[:32].hex())
    print('PCAP   head',pcap[:32].hex())
    print('match first %d? %s'%(n, b[:n]==pcap[:n]))
print('done, bodies captured:',len(BODY_LOG))
