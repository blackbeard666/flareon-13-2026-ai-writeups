import http.server, socketserver, threading, json, subprocess, time, os, shutil, ctypes
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
# find exe base in the game via EnumProcessModules
k32=ctypes.WinDLL('kernel32',use_last_error=True); psapi=ctypes.WinDLL('psapi')
OpenProcess=k32.OpenProcess; OpenProcess.restype=wintypes.HANDLE
RPM=k32.ReadProcessMemory
hproc=OpenProcess(0x0410,False,p.pid)
# EnumProcessModules
arr=(wintypes.HMODULE*1024)(); needed=wintypes.DWORD()
psapi.EnumProcessModulesEx(hproc,arr,ctypes.sizeof(arr),ctypes.byref(needed),0x03)
base=None
namebuf=ctypes.create_unicode_buffer(260)
for i in range(needed.value//ctypes.sizeof(wintypes.HMODULE)):
    psapi.GetModuleFileNameExW(hproc,arr[i],namebuf,260)
    if namebuf.value.lower().endswith("threatinvaders.exe"):
        base=arr[i]; break
print("exe base:",hex(base) if base else None,flush=True)
def rd(rva,n):
    buf=(ctypes.c_ubyte*n)(); r=ctypes.c_size_t()
    RPM(hproc, ctypes.c_void_p(base+rva), buf, n, ctypes.byref(r))
    return bytes(buf)
A=rd(0x7FF800,16); B=rd(0x7FFA30,16)
out=bytes(A[15-i]^B[i] for i in range(16))
print("A:",A.hex()); print("B:",B.hex())
print("A[15-i]^B[i]:",out.hex(),"|","".join(chr(c) if 32<=c<127 else '.' for c in out),flush=True)
print("pcap TEL#3 :","54ae032ea875b0f8cc578a511fe71631",flush=True)
gate=rd(0x7FD5FE,4); print("gate byte 0x7FD5FE:",gate.hex(),flush=True)
lg=rd(0x7FE5E8,8); print("length global 0x7FE5E8:",lg.hex(),flush=True)
ptrg=rd(0x7FE5B0,8); print("ptr global 0x7FE5B0:",ptrg.hex(),flush=True)
buf=rd(0x7FE5F0,0x1000)
open(os.path.join(HERE,"buf_7FE5F0.bin"),"wb").write(buf)
nz=sum(1 for c in buf if c)
print("0x7FE5F0 buffer nonzero=%d first96=%s"%(nz,buf[:96].hex()),flush=True)
print("  ascii:","".join(chr(c) if 32<=c<127 else '.' for c in buf[:120]),flush=True)
# also dump wider tables around A and B (maybe longer)
open(os.path.join(HERE,"tableA_wide.bin"),"wb").write(rd(0x7FF700,0x400))
open(os.path.join(HERE,"tableB_wide.bin"),"wb").write(rd(0x7FF900,0x400))
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
srv.shutdown()
