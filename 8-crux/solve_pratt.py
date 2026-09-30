import sys, sympy, struct

def u32(n): return struct.pack('<I', n)
def bLE(n):
    n=abs(int(n)); b=bytearray()
    while n>0: b.append(n&0xff); n>>=8
    return bytes(b)

def node(children, k, v):
    kb=bLE(k); vb=bLE(v)
    p=bytearray([1]); p+=u32(len(children))
    for c in children:
        p+=u32(len(c)); p+=c
    p+=u32(len(kb)); p+=kb; p+=u32(len(vb)); p+=vb
    return bytes(p)

memo={}
def cert(p):
    p=int(p)
    if p in memo: return memo[p]
    if p==2:
        r=node([],2,0)   # axiom leaf
        memo[p]=r; return r
    g=int(sympy.primitive_root(p))
    fd=sympy.factorint(p-1)
    facs=[]
    for q in sorted(fd): facs+=[q]*fd[q]
    ch=[cert(q) for q in facs]
    r=node(ch,p,g)
    memo[p]=r; return r

target=sys.argv[1] if len(sys.argv)>1 else "7"
P=int(target)
c=cert(P)
sys.stderr.write("prime=%d bits=%d len=%d\n"%(P,P.bit_length(),len(c)))
sys.stdout.write(c.hex())
