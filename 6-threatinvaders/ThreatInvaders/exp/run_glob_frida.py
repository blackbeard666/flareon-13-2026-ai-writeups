import http.server, socketserver, threading, json, subprocess, time, os, shutil
import frida
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
b=[0]
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        x=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.end_headers();self.wfile.write(x)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path:self._s({"status":"ok"})
        elif 'highscores' in self.path:self._s({"entries":[],"total":0})
        elif 'version' in self.path:self._s({"latest":"9.9.9.9","message":"u"})
        else:self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0));self.rfile.read(n)
        if 'telemetry' in self.path:b[0]+=1
        self._s({"received":True})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H);srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start();time.sleep(0.3)
shutil.copy(os.path.join(HERE,"updater_test.exe"), os.path.join(GAMEDIR,"updater.exe"))
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True,"headlessUpdate":True}))
env=dict(os.environ);env["DOTNET_ROLL_FORWARD"]="LatestMajor"
p=subprocess.Popen([os.path.join(GAMEDIR,"ThreatInvaders.exe")],cwd=GAMEDIR,env=env)
print("spawned",p.pid,flush=True)
for _ in range(25):
    time.sleep(1)
    if b[0]>=1: break
time.sleep(3)
session=frida.attach(p.pid)
JS='''
var base=Module.findBaseAddress("ThreatInvaders.exe");
function rd(rva,n){ return Array.from(new Uint8Array(base.add(rva).readByteArray(n))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join(''); }
send({t:"base",base:base.toString()});
send({t:"A",hex:rd(0x7FF800,16)});
send({t:"B",hex:rd(0x7FFA30,16)});
send({t:"gate",hex:rd(0x7FD5FE,4)});
send({t:"len",hex:rd(0x7FE5E8,8)});
send({t:"ptr",hex:rd(0x7FE5B0,8)});
send({t:"buf",hex:rd(0x7FE5F0,0x1000)});
send({t:"Awide",hex:rd(0x7FF780,0x140)});
send({t:"Bwide",hex:rd(0x7FF9B0,0x140)});
send({t:"DONE"});
'''
s=session.create_script(JS)
res={}
def onmsg(m,d):
    if m.get('type')=='send':
        pl=m['payload']; res[pl['t']]=pl.get('hex'); 
        if pl['t'] in ('base','DONE'): print(pl,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load()
time.sleep(3)
for k in ('A','B','gate','len','ptr'): print(k,res.get(k),flush=True)
if res.get('buf'):
    buf=bytes.fromhex(res['buf']); open(os.path.join(HERE,"buf_7FE5F0.bin"),"wb").write(buf)
    nz=sum(1 for c in buf if c); print("buf nonzero",nz,"first96",buf[:96].hex(),flush=True)
    print("buf ascii:","".join(chr(c) if 32<=c<127 else '.' for c in buf[:200]),flush=True)
if res.get('A') and res.get('B'):
    A=bytes.fromhex(res['A']); B=bytes.fromhex(res['B'])
    out=bytes(A[15-i]^B[i] for i in range(16))
    print("A[15-i]^B[i]:",out.hex(),"| ascii","".join(chr(c) if 32<=c<127 else '.' for c in out),flush=True)
for k in ('Awide','Bwide'):
    if res.get(k): open(os.path.join(HERE,k+".bin"),"wb").write(bytes.fromhex(res[k]))
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
srv.shutdown()
