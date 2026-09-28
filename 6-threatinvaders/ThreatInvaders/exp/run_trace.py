import http.server, socketserver, threading, json, subprocess, time, os, shutil
import frida
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
DOTNET="C:/Users/cavila/Desktop/tools/dotnet/dotnet.exe"; EP=os.path.join(HERE,"..","csharp","eptrace","bin","eptrace.dll")
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
        n=int(self.headers.get('Content-Length',0));body=self.rfile.read(n)
        if 'telemetry' in self.path: b[0]+=1
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
subprocess.run([DOTNET,EP,str(p.pid)],capture_output=True,text=True,timeout=120,env=env)
sf=bd=None
for line in open(os.path.join(HERE,"method_map.txt")):
    pr=line.strip().split("\t")
    if len(pr)==3:
        if pr[2].endswith("TelemetryReporter.SetFeedback"): sf=hex(int(pr[0],16))
        if pr[2].endswith("TelemetryReporter.BuildDocument"): bd=hex(int(pr[0],16))
print("SetFeedback",sf,"BuildDocument",bd,flush=True)
session=frida.attach(p.pid)
scr=open(os.path.join(HERE,"hook_trace.js")).read().replace("SF_ADDR",sf or "0").replace("BD_ADDR",bd or "0")
s=session.create_script(scr)
seen=[0]
def onmsg(m,d):
    if m.get('type')=='send':
        pl=m['payload']
        if pl.get('t')=='SetFeedback':
            seen[0]+=1
            if seen[0]<=6:
                print("SetFeedback textLen=%s text=%r"%(pl.get('textLen'),pl.get('text')),flush=True)
                print("  backtrace:",pl.get('bt'),flush=True)
        elif pl.get('t')=='BuildDocument':
            print("BuildDocument feedbackLen=%s head=%s"%(pl.get('feedbackLen'),pl.get('feedbackHead')),flush=True)
        else: print("FRIDA",pl,flush=True)
    elif m.get('type')=='error': print("FRIDA-ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load()
print("hooks installed",flush=True)
time.sleep(40)
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
srv.shutdown()
