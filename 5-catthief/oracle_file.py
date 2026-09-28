import socket, threading, frida, time, subprocess, os, random, json
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
RESP=open('streams/body_49681.bin','rb').read()  # 3MB file ct
print('resp len',len(RESP))
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1); s.bind(('127.0.0.1',8080)); s.listen(16)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(10)
    try:
        d=b''
        while b'\r\n\r\n' not in d:
            x=c.recv(65536)
            if not x:break
            d+=x
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n'%len(RESP)+RESP)
    except Exception as e: print('c2 err',e)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
calls=[o for o,c in json.load(open('callset.json'))]
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Process.enumerateModules()[0].base; var ar=false;
Interceptor.attach(Module.getExportByName('ws2_32.dll','recv'),{onLeave:function(r){ar=true;}});
var OFFS=OFFP; var seen={};
function grab(p,len){ if(p.compare(ptr(0x10000))<0)return; try{ var head=new Uint8Array(p.readByteArray(4)); 
  // report large buffers that are printable-ish or gzip
  var k=p.toString(); if(seen[k])return; 
  // check first bytes for gzip 1f8b or readable
  if(head[0]==0x1f&&head[1]==0x8b){ seen[k]=1; send({gz:1,addr:k}); var big=p.readByteArray(Math.min(len,2000000)); send(big); }
}catch(e){} }
OFFS.forEach(function(off){ try{Interceptor.attach(base.add(off),{onEnter:function(a){ if(!ar)return; 
  grab(this.context.rcx,3200000); grab(this.context.rdx,3200000); grab(this.context.r8,3200000); }});}catch(e){} });
send({log:'ok'});
""".replace('OFFP',json.dumps(calls))
chunks=[]
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'gz' in p: print('[GZIP found] at',p['addr'],flush=True)
    if d: chunks.append(d); print('  got',len(d),'bytes',flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(15)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if chunks:
    open('decrypted_file.gz','wb').write(chunks[0])
    print('saved decrypted_file.gz',len(chunks[0]))
