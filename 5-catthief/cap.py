import socket, threading, frida, time
BODIES=[]
def serve():
    s=socket.socket(); s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
    s.bind(('127.0.0.1',8080)); s.listen(16); print('[c2] up',flush=True)
    while True:
        c,_=s.accept(); threading.Thread(target=h,args=(c,),daemon=True).start()
def h(c):
    c.settimeout(5); data=b''
    try:
        import re
        while b'\r\n\r\n' not in data:
            ch=c.recv(65536)
            if not ch: break
            data+=ch
        m=re.search(rb'Content-Length: (\d+)',data); bstart=data.find(b'\r\n\r\n')+4
        body=data[bstart:]
        if m:
            need=int(m.group(1))
            while len(body)<need:
                ch=c.recv(65536)
                if not ch: break
                body+=ch
        BODIES.append(body); print('[c2] body len',len(body),'head',body[:24].hex(),flush=True)
        c.sendall(b'HTTP/1.0 200 OK\r\nContent-Length: 32\r\n\r\n'+b'\x00'*32)
    except Exception as e: print('[c2]err',e,flush=True)
    finally:
        try:c.close()
        except:pass
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.3)
EXE=r"C:\Users\cavila\Desktop\ctf\flareon13-2026\5-catthief\catthief\catthief.exe"
js=r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
send({log:'ready'});
"""
def on_msg(m,d):
    if m['type']=='send': print('[f]',m['payload'],flush=True)
    else: print('[err]',m,flush=True)
dev=frida.get_local_device(); pid=dev.spawn([EXE]); sess=dev.attach(pid)
scr=sess.create_script(js); scr.on('message',on_msg); scr.load(); dev.resume(pid)
time.sleep(15)
try: dev.kill(pid)
except: pass
sess.detach()
if BODIES:
    pcap=open('streams/body_49680.bin','rb').read()
    b=BODIES[0]
    print('MYSEND len',len(b),'head',b[:32].hex())
    print('PCAP   len',len(pcap),'head',pcap[:32].hex())
    n=min(len(b),len(pcap))
    same=sum(1 for i in range(n) if b[i]==pcap[i])
    print('common',n,'equal',same,'(%.1f%%)'%(100*same/n))
print('bodies:',len(BODIES))
