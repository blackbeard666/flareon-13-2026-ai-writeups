import socket, threading, frida, time, subprocess, os, random

KS = bytes.fromhex('c728a715708a98840dae290d0d983abe6cad44ae901586b9ae1a12deb8f35d061266a2d8c0d8fd')
MYPATH = b'C:\\Users\\cavila\\Desktop\\important.jpg'
cmd = bytes(MYPATH[i] ^ KS[i] for i in range(len(MYPATH)))
print('crafted cmd len', len(cmd))

raw = bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe', 'e', '-pflare', '-so', '5-catthief.7z', 'catthief/catthief.exe'], capture_output=True).stdout)
i = raw.find(b'This program cannot'); raw[i] = ord('t')
tmp = os.path.join(os.environ.get('TEMP', '.'), 'upd_%d.exe' % random.randint(10000, 99999))
open(tmp, 'wb').write(raw)

reqno = [0]; bodies = []
def serve():
    s = socket.socket(); s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('127.0.0.1', 8080)); s.listen(16)
    while True:
        c, _ = s.accept(); threading.Thread(target=h, args=(c,), daemon=True).start()
def h(c):
    c.settimeout(15)
    try:
        d = b''
        while b'\r\n\r\n' not in d:
            x = c.recv(65536)
            if not x: break
            d += x
        import re
        m = re.search(rb'Content-Length: (\d+)', d); bs = d.find(b'\r\n\r\n') + 4; body = d[bs:]
        if m:
            need = int(m.group(1))
            while len(body) < need:
                x = c.recv(65536)
                if not x: break
                body += x
        n = reqno[0]; reqno[0] += 1
        bodies.append(body); print('[c2] req#%d bodylen=%d head=%s' % (n, len(body), body[:12].hex()), flush=True)
        hdr = b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        if n == 0:
            c.sendall(hdr + cmd)
        else:
            c.sendall(hdr)
        c.close()
    except Exception as e:
        print('c2 err', e, flush=True)
    finally:
        try: c.close()
        except: pass
threading.Thread(target=serve, daemon=True).start(); time.sleep(0.3)

js = r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
try{Interceptor.attach(Module.getExportByName('kernel32.dll','CreateFileW'),{onEnter:function(a){try{var p=a[0].readUtf16String();if(p&&p.indexOf('.jpg')>=0)send({file:p});}catch(e){}}});}catch(e){}
send({log:'ok'});
"""
def on_msg(m, d):
    if m['type']=='send':
        p=m['payload']
        if 'log' in p: print('[f]',p['log'],flush=True)
        elif 'file' in p: print('[FILE]',p['file'],flush=True)
dev = frida.get_local_device(); pid = dev.spawn([tmp]); sess = dev.attach(pid)
scr = sess.create_script(js); scr.on('message', on_msg); scr.load(); dev.resume(pid)
time.sleep(30)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
if len(bodies) > 1:
    exfil = bodies[1]
    open('KS_full.bin', 'wb').write(exfil)
    print('exfil(zerofile) len', len(exfil), 'head', exfil[:16].hex())
print('total requests:', len(bodies))
