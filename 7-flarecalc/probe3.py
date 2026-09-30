import frida, time, os, ctypes
from ctypes import wintypes
EXE=os.path.abspath("FlareCalc.exe")
pid=frida.spawn([EXE]); session=frida.attach(pid)
disp=[]
s=session.create_script(open("probe.js").read())
def onmsg(m,d):
    if m.get('type')=='send':
        p=m['payload']
        if p.get('t')=='D': disp.append(p['s']); 
        elif p.get('t')=='VP': print("VP!",p,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load(); frida.resume(pid); time.sleep(3)
u=ctypes.WinDLL('user32'); FW=u.FindWindowW; FW.restype=wintypes.HWND; FW.argtypes=[wintypes.LPCWSTR,wintypes.LPCWSTR]
PM=u.PostMessageW; WM_CHAR=0x102
hwnd=FW("Flare-OnCalculatorClass",None); print("hwnd",hwnd,flush=True)
def run(seq):
    disp.clear(); PM(hwnd,WM_CHAR,ord('c'),0); time.sleep(0.05)
    for ch in seq: PM(hwnd,WM_CHAR,ord(ch),0); time.sleep(0.05)
    time.sleep(0.6); return disp[-3:]
print("843*952= ->", run("843*952="),flush=True)
time.sleep(0.5)
# check window title of calc (rickroll might set title) and any new windows
GWT=u.GetWindowTextW; GWT.argtypes=[wintypes.HWND,wintypes.LPWSTR,ctypes.c_int]
buf=ctypes.create_unicode_buffer(256); GWT(hwnd,buf,256); print("calc title:",buf.value,flush=True)
# enumerate all windows of the process for any popup
print("952*843= ->", run("952*843="),flush=True)
time.sleep(1)
try: frida.kill(pid)
except: pass
