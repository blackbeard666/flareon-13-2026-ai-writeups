import socket, threading, frida, time, subprocess, os, random
resps=[open('resps/r%d.bin'%k,'rb').read() for k in range(6)]
raw=bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe','e','-pflare','-so','5-catthief.7z','catthief/catthief.exe'],capture_output=True).stdout)
i=raw.find(b'This program cannot'); raw[i]=ord('t')
tmp=os.path.join(os.environ.get('TEMP','.'),'upd_%d.exe'%random.randint(10000,99999)); open(tmp,'wb').write(raw)
reqno=[0]
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1); s.bind(('127.0.0.1',8080)); s.listen(16)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(30)
    try:
        d=b''
        while b'\r\n\r\n' not in d:
            x=c.recv(65536)
            if not x:break
            d+=x
        n=reqno[0]; reqno[0]+=1; print('[c2] req#%d'%n,flush=True)
        hdr=b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        c.sendall(hdr+(resps[n] if n<len(resps) else b'')); c.close()
    except Exception as e: print('err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var NEW='C:\Users\cavila\r.jpg';
['kernel32.dll','kernelbase.dll'].forEach(function(dll){try{Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){try{var p=a[0].readUtf16String();if(p&&p.indexOf('flare')>=0&&p.indexOf('.jpg')>=0){a[0].writeUtf16String(NEW);}}catch(e){}}});}catch(e){}});
var done=false;
function scanzlib(){ if(done)return;
  Process.enumerateRanges({protection:'rw-',coalesce:true}).forEach(function(r){
    if(done||r.size<3000000||r.size>7000000) return;
    try{ var h=new Uint8Array(r.base.readByteArray(2));
      // scan first 4KB for a zlib header 78 01 / 78 9c / 78 da
      var ms=Memory.scanSync(r.base, Math.min(r.size,64), '78 01');
      var m2=Memory.scanSync(r.base, Math.min(r.size,64), '78 9c');
      var hit=ms.concat(m2);
      if(hit.length){ done=true; send({found:hit[0].toString(),rsize:r.size}, hit[0].readByteArray(Math.min(r.size,3300000))); }
    }catch(e){}
  });
}
['send','WSASend'].forEach(function(fn){ try{ Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){ if(this.context.r8.toInt32()>60000) scanzlib(); }}); }catch(e){} });
send({log:'ok'});
"""
msg=None
def on_msg(m,d):
    global msg
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[f] ok',flush=True)
        elif 'found' in p: print('[f] zlib buf at',p['found'],'rsize',p['rsize'],'datalen',len(d) if d else 0,flush=True); msg=bytes(d) if d else None
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(30)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if msg:
    open('compressed_b1.bin','wb').write(msg)
    b1=open('exfil_bodies/b1.bin','rb').read()
    ks40=bytes.fromhex('c728a715708a98840dae290d0d983abe6cad44ae901586b9ae1a12deb8f35d061266a2d8c0d8fd')
    # message_b1 = header(40) + compressed. KS[40:]=b1[40:]^compressed. Try offsets for header len
    import zlib
    pc=open('streams/body_49681.bin','rb').read()
    for HL in range(36,48):
        n=min(len(b1)-HL,len(msg))
        ks=bytearray(len(b1)); ks[:40]=ks40
        for i in range(n): ks[HL+i]=b1[HL+i]^msg[i]
        m=min(len(pc),len(ks)); dec=bytes(pc[i]^ks[i] for i in range(m))
        for wb in (15,-15,31):
            try:
                d=zlib.decompressobj(wb).decompress(dec[HL:HL+200000])
                if d[:3]==b'\xff\xd8\xff' or len(d)>1000:
                    print('HL',HL,'wb',wb,'JPGorDATA',d[:8].hex(),flush=True)
                    open('KS_real.bin','wb').write(bytes(ks)); 
                    raise SystemExit
            except SystemExit: raise
            except: pass
    print('reconstruct failed, saved compressed_b1',len(msg),flush=True)
else: print('no zlib buffer found',flush=True)
