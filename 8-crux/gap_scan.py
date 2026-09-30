import sympy, struct, hashlib, sys
from Crypto.Cipher import AES
from multiprocessing import Pool
P=95681613235744740119807961018865688051340183696570761153419351987106658443873
CT=bytes.fromhex("78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232ff619632797e3708ad29b2cdd4491a3c2")
IV=bytes.fromhex("5ff26040c4c20b9f2ffdefa7ecf65d91")
def u32(n): return struct.pack('<I',n)
def bLE(n):
    n=abs(int(n)); b=bytearray()
    while n>0: b.append(n&0xff); n>>=8
    return bytes(b)
def cert_tmpl(L):
    slots=[]
    def cert(p):
        p=int(p); out=bytearray([1]); sl=[]
        if p==2:
            out+=u32(0); kb=bLE(2); out+=u32(len(kb))+kb; out+=u32(L); sl.append(len(out)); out+=bytes(L)
        else:
            g=int(sympy.primitive_root(p)); fd=sympy.factorint(p-1); f=[]
            for q in sorted(fd): f+=[q]*fd[q]
            out+=u32(len(f))
            for q in f:
                cb,cs=cert(q); base=len(out)+4; out+=u32(len(cb))+cb; sl+=[base+s for s in cs]
            kb=bLE(p); gb=bLE(g); out+=u32(len(kb))+kb+u32(len(gb))+gb
        return bytes(out),sl
    return cert(P)
TMPL=None; SLOTS=None; Lg=3
def init(L):
    global TMPL,SLOTS,Lg; Lg=L; t,s=cert_tmpl(L); TMPL=bytearray(t); SLOTS=s
def work(rng):
    lo,hi=rng; hits=[]
    t=bytearray(TMPL); L=Lg; slots=SLOTS
    aes=AES.new  # local
    for X in range(lo,hi):
        xb=X.to_bytes(L,'little')
        if xb[-1]==0: continue
        for s in slots: t[s:s+L]=xb
        key=hashlib.sha256(bytes(t)).digest()
        pt=AES.new(key,AES.MODE_CBC,IV).decrypt(CT)
        pad=pt[-1]
        if 1<=pad<=16 and pt[-pad:]==bytes([pad])*pad:
            body=pt[:-pad]
            if b'flare' in body or (body and all(32<=c<127 for c in body)):
                hits.append((X,pad,bytes(pt)))
    return hits
if __name__=="__main__":
    L=int(sys.argv[1]); lo=int(sys.argv[2]); hi=int(sys.argv[3])
    NPROC=12; chunk=(hi-lo)//NPROC+1
    ranges=[(lo+i*chunk, min(lo+(i+1)*chunk,hi)) for i in range(NPROC)]
    with Pool(NPROC, initializer=init, initargs=(L,)) as pool:
        for res in pool.imap_unordered(work, ranges):
            for X,pad,pt in res:
                print(f"HIT L={L} X={X} pad={pad}")
                print("  PT:", pt)
                try: print("  FLAG:", pt[:-pad].decode())
                except: print("  body:", pt[:-pad])
    print(f"L={L} [{lo},{hi}) done")
