import os, subprocess, time, _winapi

# Run the patched parent, block its child drop, and read the pipe message ourselves.
here = os.path.dirname(os.path.abspath(__file__))
run = os.path.join(here, 'run')
tmp = os.path.join(run, 'tmp')
os.makedirs(tmp, exist_ok=True)
lock = _winapi.CreateFile(os.path.join(tmp, 'Partner_CTF.exe'), 0x40000000, 0, _winapi.NULL, 2, 0x80, _winapi.NULL)

env = dict(os.environ, TEMP=tmp + '\\', TMP=tmp + '\\')
p = subprocess.Popen([os.path.join(run, 'GhostStream.exe')], cwd=run, env=env,
                     stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
h = None
for _ in range(400):
    try:
        h = _winapi.CreateFile('\\\\.\\pipe\\FlareChallenge', 0x80000000, 0, _winapi.NULL, 3, 0, _winapi.NULL)
        break
    except OSError:
        time.sleep(0.1)
if h:
    data, _ = _winapi.ReadFile(h, 256)
    print('PIPE:', data)
    _winapi.CloseHandle(h)
out, _ = p.communicate(timeout=30)
print(out)
_winapi.CloseHandle(lock)
