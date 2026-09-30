import frida, time, os, ctypes, sys
from ctypes import wintypes
EXE=os.path.abspath("FlareCalc.exe")
pid=frida.spawn([EXE]); session=frida.attach(pid)
last=[""]; events=[]
s=session.create_script(open("probe.js").read())
def onmsg(m,d):
    if m.get('type')=='send':
        p=m['payload']; t=p.get('t')
        if t=='D': last[0]=p['s']
        elif t in ('FILE','LOADLIB','GPA','VP'):
            events.append(p); print("EVENT",p,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load(); frida.resume(pid); time.sleep(3)
u=ctypes.WinDLL('user32'); FindWindowW=u.FindWindowW; FindWindowW.restype=wintypes.HWND; FindWindowW.argtypes=[wintypes.LPCWSTR,wintypes.LPCWSTR]
PM=u.PostMessageW; WM_CHAR=0x102
hwnd=FindWindowW("Flare-OnCalculatorClass",None); print("hwnd",hwnd,flush=True)
def typ(seq,wait=0.04):
    for ch in seq: PM(hwnd,WM_CHAR,ord(ch),0); time.sleep(wait)
def test(op):
    PM(hwnd,WM_CHAR,ord('c'),0); time.sleep(0.05)
    typ("5"); typ(op); typ("3"); typ("="); time.sleep(0.12)
    return last[0]
# enumerate operators across many chars
import string
cands = "+-*/%^&|~!.=<>()[]{}#$@?:;,\\\"'`_ " + string.ascii_letters + string.digits
print("=== operator scan (5 <op> 3 =) ===",flush=True)
seen={}
for c in cands:
    r=test(c)
    seen[c]=r
for c,r in seen.items():
    # flag operators that produced a numeric result different from trivial
    if r not in ('0','5','53','3','') :
        print("op %r -> %r"%(c,r),flush=True)
print("=== events during scan:",len(events),flush=True)
time.sleep(1)
try: frida.kill(pid)
except: pass
