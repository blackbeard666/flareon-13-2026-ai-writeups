import http.server, socketserver, threading, json, base64, subprocess, time, os, shutil, ctypes
from ctypes import wintypes
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
OUT=os.path.join(HERE,"out5"); os.makedirs(OUT,exist_ok=True)
LOG=open(os.path.join(OUT,"log.txt"),"w")
def log(*a):
    s=" ".join(str(x) for x in a); print(s,flush=True); print(s,file=LOG); LOG.flush()
seen=set(); idx=[0]; conn=[0]
HS={"entries":[{"id":"f73924f6-8610-40ef-bc7e-59ab407c7b26","player_name":"ZAP","score":9870,"wave_reached":7,"duration_seconds":612,"achieved_at":"2026-07-02T18:14:00Z","comment_b64":"Y2xlYXJlZCB3YXZlIDcgb24gb25lIGxpZmU="}],"total":1}
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        b=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.end_headers();self.wfile.write(b)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path: self._s({"status":"ok","entries":1,"time":"2026-09-28T00:00:00Z"})
        elif 'highscores' in self.path: self._s(HS)
        elif 'version' in self.path: self._s({"latest":"9.9.9.9","message":"update"})
        else: self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0)); body=self.rfile.read(n)
        if 'telemetry' in self.path:
            conn[0]+=1
            try:
                j=json.loads(body); fb=j.get('feedback_b64','') or ''; raw=base64.b64decode(fb) if fb else b''
                nz=sum(1 for c in raw if c); L=j.get('feedback_length')
                key=(L,nz,raw[:64])
                if key not in seen:
                    seen.add(key); i=idx[0]; idx[0]+=1
                    open(os.path.join(OUT,"exp_tel%d.bin"%i),"wb").write(raw)
                    log("TEL#%d conn=%d fb_len=%s decoded=%d nonzero=%d head=%s"%(i,conn[0],L,len(raw),nz,raw[:64].hex()))
            except Exception as e: log("tel err",e)
            self._s({"received":True,"feedback_received":True,"connects":conn[0],"reward_now":conn[0]>=5})
        elif 'highscores' in self.path: self._s({"entry":json.loads(body) if body else {},"rank":1})
        else: self._s({})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H); srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start(); time.sleep(0.3)
shutil.copy(os.path.join(HERE,"updater_big.exe"), os.path.join(GAMEDIR,"updater.exe"))
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True,"headlessUpdate":True,"defaultPlayerName":"FLARE"}))
EXE=os.path.join(GAMEDIR,"ThreatInvaders.exe")
p=subprocess.Popen([EXE],cwd=GAMEDIR); log("spawned",p.pid)
time.sleep(7)
user32=ctypes.WinDLL('user32',use_last_error=True)
EnumWindows=user32.EnumWindows; EnumWindowsProc=ctypes.WINFUNCTYPE(wintypes.BOOL,wintypes.HWND,wintypes.LPARAM)
GetWindowThreadProcessId=user32.GetWindowThreadProcessId; IsWindowVisible=user32.IsWindowVisible; PostMessageW=user32.PostMessageW
hwnds=[]
def cb(h,l):
    pid=wintypes.DWORD(); GetWindowThreadProcessId(h,ctypes.byref(pid))
    if pid.value==p.pid and IsWindowVisible(h): hwnds.append(h)
    return True
EnumWindows(EnumWindowsProc(cb),0)
log("game hwnds:",hwnds)
WM_KEYDOWN=0x100; WM_KEYUP=0x101; VK_RIGHT=0x27
# keep message pump alive with harmless ignored key at title, for ~200s
end=time.time()+220
while time.time()<end:
    for h in hwnds:
        PostMessageW(h,WM_KEYDOWN,VK_RIGHT,0); PostMessageW(h,WM_KEYUP,VK_RIGHT,0)
    time.sleep(0.5)
    if idx[0]>=3: 
        log("got enough beacons, continuing a bit"); 
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
mk=os.path.join(OUT,"updater_marker.txt")
log("done; beacons:",idx[0]," updater runs:", (open(mk).read().count("updater ran") if os.path.exists(mk) else 0))
srv.shutdown()
