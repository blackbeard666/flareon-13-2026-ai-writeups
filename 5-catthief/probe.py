import socket, threading, frida, time, subprocess, os, random

# Probe file: 256 x 0x00 then 44 x 0x01  -> only symbols 0x00,0x01 present. Reveals table+huffman format.
PROBE = os.path.join(os.environ.get('TEMP','.'), 'probe_input.bin')
open(PROBE,'wb').write(b'\x00'*256 + b'\x01'*44)
print('probe file', PROBE, 'size', os.path.getsize(PROBE))

resps = [open('resps/r%d.bin' % k, 'rb').read() for k in range(6)]

raw = bytearray(subprocess.run(['C:/Program Files/7-Zip/7z.exe', 'e', '-pflare', '-so', '5-catthief.7z', 'catthief/catthief.exe'], capture_output=True, cwd='.').stdout)
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
    c.settimeout(30)
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
        hdr = b'HTTP/1.0 200 OK\r\nServer: BaseHTTP/0.6 Python/3.8.10\r\n\r\n'
        r = resps[n] if n < len(resps) else b''
        c.sendall(hdr + r); c.close()
    except Exception as e:
        print('err', e, flush=True)
    finally:
        try: c.close()
        except: pass
threading.Thread(target=serve, daemon=True).start(); time.sleep(0.3)
js = r"""
['connect','WSAConnect'].forEach(function(fn){try{Interceptor.attach(Module.getExportByName('ws2_32.dll',fn),{onEnter:function(a){if(a[1].readU16()==2)a[1].add(4).writeU32(0x0100007f);}});}catch(e){}});
var NEW = 'C:\\Users\\cavila\\AppData\\Local\\Temp\\probe_input.bin';
['kernel32.dll','kernelbase.dll'].forEach(function(dll){ try{ Interceptor.attach(Module.getExportByName(dll,'CreateFileW'),{onEnter:function(a){ try{ var p=a[0].readUtf16String(); if(p&&p.indexOf('flare')>=0&&p.indexOf('.jpg')>=0){ a[0].writeUtf16String(NEW); send({redir:p}); } }catch(e){} }}); }catch(e){} });
send({log:'ok'});
"""
def on_msg(m, d):
    if m['type'] == 'send':
        p = m['payload']
        if 'log' in p: print('[f] ok', flush=True)
        elif 'redir' in p: print('[REDIR]', p['redir'], '-> probe', flush=True)
dev = frida.get_local_device(); pid = dev.spawn([tmp]); sess = dev.attach(pid)
scr = sess.create_script(js); scr.on('message', on_msg); scr.load(); dev.resume(pid)
time.sleep(90)
try: dev.kill(pid)
except: pass
sess.detach()
try: os.remove(tmp)
except: pass
os.makedirs('probe_out', exist_ok=True)
for _i,_b in enumerate(bodies): open('probe_out/pb%d.bin'%_i,'wb').write(_b)
print('req count', len(bodies), 'sizes', [len(b) for b in bodies], flush=True)
