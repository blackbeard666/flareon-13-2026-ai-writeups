import http.server, socketserver, threading, json, base64, subprocess, time, os, signal

LOG = open('detonate_requests.log','w')
def log(*a):
    print(*a); print(*a,file=LOG); LOG.flush()

class H(http.server.BaseHTTPRequestHandler):
    def _send(self, obj, extra=None):
        body=json.dumps(obj).encode()
        self.send_response(200)
        self.send_header('Content-Type','application/json; charset=utf-8')
        self.send_header('Access-Control-Allow-Origin','*')
        if extra:
            for k,v in extra.items(): self.send_header(k,v)
        self.end_headers(); self.wfile.write(body)
    def log_message(self,*a): pass
    def do_GET(self):
        log('GET',self.path)
        if 'health' in self.path: self._send({"status":"ok","entries":10,"time":"2026-09-28T00:00:00Z"})
        elif 'highscores' in self.path:
            self._send({"entries":[{"id":"00000000-0000-0000-0000-000000000001","player_name":"MARKER1","score":99999,"wave_reached":9,"duration_seconds":1,"achieved_at":"2026-09-28T00:00:00Z","comment_b64":base64.b64encode(b"COMMENT_MARKER_REVEAL").decode()}],"total":1})
        elif 'version' in self.path:
            self._send({"latest":"9.9.9.9","message":"VERSION_MESSAGE_MARKER_REVEAL"})
        else: self._send({})
    def do_POST(self):
        n=int(self.headers.get('Content-Length',0)); body=self.rfile.read(n)
        if 'telemetry' in self.path:
            try:
                j=json.loads(body); fb=j.get('feedback_b64',''); raw=base64.b64decode(fb) if fb else b''
                open('last_feedback.bin','wb').write(raw)
                idx=raw.find(b'DEADBEEF')
                log('TELEMETRY fb_len=%s totalbytes=%d nonzero=%d DEADBEEF@=%d'%(j.get('feedback_length'),len(raw),sum(1 for c in raw if c),idx))
            except Exception as e: log('telemetry parse err',e, body[:100])
            self._send({"received":True,"duplicate":False,"session_games":9,"total_games":9,"sessions":9,"feedback_received":True,"connects":9,"reward_now":True})
        elif 'highscores' in self.path:
            log('SCORE POST', body[:200])
            self._send({"entry":json.loads(body),"rank":1})
        else: self._send({})

def serve():
    with socketserver.ThreadingTCPServer(('127.0.0.1',8090),H) as s:
        s.serve_forever()
threading.Thread(target=serve,daemon=True).start(); time.sleep(0.5)
log('server up on 8090')

# remove stale updater log
try: os.remove('updater_args.log')
except: pass

# spawn the game
log('spawning game...')
EXE=os.path.join(os.path.dirname(os.path.abspath(__file__)),'ThreatInvaders.exe')
p=subprocess.Popen([EXE], cwd=os.path.dirname(EXE))
time.sleep(35)
log('killing game...')
try: p.terminate()
except: pass
time.sleep(1)
try: p.kill()
except: pass
# report updater args
if os.path.exists('updater_args.log'):
    log('=== updater_args.log ===')
    log(open('updater_args.log').read())
else:
    log('updater.exe was NOT run')
log('done')
LOG.close()
