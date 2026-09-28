import http.server, socketserver, threading, json, base64, subprocess, time, os
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
DOTNET="C:/Users/cavila/Desktop/tools/dotnet/dotnet.exe"
JIT=os.path.join(HERE,"..","csharp","jitdump","bin","jitdump.dll")
DAC=os.path.join(HERE,"dac","mscordaccore.dll")
beacons=[0]
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        b=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.end_headers();self.wfile.write(b)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path: self._s({"status":"ok","entries":1,"time":"2026-09-28T00:00:00Z"})
        elif 'highscores' in self.path: self._s({"entries":[],"total":0})
        elif 'version' in self.path: self._s({"latest":"1.0.0.0","message":""})
        else: self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0)); self.rfile.read(n)
        if 'telemetry' in self.path: beacons[0]+=1
        self._s({"received":True,"connects":beacons[0],"reward_now":False})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H); srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start(); time.sleep(0.3)
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True,"headlessUpdate":True}))
EXE=os.path.join(GAMEDIR,"ThreatInvaders.exe")
p=subprocess.Popen([EXE],cwd=GAMEDIR); print("spawned",p.pid,flush=True)
# wait for first telemetry beacon (BuildDocument JIT'd)
for _ in range(30):
    time.sleep(1)
    if beacons[0]>=1: break
print("beacons before dump:",beacons[0],flush=True)
time.sleep(2)
os.environ["DOTNET_ROLL_FORWARD"]="LatestMajor"
r=subprocess.run([DOTNET, JIT, str(p.pid), DAC], capture_output=True, text=True, timeout=180)
print("=== jitdump stdout ==="); print(r.stdout)
print("=== jitdump stderr ==="); print(r.stderr[:2000])
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
cfg=os.path.join(GAMEDIR,"config.json")
if os.path.exists(cfg): os.remove(cfg)
srv.shutdown()
