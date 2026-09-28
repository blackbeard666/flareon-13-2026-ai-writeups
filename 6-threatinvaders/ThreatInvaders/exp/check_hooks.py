import http.server, socketserver, threading, json, subprocess, time, os, ctypes
from ctypes import wintypes
HERE=os.path.dirname(os.path.abspath(__file__)); GAMEDIR=os.path.dirname(HERE)
b=[0]
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        x=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.end_headers();self.wfile.write(x)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path:self._s({"status":"ok"})
        elif 'highscores' in self.path:self._s({"entries":[],"total":0})
        elif 'version' in self.path:self._s({"latest":"1.0.0.0","message":""})
        else:self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0));self.rfile.read(n)
        if 'telemetry' in self.path:b[0]+=1
        self._s({"received":True})
srv=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H);srv.daemon_threads=True
threading.Thread(target=srv.serve_forever,daemon=True).start();time.sleep(0.3)
open(os.path.join(GAMEDIR,"config.json"),"w").write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":2,"muted":True}))
env=dict(os.environ); env["DOTNET_ROLL_FORWARD"]="LatestMajor"
p=subprocess.Popen([os.path.join(GAMEDIR,"ThreatInvaders.exe")],cwd=GAMEDIR,env=env)
print("spawned",p.pid,flush=True)
for _ in range(25):
    time.sleep(1)
    if b[0]>=1: break
print("beacons",b[0],flush=True)
time.sleep(1)
k32=ctypes.WinDLL('kernel32',use_last_error=True)
OpenProcess=k32.OpenProcess; OpenProcess.restype=wintypes.HANDLE
RPM=k32.ReadProcessMemory
LoadLibrary=k32.LoadLibraryW; LoadLibrary.restype=wintypes.HMODULE
GetProcAddress=k32.GetProcAddress; GetProcAddress.restype=ctypes.c_void_p; GetProcAddress.argtypes=[wintypes.HMODULE,ctypes.c_char_p]
hproc=OpenProcess(0x0410,False,p.pid)
# load ws2_32 in our process (same base as game due to ASLR-per-boot)
ws=LoadLibrary("ws2_32.dll")
funcs=["send","WSASend","connect","WSAConnect","closesocket","recv","WSARecv"]
for fn in funcs:
    a=GetProcAddress(ws, fn.encode())
    if not a: print(fn,"no addr"); continue
    # our bytes
    ours=(ctypes.c_ubyte*16).from_address(a); ours=bytes(ours)
    # game bytes
    buf=(ctypes.c_ubyte*16)(); read=ctypes.c_size_t()
    ok=RPM(hproc, ctypes.c_void_p(a), buf, 16, ctypes.byref(read))
    theirs=bytes(buf)
    same = ours==theirs
    print("%-12s @0x%X ours=%s game=%s %s"%(fn, a, ours.hex(), theirs.hex(), "SAME" if same else "*** DIFF (HOOK?) ***"))
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
cfg=os.path.join(GAMEDIR,"config.json")
if os.path.exists(cfg): os.remove(cfg)
srv.shutdown()
