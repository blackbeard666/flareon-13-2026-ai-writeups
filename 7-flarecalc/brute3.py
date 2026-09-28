import hashlib, struct, time, sys
from unpack import unpack, MAP
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
md=Cs(CS_ARCH_X86,CS_MODE_64)
TIGHT=set([0x48,0x40,0x4c,0x53,0x55,0x56,0x57,0x4d,0x41])
k3829=struct.pack("<I",3829); b3829=MAP[3829][0]
def fold(m):
    b=0
    for x in m: b=(b*0x1f+x)&0xff
    return b
def out0_3829(inp):
    m=hashlib.md5(inp+k3829).digest(); b=fold(m); return b3829^((b*0x6d+0x39)&0xff)
def full(code):
    off=0
    while off<len(code):
        g=list(md.disasm(code[off:],0,count=1))
        if not g: return False
        off+=g[0].size
    return True
def verify(inp):
    return full(unpack(3829,inp)) and full(unpack(3827,inp)) and full(unpack(3824,inp))
L=int(sys.argv[1]) if len(sys.argv)>1 else 256
t=time.time(); tried=0; hits=[]
for a in range(L):
    for b in range(L):
        for c in range(L):
            inp=("%d-%d-%d"%(a,b,c)).encode(); tried+=1
            if out0_3829(inp) not in TIGHT: continue
            if verify(inp):
                print("*** HIT",inp,flush=True); hits.append(inp)
    if a%16==0: print("a=%d tried=%d %.0fs hits=%d"%(a,tried,time.time()-t,len(hits)),flush=True)
print("DONE",hits)
