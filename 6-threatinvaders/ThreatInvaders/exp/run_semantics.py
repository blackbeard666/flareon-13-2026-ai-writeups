import http.server, socketserver, threading, json, subprocess, time, os, shutil
import frida
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
DOTNET="C:/Users/cavila/Desktop/tools/dotnet/dotnet.exe"; EP=os.path.join(HERE,"..","csharp","eptrace","bin","eptrace.dll")
b=[0]; jsons=[]
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
        if 'telemetry' in self.path:
            b[0]+=1
            try: jsons.append(json.loads(body))
            except: pass
        self._s({"received":True})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H);srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start();time.sleep(0.3)
shutil.copy(os.path.join(HERE,"updater_test.exe"), os.path.join(GAMEDIR,"updater.exe"))
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True,"headlessUpdate":True}))
env=dict(os.environ);env["DOTNET_ROLL_FORWARD"]="LatestMajor"
p=subprocess.Popen([os.path.join(GAMEDIR,"ThreatInvaders.exe")],cwd=GAMEDIR,env=env)
print("spawned",p.pid,flush=True)
for _ in range(20):
    time.sleep(1)
    if b[0]>=2: break
session=frida.attach(p.pid)
s=session.create_script(open(os.path.join(HERE,"ks2.js")).read())
res={}
def onmsg(m,d):
    if m.get('type')=='send': res[m['payload']['t']]=m['payload'].get('hex')
    elif m.get('type')=='error': print("ERR",m.get('description'))
s.on('message',onmsg); s.load()
time.sleep(2)
print("tableA",res.get('tableA'),flush=True)
print("tableB",res.get('tableB'),flush=True)
for j in jsons[:4]:
    print("beacon req=%s ses=%s fb=%s"%(j.get('request_id'),j.get('session_id'),j.get('feedback_length')),flush=True)
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
srv.shutdown()
