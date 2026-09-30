import frida, time, os, ctypes, pickle
from ctypes import wintypes
EXE=os.path.abspath("FlareCalc.exe")
keys=sorted(set(k for k,_ in pickle.load(open('map_entries.pkl','rb'))))
pid=frida.spawn([EXE]); session=frida.attach(pid)
vpfired=[]
s=session.create_script(open("drive.js").read())
def onmsg(m,d):
    if m.get('type')=='send':
        p=m['payload']
        if p.get('t')=='VP': vpfired.append(p); print("*** VP FIRED size=%d ascii=%s"%(p['size'],p['ascii']),flush=True)
        elif p.get('t') in ('SWTW','SWTA') and p['s'] not in ('0',): pass
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load(); frida.resume(pid); time.sleep(3)
u=ctypes.WinDLL('user32'); FindWindowW=u.FindWindowW; FindWindowW.restype=wintypes.HWND; FindWindowW.argtypes=[wintypes.LPCWSTR,wintypes.LPCWSTR]
PM=u.PostMessageW; hwnd=FindWindowW("Flare-OnCalculatorClass",None); print("hwnd",hwnd,flush=True)
WM_CHAR=0x102
def typ(seq):
    for ch in seq: PM(hwnd,WM_CHAR,ord(ch),0); time.sleep(0.03)
# test a batch of map keys as direct number entry + '='
for k in keys[:60]:
    PM(hwnd,WM_CHAR,ord('c'),0); time.sleep(0.05)
    typ(str(k)+"=")
    time.sleep(0.1)
    if vpfired: print("VP after key",k,flush=True); break
print("done batch; vp count",len(vpfired),flush=True)
time.sleep(1)
try: frida.kill(pid)
except: pass
