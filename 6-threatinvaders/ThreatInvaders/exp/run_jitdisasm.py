import http.server, socketserver, threading, json, subprocess, time, os
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
b=[0]
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        x=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.end_headers();self.wfile.write(x)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path:self._s({"status":"ok","entries":0,"time":"t"})
        elif 'highscores' in self.path:self._s({"entries":[],"total":0})
        elif 'version' in self.path:self._s({"latest":"1.0.0.0","message":""})
        else:self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0));self.rfile.read(n)
        if 'telemetry' in self.path:b[0]+=1
        self._s({"received":True,"connects":b[0]})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H);srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start();time.sleep(0.3)
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True}))
env=dict(os.environ)
env["DOTNET_JitDisasm"]="BuildDocument EncodeFeedbackBuffer"
env["DOTNET_JitStdOutFile"]=os.path.join(HERE,"jitdisasm.txt")
env["DOTNET_TieredCompilation"]="0"
env["DOTNET_JitDisasmDiffable"]="1"
open(env["DOTNET_JitStdOutFile"],"w").close()
p=subprocess.Popen([os.path.join(GAMEDIR,"ThreatInvaders.exe")],cwd=GAMEDIR,env=env)
print("spawned",p.pid,flush=True)
for _ in range(20):
    time.sleep(1)
    if b[0]>=1: break
print("beacons",b[0],flush=True)
time.sleep(3)
try:p.terminate()
except:pass
time.sleep(1)
try:p.kill()
except:pass
cfg=os.path.join(GAMEDIR,"config.json")
if os.path.exists(cfg):os.remove(cfg)
srv.shutdown()
sz=os.path.getsize(env["DOTNET_JitStdOutFile"])
print("jitdisasm.txt size:",sz)
