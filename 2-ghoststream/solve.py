import struct
d=open('child.exe','rb').read()
D=bytearray(d[0x3078:d.index(b'\0',0x3078)])
def patched_strlen(s):
    s=bytearray(s); i=0
    while True:
        s[i]=((s[i]+i+1)&0xff)^0x13; i+=1
        if s[i-0]==0 if i<len(s) else True: break
    return s
Dt=patched_strlen(D+b'\0')[:len(D)]
C=struct.pack('<QQQQIH',0x8b397ad735875c96,0xc85856bb286d0475,0x37a956a4e1daee35,0x0d340a27f9561581,0x262c82ee,0xf8a5)
def run(key):
    S=list(range(256)); j=0
    for i in range(256):
        j=(j+key[i%len(key)]+S[i])&0xff; S[i],S[j]=S[j],S[i]
    i=j=0; out=bytearray()
    for k in range(38):
        i=(i+19)&0xff; j=(j+S[i])&0xff; S[i],S[j]=S[j],S[i]
        out.append(S[(S[i]+S[j])&0xff]^Dt[k%len(Dt)]^((19+C[k])&0xff))
    return bytes(out)
potion=open('extracted/GhostStream/PolyjuicePotion.txt','rb').read()
xk=bytes([0x8b,0x8f,0x92,0x85,0x88,0x96,0x98,0x9b,0x94,0x8b,0x95,0xe6,0xed,0xf0,0xe7])
cands={'ads':b'AlbusDumbledore ','ads_nospace':b'AlbusDumbledore'}
base=b'AlbusDumbledore \r\n'
for prev in range(256):
    t=bytearray(x^1^prev for x in base)
    for n in range(15): t[n]^=xk[n]
    cands['wmcreate_prev%02x'%prev]=bytes(t)
cands['potion']=potion
for n,k in cands.items():
    k=k[:len(k)] 
    for sep in (b'\r',b'\n'):
        if sep in k: k=k[:k.index(sep)]
    if not k: continue
    r=run(k)
    if b'flare-on' in r or n in('ads','ads_nospace','potion'): print(n,k,r)
print('Dt',Dt)
print('---')
import itertools
def run2(key,L):
    S=list(range(256)); j=0
    for i in range(256):
        j=(j+key[i%len(key)]+S[i])&0xff; S[i],S[j]=S[j],S[i]
    i=j=0; out=bytearray()
    for k in range(38):
        i=(i+L)&0xff; j=(j+S[i])&0xff; S[i],S[j]=S[j],S[i]
        out.append(S[(S[i]+S[j])&0xff]^Dt[k%len(Dt)]^((L+C[k])&0xff))
    return bytes(out)
for name,k in [('potion255',potion[:255]),('ads','AlbusDumbledore '.encode())]+[(n,v) for n,v in cands.items() if n.startswith('wm')]:
    for L in (18,19):
        r=run2(k,L)
        if b'@fl' in r or b'on.com' in r or not name.startswith('wm'): print(name,L,r)
print('=== prev83')
k=cands['wmcreate_prev83']; print(k)
for kk in (k, k.rstrip(b'\x8f\x88'), k[:15], k[:16]):
    print(kk, run(kk))
