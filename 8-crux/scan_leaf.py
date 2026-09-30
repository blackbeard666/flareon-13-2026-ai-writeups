import sympy, struct, hashlib, sys
from Crypto.Cipher import AES
P=95681613235744740119807961018865688051340183696570761153419351987106658443873
CT=bytes.fromhex("78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232ff619632797e3708ad29b2cdd4491a3c2")
IV=bytes.fromhex("5ff26040c4c20b9f2ffdefa7ecf65d91")
def u32(n): return struct.pack('<I',n)
def bLE(n):
    n=abs(int(n)); b=bytearray()
    while n>0: b.append(n&0xff); n>>=8
    return bytes(b)
# returns (bytes, [slot_offsets]) for leaf-val length L
def cert(p, L):
    p=int(p)
    out=bytearray([1]); slots=[]
    if p==2:
        out+=u32(0)
        kb=bLE(2); out+=u32(len(kb))+kb
        out+=u32(L)
        slots.append(len(out))
        out+=bytes(L)
    else:
        g=int(sympy.primitive_root(p)); fd=sympy.factorint(p-1); facs=[]
        for q in sorted(fd): facs+=[q]*fd[q]
        out+=u32(len(facs))
        for q in facs:
            cb,cs=cert(q,L)
            base=len(out)+4
            out+=u32(len(cb))+cb
            slots+=[base+s for s in cs]
        kb=bLE(p); out+=u32(len(kb))+kb
        gb=bLE(g); out+=u32(len(gb))+gb
    return bytes(out), slots

def scan(L, lo, hi):
    tmpl, slots = cert(P,L); tmpl=bytearray(tmpl)
    print(f"L={L}: len={len(tmpl)} slots={len(slots)} scan {lo}..{hi}", file=sys.stderr)
    for X in range(lo,hi):
        xb=bLE(X)
        if len(xb)!=L or (xb and xb[-1]==0): continue
        for s in slots: tmpl[s:s+L]=xb
        key=hashlib.sha256(bytes(tmpl)).digest()
        pt=AES.new(key,AES.MODE_CBC,IV).decrypt(CT)
        pad=pt[-1]
        if 1<=pad<=16 and pt[-pad:]==bytes([pad])*pad:
            body=pt[:-pad]
            if b'flare' in body or (body and all(32<=c<127 for c in body)):
                print(f"  HIT X={X} pad={pad} body={body!r}")
    print(f"L={L} done", file=sys.stderr)

scan(1,1,256)
scan(2,256,65536)
scan(3,65536,4000000)
