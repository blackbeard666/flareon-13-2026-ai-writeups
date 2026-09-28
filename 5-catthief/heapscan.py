import socket, threading, frida, time, subprocess, os, random, json
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
RESP=open('streams/body_49680.bin','rb').read()
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
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n'%len(RESP)+RESP)
    except:pass
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
// after a delay, scan memory for 'READY\0\0\0'
rpc.exports={scan:function(){
  var pat='52 45 41 44 59 00 00 00';
  var res=[];
  var ranges=Process.enumerateRanges({protection:'rw-',coalesce:true});
  ranges.forEach(function(r){
    try{ var found=Memory.scanSync(r.base,r.size,pat);
      found.forEach(function(m){ try{var b=new Uint8Array(m.address.readByteArray(232)); var s='';for(var i=0;i<b.length;i++)s+=('0'+b[i].toString(16)).slice(-2); res.push(s);}catch(e){} });
    }catch(e){}
  });
  return res;
}};
"""
def runonce():
    scr_res=[]
    dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.load(); dev.resume(pid)
    time.sleep(8)
    try: r=scr.exports_sync.scan()
    except Exception as e: r=[]; print('scan err',e)
    try: dev.kill(pid)
    except: pass
    sess.detach(); return set(r)
a=runonce(); b=runonce()
try: os.remove(tmp)
except: pass
common=a&b
print('run1',len(a),'run2',len(b),'CONSTANT READY buffers:',len(common))
c1=RESP
for v in common:
    pt=bytes.fromhex(v); ks=bytes(pt[i]^c1[i] for i in range(len(pt)))
    # validate: does this KS decrypt big file header to match msg1 header region? just print
    print('PT:',pt[:64]); print('KS:',ks[:32].hex())
    open('KS_scan.bin','wb').write(ks)
