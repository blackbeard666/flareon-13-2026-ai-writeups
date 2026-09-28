import hashlib, struct, time, sys
from unpack import unpack, MAP, deinterleave, xor_decrypt
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
md=Cs(CS_ARCH_X86,CS_MODE_64)

PROL=set([0x48,0x4c,0x4d,0x40,0x41,0x53,0x55,0x56,0x57,0x50,0x51,0x52,0x54,0x33,0x8b,0x89,0xb8,0xff,0xe8,0xe9])

blobs={k:MAP[k] for k in (3829,3822,3823,3824,3827)}
keys ={k:struct.pack("<I",k) for k in blobs}
b0   ={k:MAP[k][0] for k in blobs}

def fold(m):
    b=0
    for x in m: b=(b*0x1f+x)&0xff
    return b

def out0(inp, k):
    m=hashlib.md5(inp+keys[k]).digest()
    b=fold(m); ks0=(b*0x6d+0x39)&0xff
    return b0[k]^ks0

def full_decode(code):
    off=0
    while off<len(code):
        g=list(md.disasm(code[off:],0,count=1))
        if not g: return False
        off+=g[0].size
    return True

def verify(inp):
    for k in (3829,3827,3824):
        if not full_decode(unpack(k, inp)): return False
    return True

ops={'+':lambda a,b:a+b,'-':lambda a,b:a-b,'*':lambda a,b:a*b,
     '/':lambda a,b:(a//b if b else None),'&':lambda a,b:a&b,'|':lambda a,b:a|b,'^':lambda a,b:a^b}

LIM=int(sys.argv[1]) if len(sys.argv)>1 else 4096
t=time.time(); tried=0; hits=[]
for a in range(0,LIM):
    for b in range(0,LIM):
        for nm,f in ops.items():
            c=f(a,b)
            if c is None or c<0: continue
            inp=("%d-%d-%d"%(a,b,c)).encode()
            tried+=1
            if out0(inp,3829) not in PROL: continue
            if out0(inp,3822) not in PROL: continue
            if out0(inp,3824) not in PROL: continue
            if out0(inp,3827) not in PROL: continue
            if verify(inp):
                print("*** HIT",inp,flush=True); hits.append(inp)
    if a%256==0:
        print("a=%d tried=%d %.0fs hits=%d"%(a,tried,time.time()-t,len(hits)),flush=True)
print("DONE tried=%d hits=%s"%(tried,hits))
