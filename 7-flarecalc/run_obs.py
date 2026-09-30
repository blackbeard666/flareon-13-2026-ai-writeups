import frida, sys, time, subprocess, os
EXE=os.path.abspath("FlareCalc.exe")
pid=frida.spawn([EXE])
session=frida.attach(pid)
s=session.create_script(open("obs.js").read())
def onmsg(m,d):
    if m.get('type')=='send':
        p=m['payload']
        if p.get('t')=='VP': print("VP addr=%s size=%d prot=0x%x head=%s"%(p['addr'],p['size'],p['prot'],p['head'][:80]),flush=True)
        else: print(p,flush=True)
    elif m.get('type')=='error': print("ERR",m.get('description'),flush=True)
s.on('message',onmsg); s.load()
frida.resume(pid)
print("spawned",pid,flush=True)
time.sleep(8)
try: frida.kill(pid)
except: pass
