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
var mod=Process.enumerateModules()[0]; var base=mod.base, size=mod.size;
var following=false, calls={};
['kernel32.dll','kernelbase.dll'].forEach(function(dll){try{Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){try{var p=a[0].readUtf16String();if(p&&p.indexOf('flare')>=0){a[0].writeUtf16String(NEW); if(!following){following=true; Stalker.follow(this.threadId,{events:{call:true},onCallSummary:function(sum){for(var ad in sum){var pp=ptr(ad); if(pp.compare(base)>=0&&pp.compare(base.add(size))<0){var o=pp.sub(base).toInt32(); calls[o]=(calls[o]||0)+sum[ad];}}}});}}}catch(e){}}});}catch(e){}});
var dumped=false;
['send','WSASend'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){ if(following&&!dumped&&this.context.r8.toInt32()>60000){ dumped=true; Stalker.flush(); Stalker.unfollow(); var arr=[];for(var o in calls)arr.push([parseInt(o),calls[o]]); arr.sort(function(a,b){return b[1]-a[1];}); send({hot:arr.slice(0,25)}); } }});}catch(e){}});
send({log:'ok'});
"""
def on_msg(m,d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[f] ok',flush=True)
        elif 'hot' in p:
            print('[HOT functions during exfil]',flush=True)
            for o,c in p['hot']: print('  %#x  x%d'%(0x140000000+o,c),flush=True)
dev=frida.get_local_device(); pid=dev.spawn([tmp]); sess=dev.attach(pid); scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(20)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
