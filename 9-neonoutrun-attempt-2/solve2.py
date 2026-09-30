# Real flag: lap i must take t_i whole seconds with sin((K_i ± t_i) deg) == 1; bytes t_i form the flag
import json, math
p = json.load(open('params.json'))
out = []
for K, neg in p['laps']:
    s = -1 if neg else 1
    c = [t for t in range(256) if (K + s * t - 90) % 360 == 0]
    assert len(c) == 1, c
    t = c[0]
    assert abs(math.sin(math.radians(K + s * t)) - 1) < 1e-9
    out.append(t)
print(out)
flag = bytearray(out) + b'@f1are-on.com'
flag[0x1e] += 0x3b
print(flag.decode())
