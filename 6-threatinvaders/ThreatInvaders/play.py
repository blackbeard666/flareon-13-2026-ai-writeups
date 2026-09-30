import http.server, socketserver, threading, json, base64, subprocess, time, os

# mimic the pcap server responses; capture every telemetry feedback distinctly
os.makedirs('play_out', exist_ok=True)
LOG=open('play_out/log.txt','w')
def log(*a): s=' '.join(str(x) for x in a); print(s); print(s,file=LOG); LOG.flush()
seen=set(); idx=[0]
HS={"entries":[{"id":"f73924f6-8610-40ef-bc7e-59ab407c7b26","player_name":"ZAP","score":9870,"wave_reached":7,"duration_seconds":612,"achieved_at":"2026-07-02T18:14:00Z","comment_b64":"Y2xlYXJlZCB3YXZlIDcgb24gb25lIGxpZmU="}],"total":1}
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        b=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.send_header('Access-Control-Allow-Origin','*');self.end_headers();self.wfile.write(b)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path: self._s({"status":"ok","entries":1,"time":"2026-09-28T00:00:00Z"})
        elif 'highscores' in self.path: self._s(HS)
        elif 'version' in self.path: self._s({"latest":"1.0.0.1","message":""})
        else: self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0)); body=self.rfile.read(n)
        if 'telemetry' in self.path:
            try:
                j=json.loads(body); fb=j.get('feedback_b64','') or ''; raw=base64.b64decode(fb)
                nz=sum(1 for c in raw if c); key=(j.get('feedback_length'),nz,raw[:16])
                if key not in seen:
                    seen.add(key); i=idx[0]; idx[0]+=1
                    open('play_out/tel%d.bin'%i,'wb').write(raw)
                    log('TEL#%d games=%s fb_len=%s decoded=%d nonzero=%d head=%s'%(i,j.get('games_played'),j.get('feedback_length'),len(raw),nz,raw[:24].hex()))
            except Exception as e: log('tel err',e)
            self._s({"received":True,"duplicate":False,"session_games":1,"total_games":1,"sessions":1,"feedback_received":True,"connects":9,"reward_now":True})
        elif 'highscores' in self.path:
            log('SCORE POST', body[:220].decode('latin1',errors='replace'))
            self._s({"entry":json.loads(body) if body else {},"rank":1})
        else: self._s({})
def serve():
    s=socketserver.ThreadingTCPServer(('127.0.0.1',8090),H); s.serve_forever()
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.4)
open('config.json','w').write(json.dumps({"baseUrl":"http://127.0.0.1:8090","apiKey":"ed347a07305214ab98974a008674eb78cd03b1fedb73c8be9f79e40fb8e155b0","autoSyncSeconds":2,"muted":True,"headlessUpdate":True,"defaultPlayerName":"FLARE"}))
EXE=os.path.join(os.path.dirname(os.path.abspath(__file__)),'ThreatInvaders.exe')
p=subprocess.Popen([EXE],cwd=os.path.dirname(EXE)); log('spawned',p.pid); time.sleep(6)

# drive the game via SendKeys through PowerShell
ps=r'''
Add-Type -AssemblyName System.Windows.Forms,Microsoft.VisualBasic
Start-Sleep -Milliseconds 500
[Microsoft.VisualBasic.Interaction]::AppActivate("ThreatInvaders")
Start-Sleep -Milliseconds 400
function K($k){ [System.Windows.Forms.SendKeys]::SendWait($k); Start-Sleep -Milliseconds 120 }
# F1 open debug injector, submit a couple injected scores
K("{F1}"); Start-Sleep -Milliseconds 300
K("{ENTER}"); Start-Sleep -Milliseconds 400
K("{F6}"); Start-Sleep -Milliseconds 500   # burst x10 if available
K("{ENTER}"); Start-Sleep -Milliseconds 400
# also try normal play: back to title then play
K("{ESC}"); Start-Sleep -Milliseconds 300
K(" "); Start-Sleep -Milliseconds 300      # start game
1..40 | ForEach-Object { [System.Windows.Forms.SendKeys]::SendWait(" "); [System.Windows.Forms.SendKeys]::SendWait("{LEFT}"); [System.Windows.Forms.SendKeys]::SendWait("{RIGHT}"); Start-Sleep -Milliseconds 150 }
Start-Sleep -Seconds 3
# name/comment entry submit
K("F"); K("L"); K("A"); K("G"); K("{ENTER}"); Start-Sleep -Milliseconds 300
K("h"); K("i"); K("{ENTER}"); Start-Sleep -Milliseconds 300
'''
open('play_out/drive.ps1','w').write(ps)
subprocess.run(['powershell.exe','-NonInteractive','-ExecutionPolicy','Bypass','-File','play_out/drive.ps1'],cwd=os.path.dirname(EXE),timeout=60)
log('drive done, waiting for beacons')
time.sleep(12)
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
os.remove('config.json') if os.path.exists('config.json') else None
log('done; distinct telemetry captured: %d'%idx[0])
