import hashlib, struct, sys
SEED=1116755918
inv129=pow(129,-1,2**32); M=(1<<32)-1
def hstr(s,txt):
    for ch in txt: s=(s*129+ord(ch))&M
    return s
def peel(s,txt):
    for ch in reversed(txt): s=((s-ord(ch))*inv129)&M
    return s
FOLDS={3829:190,3827:90,3824:116,3822:146}
def check(inp):
    for k,fv in FOLDS.items():
        md=hashlib.md5(inp+struct.pack("<I",k)).digest()
        f=0
        for x in md: f=(f*0x1f+x)&0xff
        if f!=fv: return False
    return True
RA=RB=int(sys.argv[1]) if len(sys.argv)>1 else 5000
RC=int(sys.argv[2]) if len(sys.argv)>2 else (1<<26)
fwd={}
for A in range(RA):
    sA=hstr(0x2437,"%d-"%A)
    for B in range(RB):
        fwd[hstr(sA,"%d-"%B)]=(A,B)
print("fwd",len(fwd),flush=True)
hits=0
for C in range(RC):
    ab=fwd.get(peel(SEED,"%d"%C))
    if ab is not None:
        hits+=1
        s=("%d-%d-%d"%(ab[0],ab[1],C)).encode()
        if check(s):
            print("*** REAL INPUT:",s.decode(),flush=True)
    if (C&0x3FFFFF)==0: print("C=%d hits=%d"%(C,hits),flush=True)
print("done hits",hits)
