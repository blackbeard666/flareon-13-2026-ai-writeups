import _winapi, subprocess, sys, os

# Stand-in for the parent: serve the key over \\.\pipe\FlareChallenge and run the child.
key = sys.argv[1].encode('latin1').decode('unicode_escape').encode('latin1')
PIPE_ACCESS_OUTBOUND = 2
h = _winapi.CreateNamedPipe('\\\\.\\pipe\\FlareChallenge', PIPE_ACCESS_OUTBOUND, 0, 1, 512, 512, 0, _winapi.NULL)
child = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'child_patched.exe')
p = subprocess.Popen([child], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
_winapi.ConnectNamedPipe(h, _winapi.NULL)
_winapi.WriteFile(h, key)
_winapi.CloseHandle(h)
out, _ = p.communicate(b'\r\n', timeout=15)
print(out)
