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
subprocess.run([DOTNET,EP,str(p.pid)],capture_output=True,text=True,timeout=120,env=env)
bd=None
for line in open(os.path.join(HERE,"method_map.txt")):
    pr=line.strip().split("\t")
    if len(pr)==3 and pr[2].endswith("TelemetryReporter.BuildDocument"): bd=hex(int(pr[0],16))
session=frida.attach(p.pid)
JS='''
var BD=ptr("%s");
function follow(t){for(var h=0;h<6;h++){var b0=t.readU8(),b1=t.add(1).readU8();
 if(b0==0xE9){t=t.add(5).add(t.add(1).readS32());continue;}
 if(b0==0xFF&&b1==0x25){t=t.add(6).add(t.add(2).readS32()).readPointer();continue;}
 if(b0==0x48&&b1==0x8B&&t.add(2).readU8()==0x05&&t.add(7).readU8()==0x66){var j2=t.add(16);if(j2.readU8()==0xFF&&j2.add(1).readU8()==0x25){t=j2.add(6).add(j2.add(2).readS32()).readPointer();continue;}}
 break;}return t;}
var code=new Uint8Array(BD.readByteArray(0xA0));var calls=[];for(var i=0;i<code.length-6;i++){if(code[i]==0xFF&&code[i+1]==0x15)calls.push(i);}
var cs=calls.filter(function(x){return x>=0x88&&x<0x98;})[0];
var instr=BD.add(cs);var real=follow(instr.add(6).add(instr.add(2).readS32()).readPointer());
send({t:"efbreal", addr:real.toString()});
var m=Process.findModuleByAddress(real);
if(m){send({t:"module",name:m.name,base:m.base.toString(),size:m.size});}
else{var r=Process.findRangeByAddress(real); send({t:"range",base:r.base.toString(),size:r.size,prot:r.protection});}
// dump 0x740000 bytes starting at real - 0x1000 (covers code + tables)
var dstart=real.sub(0x2000); var total=0x740000; var CH=0x40000; var idx=0;
for(var off=0; off<total; off+=CH){
  var n=Math.min(CH,total-off);
  try{ var buf=dstart.add(off).readByteArray(n); send({t:"chunk", idx:idx, off:off, start:dstart.toString()}, buf); idx++; }catch(e){ send({t:"chunkerr",off:off,e:''+e}); }
}
send({t:"DONE"});
''' % bd
s=session.create_script(JS)
fdump=open(os.path.join(HERE,"injmod.bin"),"wb")
meta={}
def onmsg(m,d):
    if m.get('type')=='send':
        pl=m['payload']
        if pl.get('t')=='chunk':
            if d: fdump.seek(pl['off']); fdump.write(d)
        elif pl.get('t')=='DONE': print("DUMP DONE",flush=True)
        else: print("FRIDA",pl,flush=True); meta.update(pl)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load()
time.sleep(20)
fdump.close()
open(os.path.join(HERE,"injmod_meta.json"),"w").write(json.dumps(meta))
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
for f in ("config.json","updater.exe"):
    fp=os.path.join(GAMEDIR,f)
    if os.path.exists(fp): os.remove(fp)
srv.shutdown()
print("meta",meta,flush=True)
