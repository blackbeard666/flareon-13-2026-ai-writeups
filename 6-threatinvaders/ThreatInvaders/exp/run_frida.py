import http.server, socketserver, threading, json, base64, time, os, shutil, sys
import frida
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
b=[0]
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        x=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.end_headers();self.wfile.write(x)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path:self._s({"status":"ok","entries":0,"time":"t"})
        elif 'highscores' in self.path:self._s({"entries":[],"total":0})
        elif 'version' in self.path:self._s({"latest":"9.9.9.9","message":"update"})
        else:self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0));body=self.rfile.read(n)
        if 'telemetry' in self.path:
            b[0]+=1
            try:
                j=json.loads(body);fb=j.get('feedback_b64','') or '';raw=base64.b64decode(fb) if fb else b''
                nz=sum(1 for c in raw if c)
                print("MOCK TEL#%d fb_len=%s nz=%d"%(b[0],j.get('feedback_length'),nz),flush=True)
            except Exception as e: print("mock err",e,flush=True)
        self._s({"received":True,"connects":b[0],"reward_now":False})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H);srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start();time.sleep(0.3)
shutil.copy(os.path.join(HERE,"updater_big.exe"), os.path.join(GAMEDIR,"updater.exe"))
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True,"headlessUpdate":True}))
EXE=os.path.join(GAMEDIR,"ThreatInvaders.exe")
seen=set()
def on_msg(m,data):
    if m.get('type')=='send':
        p=m['payload']
        if p.get('type')=='TELEM': print("FRIDA TELEM",p['tag'],"len",p['len'],"head:",p['head'][:200],flush=True)
        elif p.get('type')=='TELEM_HEX':
            h=p['hex']
            if h not in seen:
                seen.add(h); idx=len(seen)
                open(os.path.join(HERE,"frida_tel%d.bin"%idx),"wb").write(bytes.fromhex(h))
                print("FRIDA TELEM_HEX saved frida_tel%d.bin (%d bytes)"%(idx,len(h)//2),flush=True)
        elif p.get('type')=='HOOKED': print("FRIDA HOOKED",p['name'],p['addr'],flush=True)
        elif p.get('type')=='ERR': print("FRIDA ERR",p['e'],flush=True)
pid=frida.spawn([EXE], cwd=GAMEDIR)
session=frida.attach(pid)
script=session.create_script(open(os.path.join(HERE,"hook.js")).read())
script.on('message', on_msg)
script.load()
frida.resume(pid)
print("spawned+instrumented",pid,flush=True)
time.sleep(100)
try: frida.kill(pid)
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
print("done; mock beacons",b[0],flush=True)
srv.shutdown()
