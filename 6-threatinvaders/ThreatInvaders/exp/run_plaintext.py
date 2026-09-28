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
for _ in range(20):
    time.sleep(1)
    if b[0]>=1: break
session=frida.attach(p.pid)
JS='''
var base=Module.findBaseAddress("ThreatInvaders.exe");
var cipher=base.add(0xc65e0);
Interceptor.attach(cipher,{
  onEnter:function(a){ this.buf=a[0]; this.len=a[1].toInt32();
    if(this.len>0 && this.len<0x2000){
      var pt=new Uint8Array(a[0].readByteArray(this.len));
      send({t:"PLAINTEXT", len:this.len, hex:Array.from(pt).map(function(x){return('0'+x.toString(16)).slice(-2)}).join('')});
    }
  }
});
send({t:"READY", cipher:cipher.toString()});
'''
s=session.create_script(JS)
seen=set()
def onmsg(m,d):
    if m.get('type')=='send':
        pl=m['payload']
        if pl.get('t')=='PLAINTEXT':
            h=pl['hex']
            if h not in seen:
                seen.add(h)
                raw=bytes.fromhex(h)
                asc="".join(chr(c) if 32<=c<127 else '.' for c in raw)
                print("PLAINTEXT len=%d ascii=%s"%(pl['len'],asc[:200]),flush=True)
                print("   hex:",h[:200],flush=True)
                open(os.path.join(HERE,"plaintext_%d_%d.bin"%(pl['len'],len(seen))),"wb").write(raw)
        else: print("FRIDA",pl,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load()
print("cipher hooked, waiting",flush=True)
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
