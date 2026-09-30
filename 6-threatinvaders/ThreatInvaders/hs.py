import http.server, socketserver, threading, json, base64, subprocess, time, os

os.makedirs('hs_out', exist_ok=True)
seen=set(); idx=[0]
# full pcap highscores (8 entries incl RAY binary comment)
HS={"entries":[
 {"id":"f73924f6-8610-40ef-bc7e-59ab407c7b26","player_name":"ZAP","score":9870,"wave_reached":7,"duration_seconds":612,"achieved_at":"2026-07-02T18:14:00Z","comment_b64":"Y2xlYXJlZCB3YXZlIDcgb24gb25lIGxpZmU="},
 {"id":"7019a8b2-3ac3-4739-86ed-c52f312854d0","player_name":"NOVA","score":8140,"wave_reached":6,"duration_seconds":540,"achieved_at":"2026-07-11T09:03:00Z","comment_b64":"dGhlIHNhdWNlciBvd2VzIG1lIG1vbmV5"},
 {"id":"468622df-f946-4f5a-a47e-d6cd5cb1faf0","player_name":"RAY","score":6520,"wave_reached":5,"duration_seconds":431,"achieved_at":"2026-07-19T21:47:00Z","comment_b64":"AAECAwQFBgcICQoLDA0ODxAREhMUFRYXGBkaGxwdHh8AYmluYXJ5//4gcGF5bG9hZA=="},
 {"id":"f047cf98-06ac-4510-9443-a9c1226d4dda","player_name":"ORBIT","score":5300,"wave_reached":4,"duration_seconds":388,"achieved_at":"2026-08-01T12:22:00Z","comment_b64":"YnVua2VycyBnb25lIGJ5IHdhdmUgMywgc3RpbGwgbWFkZSBpdA=="},
 {"id":"7d1f9bcb-6691-4a7d-a15b-ad5b31929c82","player_name":"PIXEL","score":4110,"wave_reached":4,"duration_seconds":301,"achieved_at":"2026-08-05T16:35:00Z","comment_b64":""},
 {"id":"1a1a0656-1c53-4ca0-b68a-74cb5d881e1d","player_name":"GLITCH","score":2980,"wave_reached":3,"duration_seconds":245,"achieved_at":"2026-08-09T20:10:00Z","comment_b64":"cmFnZSBxdWl0IGF0IHRoZSBsYXN0IGludmFkZXI="},
 {"id":"cba6dc87-909d-403f-a628-467c3c1df938","player_name":"ECHO","score":1760,"wave_reached":2,"duration_seconds":158,"achieved_at":"2026-08-14T11:58:00Z","comment_b64":"Zmlyc3QgZXZlciBydW4h"},
 {"id":"8012647c-84ad-4970-b67b-84e4146c4e93","player_name":"DOT","score":640,"wave_reached":1,"duration_seconds":74,"achieved_at":"2026-08-17T08:29:00Z","comment_b64":"VGhpcyB3YXMgYXdlc29tZQ=="}
],"total":8}
class H(http.server.BaseHTTPRequestHandler):
    def _s(self,o):
        b=json.dumps(o).encode();self.send_response(200);self.send_header('Content-Type','application/json');self.send_header('Access-Control-Allow-Origin','*');self.end_headers();self.wfile.write(b)
    def log_message(self,*a): pass
    def do_GET(self):
        if 'health' in self.path: self._s({"status":"ok","entries":8,"time":"2026-09-28T00:00:00Z"})
        elif 'highscores' in self.path: self._s(HS)
        elif 'version' in self.path: self._s({"latest":"1.0.0.0","message":""})
        else: self._s({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0)); body=self.rfile.read(n)
        if 'telemetry' in self.path:
            try:
                j=json.loads(body); raw=base64.b64decode(j.get('feedback_b64','') or '')
                nz=sum(1 for c in raw if c); k=(j.get('feedback_length'),nz)
                if k not in seen:
                    seen.add(k); i=idx[0]; idx[0]+=1; open('hs_out/tel%d.bin'%i,'wb').write(raw)
                    print('TEL#%d fb_len=%s decoded=%d nonzero=%d head=%s'%(i,j.get('feedback_length'),len(raw),nz,raw[:24].hex()),flush=True)
            except Exception as e: print('err',e,flush=True)
            self._s({"received":True,"feedback_received":True,"connects":9,"reward_now":True})
        else: self._s({"entry":json.loads(body) if body else {},"rank":1})
threading.Thread(target=lambda: socketserver.ThreadingTCPServer(('127.0.0.1',8090),H).serve_forever(),daemon=True).start(); time.sleep(0.4)
open('config.json','w').write(json.dumps({"baseUrl":"http://127.0.0.1:8090","autoSyncSeconds":1,"muted":True,"headlessUpdate":True,"forceBoardRefresh":True}))
EXE=os.path.join(os.path.dirname(os.path.abspath(__file__)),'ThreatInvaders.exe')
p=subprocess.Popen([EXE],cwd=os.path.dirname(EXE)); print('spawned',p.pid,flush=True); time.sleep(25)
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
os.remove('config.json') if os.path.exists('config.json') else None
print('distinct telemetry:',idx[0],flush=True)
