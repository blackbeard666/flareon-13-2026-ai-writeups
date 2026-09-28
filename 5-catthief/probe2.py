import socket, threading, frida, time, subprocess, os, random

T = os.environ.get('TEMP','.')
# 5 tiny known probes, one per successive file-open
probes = [
    b'\x41',                       # 0: single byte
    b'\x41\x41\x41\x41',           # 1: 4x same
    b'\x41\x42',                   # 2: two distinct
    b'\x00\x01\x02\x03',           # 3: four distinct increasing
    b'AAAABBC',                    # 4: 4A 2B 1C
]
paths = []
for i,p in enumerate(probes):
    fn = os.path.join(T, 'pr%d.bin'%i); open(fn,'wb').write(p); paths.append(fn)
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
        open('probe_out/tiny%d.bin'%n,'wb').write(body)
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
