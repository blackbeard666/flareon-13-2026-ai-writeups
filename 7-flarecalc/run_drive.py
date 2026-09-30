import frida, time, os, ctypes
from ctypes import wintypes
EXE=os.path.abspath("FlareCalc.exe")
pid=frida.spawn([EXE]); session=frida.attach(pid)
s=session.create_script(open("drive.js").read())
def onmsg(m,d):
    if m.get('type')=='send':
        p=m['payload']
        if p.get('t')=='VP': print("VP size=%d ascii=%s"%(p['size'],p['ascii']),flush=True)
        elif p.get('t') in ('SWTW','SWTA'): print("DISPLAY[%s]: %r"%(p['t'],p['s']),flush=True)
        else: print(p,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load(); frida.resume(pid)
print("spawned",pid,flush=True)
time.sleep(3)
# find window and send WM_CHAR
u=ctypes.WinDLL('user32'); 
FindWindowW=u.FindWindowW; FindWindowW.restype=wintypes.HWND; FindWindowW.argtypes=[wintypes.LPCWSTR,wintypes.LPCWSTR]
PostMessageW=u.PostMessageW
hwnd=FindWindowW("Flare-OnCalculatorClass",None)
print("hwnd",hwnd,flush=True)
WM_CHAR=0x102; WM_KEYDOWN=0x100; WM_KEYUP=0x101
def sendseq(seq):
    for ch in seq:
        PostMessageW(hwnd,WM_CHAR,ord(ch),0); time.sleep(0.15)
if hwnd:
    for eq in ["2+2=","7*6=","1/3="]:
        print("--- entering",eq,flush=True); sendseq(eq); time.sleep(1.0)
        PostMessageW(hwnd,WM_CHAR,ord('c'),0); time.sleep(0.3)  # maybe clear
time.sleep(3)
try: frida.kill(pid)
except: pass
