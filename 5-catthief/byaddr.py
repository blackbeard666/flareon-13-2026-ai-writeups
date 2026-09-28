import socket, threading, frida, time, subprocess, os, random, json
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1); s.bind(('127.0.0.1',8080)); s.listen(16)
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
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
function hx(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2);return s;}catch(e){return null;}}
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var base=Process.enumerateModules()[0].base;
var seq=0;
Interceptor.attach(base.add(0x75e8b),{onEnter:function(a){
  [this.context.rcx,this.context.rdx].forEach(function(p){
    if(p.compare(ptr(0x10000))<0)return;
    var v=hx(p,264); if(!v)return;
    // only report buffers that look like plaintext (READY) or ciphertext (e728)
    if(v.indexOf('52454144')==0 || v.indexOf('e728a715')==0){ send({seq:seq++, addr:p.toString(), v:v}); }
  });
}});
send({log:'ok'});
"""
rows=[]
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[*]',p['log'],flush=True)
        elif 'addr' in p: rows.append(p); print('[%d] addr=%s %s'%(p['seq'],p['addr'],p['v'][:24]),flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(12)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
json.dump(rows,open('addr_rows.json','w'))
# find address with both plaintext and ciphertext
from collections import defaultdict
byaddr=defaultdict(list)
for r in rows: byaddr[r['addr']].append(r['v'])
for a,vs in byaddr.items():
    has_pt=any(v.startswith('52454144') for v in vs); has_ct=any(v.startswith('e728a715') for v in vs)
    if has_pt: print('ADDR',a,'has_pt',has_pt,'has_ct',has_ct,'count',len(vs))
print('rows:',len(rows))
