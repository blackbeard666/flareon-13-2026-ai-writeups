import struct,sys
def u32(n): return struct.pack('<I',n)
def ile(n):
    if n==0: return b''
    o=bytearray()
    while n: o.append(n&0xff); n>>=8
    return bytes(o)
def node(children,k=0,v=0,vb=None):
    o=bytearray([1]); o+=u32(len(children))
    for c in children: o+=u32(len(c))+c
    kb=ile(k); o+=u32(len(kb))+kb
    vv=vb if vb is not None else ile(v); o+=u32(len(vv))+vv
    return bytes(o)
def atom(k=0,v=0,vb=None): return node([],k,v,vb)
def emit(name,m):
    if m is not None and 32<=len(m)<=47: print("%s\t%s"%(name,m.hex()))
# variants: list[atom(kA,vA), atom(kB,vB)] pad kA value to reach 47
def pad2(kA,kB,vB=1):
    tail=atom(kB,vB)
    for vl in range(0,30):
        h=atom(kA,vb=b'\x01'*vl)
        m=node([h,tail])
        if len(m)==47: return m
        if len(m)>47: break
    return None
which=sys.argv[1] if len(sys.argv)>1 else 'a'
if which=='a':
    for kA in range(0,8):
        for kB in range(0,4):
            emit("l2_kA%d_kB%d"%(kA,kB),pad2(kA,kB))
def genb():
    out=[]
    # v1: list([atom(vb)]) pad atom value to 47
    for vl in range(0,40):
        c=atom(vb=b'\x01'*vl); m=node([c])
        if len(m)==47: out.append(("list[atom(v%d)]"%vl,m)); break
    # v1k: list([atom(vb)]) with list value/key too
    # v2: list([nil,nil])
    out.append(("list[nil,nil]",node([atom(),atom()])))
    # v3: list([list([nil])])
    out.append(("list[list[nil]]",node([node([atom()])])))
    # v4: list([nil], key=K, val=V) sweep
    for K in range(0,6):
        for V in range(0,6):
            m=node([atom()],k=K,v=V)
            # pad by adding value bytes to reach 47
            base=len(m)
            if base<=47:
                # extend val
                need=47-base
                m2=node([atom()],k=K,vb=(ile(V) if V else b'')+b'\x01'*need) if need>0 else m
                out.append(("list1_k%d_v%d"%(K,V),m2))
    # v5: single atom big value with nonzero key
    for K in range(0,8):
        for vl in range(0,40):
            m=atom(K,vb=b'\x01'*vl)
            if len(m)==47: out.append(("atom_k%d_bigv"%K,m)); break
    return out
if __name__=='__main__' and len(sys.argv)>1 and sys.argv[1]=='b':
    for name,m in genb(): emit(name,m)
