import socket, threading, frida, time, subprocess, os, random

T = os.environ.get('TEMP','.')
def mk(freqs):  # freqs: dict sym->count
    b=b''
    for s,c in freqs.items(): b+=bytes([s])*c
    return b
probes = [
    bytes([0]),                                   # 0: single symbol 0
    bytes([255]),                                 # 1: single symbol 255
    mk({0:1,1:1,2:2,3:3,4:5,5:8,6:13,7:21,8:34,9:55}),  # 2: deep tree, lengths up to ~9
    mk({10:1,11:1,12:1,13:1,14:1,15:1,16:1,17:1}),      # 3: 8 equal -> all len3
    mk({100:1,101:2,102:4,103:8,104:16}),               # 4: lengths 1,2,3,4,4
]
paths = []
for i,p in enumerate(probes):
    fn = os.path.join(T, 'qr%d.bin'%i); open(fn,'wb').write(p); paths.append(fn)
print('probes', [len(p) for p in probes])

resps = [open('resps/r%d.bin' % k, 'rb').read() for k in range(6)]
raw = bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe', 'e', '-pflare', '-so', '5-catthief.7z', 'catthief/catthief.exe'], capture_output=True, cwd='.').stdout)
i = raw.find(b'This program cannot'); raw[i] = ord('t')
tmp = os.path.join(T, 'upd_%d.exe' % random.randint(10000, 99999)); open(tmp, 'wb').write(raw)

reqno = [0]; bodies = []
def serve():
    s = socket.socket(); s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('127.0.0.1', 8080)); s.listen(16)
    while True:
        c, _ = s.accept(); threading.Thread(target=h, args=(c,), daemon=True).start()
def h(c):
    c.settimeout(60)
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
        bodies.append(body); print('[c2] req#%d bodylen=%d' % (n, len(body)), flush=True)
        open('probe_out/q%d.bin'%n,'wb').write(body)
        hdr = b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        r = resps[n] if n < len(resps) else b''
        c.sendall(hdr + r); c.close()
    except Exception as e:
        print('err', e, flush=True)
    finally:
        try: c.close()
        except: pass
os.makedirs('probe_out', exist_ok=True)
threading.Thread(target=serve, daemon=True).start(); time.sleep(0.3)
js = r"""
var PATHS = %s;
var cnt = 0;
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
['kernel32.dll','kernelbase.dll'].forEach(function(dll){ try{ Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){ try{ var p=a[0].readUtf16String(); if(p&&p.indexOf('flare')>=0&&p.indexOf('.jpg')>=0){ var t=PATHS[cnt %% PATHS.length]; cnt++; a[0].writeUtf16String(t); send({redir:p, to:t}); } }catch(e){} }}); }catch(e){} });
send({log:'ok'});
""" % (str(paths).replace("\\","\\\\"))
def on_msg(m, d):
    if m['type'] == 'send':
        p = m['payload']
        if 'log' in p: print('[f] ok', flush=True)
        elif 'redir' in p: print('[REDIR]', p['redir'], '->', p['to'], flush=True)
dev = frida.get_local_device(); pid = dev.spawn([tmp]); sess = dev.attach(pid)
scr = sess.create_script(js); scr.on('message', on_msg); scr.load(); dev.resume(pid)
time.sleep(420)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
print('req count', len(bodies), 'sizes', [len(b) for b in bodies], flush=True)
