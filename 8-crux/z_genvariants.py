import sys, sympy, struct, functools

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

P=95681613235744740119807961018865688051340183696570761153419351987106658443873

def build(leafval):
    memo={}
    def cert(p):
        p=int(p)
        if p in memo: return memo[p]
        if p==2:
            r=node([],2,leafval); memo[p]=r; return r
        g=int(sympy.primitive_root(p))
        fd=sympy.factorint(p-1); facs=[]
        for q in sorted(fd): facs+=[q]*fd[q]
        ch=[cert(q) for q in facs]
        r=node(ch,p,g); memo[p]=r; return r
    return cert(P)

with open('z_variants.txt','w') as f:
    for lv in range(256):
        c=build(lv)
        f.write("%d %s\n"%(lv, c.hex()))
print("done, cert len (lv0) =", len(build(0)))
