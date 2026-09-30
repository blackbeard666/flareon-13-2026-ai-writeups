import frida, time, os, ctypes
from ctypes import wintypes
EXE=os.path.abspath("FlareCalc.exe")
pid=frida.spawn([EXE]); session=frida.attach(pid)
last=[""]; special=[]
s=session.create_script(open("probe.js").read())
def onmsg(m,d):
    if m.get('type')=='send':
        p=m['payload']; t=p.get('t')
        if t=='D': last[0]=p['s']
        elif t=='VP' or (t=='FILE' and 'staticcache' not in p.get('n','')) or (t=='LOADLIB' and any(k in p.get('n','').lower() for k in('crypt','wintrust','bcrypt','ncrypt'))):
            special.append(p); print("*** SPECIAL",p,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load(); frida.resume(pid); time.sleep(3)
u=ctypes.WinDLL('user32'); FindWindowW=u.FindWindowW; FindWindowW.restype=wintypes.HWND; FindWindowW.argtypes=[wintypes.LPCWSTR,wintypes.LPCWSTR]
PM=u.PostMessageW; WM_CHAR=0x102
hwnd=FindWindowW("Flare-OnCalculatorClass",None); print("hwnd",hwnd,flush=True)
def typ(seq,wait=0.03):
    for ch in seq: PM(hwnd,WM_CHAR,ord(ch),0); time.sleep(wait)
def run(seq):
    PM(hwnd,WM_CHAR,ord('c'),0); time.sleep(0.05); typ(seq); time.sleep(0.15); return last[0]
tests=[
 "1337=","31337=","1337^1337=","1337&1337=","65535^65535=",
 "9999999999*9999999999=","0/0=","1/0=","2^2^2^2^2^2^2^2=",
 "255&255&255=","1|2|4|8|16=","1337*1337*1337=",
 # long chain
 "1"+"+1"*50+"=",
 "1337=", "11111111*11111111=",
 "0.0000001/0.0000001=", "-1~=", "4294967296=","4294967295&1=",
]
for t in tests:
    r=run(t); print("seq %-30r -> %r"%(t[:30],r),flush=True)
print("=== special events:",len(special),flush=True)
time.sleep(1)
try: frida.kill(pid)
except: pass
