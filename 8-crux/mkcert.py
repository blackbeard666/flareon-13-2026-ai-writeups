import sys,struct,sympy
def u32(n):return struct.pack('<I',n)
def bLE(n):
 n=abs(int(n));b=bytearray()
 while n>0:b.append(n&255);n>>=8
 return bytes(b)
def node(ch,k,v):
 kb=bLE(k);vb=bLE(v);p=bytearray([1]);p+=u32(len(ch))
 for c in ch:p+=u32(len(c));p+=c
 p+=u32(len(kb));p+=kb;p+=u32(len(vb));p+=vb;return bytes(p)
memo={}
def cert(p,mode='mult'):
    p=int(p)
    if p==2: return node([],2,0)
    g=int(sympy.primitive_root(p))
    fd=sympy.factorint(p-1)
    if mode=='distinct':
        facs=sorted(fd)
    else:
        facs=[]
        for q in sorted(fd): facs+=[q]*fd[q]
    ch=[cert(q,mode) for q in facs]
    return node(ch,p,g)
p=int(sys.argv[1]); mode=sys.argv[2] if len(sys.argv)>2 else 'mult'
sys.stdout.write(cert(p,mode).hex())
