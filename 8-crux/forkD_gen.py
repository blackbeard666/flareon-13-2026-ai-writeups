import struct, itertools
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
    b=vb if vb is not None else ile(v); o+=u32(len(b))+b
    return bytes(o)
def atom(k=0,v=0,vb=None): return node([],k,v,vb)

cands=[]
# structural shapes with key/value variations
for k1 in [0,1,2,3]:
  for v1 in [0,1,2]:
    # list[atom(k1,v1)]
    m=node([atom(k1,v1)])
    if 32<=len(m)<=47: cands.append(("L[a(%d,%d)]"%(k1,v1),m))
    # list[atom(k1,v1), atom(0,0)]
    m=node([atom(k1,v1),atom()])
    if 32<=len(m)<=47: cands.append(("L[a(%d,%d),a]"%(k1,v1),m))
    # list[list[atom(k1,v1)]]
    m=node([node([atom(k1,v1)])])
    if 32<=len(m)<=47: cands.append(("L[L[a(%d,%d)]]"%(k1,v1),m))
    # atom with key=k1 large value
    m=atom(k1,vb=b'\x01'*max(0,32-13))
    if 32<=len(m)<=47: cands.append(("a(%d,big)"%k1,m))
# node with key/value on the list itself
for k in [0,1,2]:
  for v in [0,1,2]:
    m=node([atom(),atom()],k=k,v=v)
    if 32<=len(m)<=47: cands.append(("L(k%d,v%d)[a,a]"%(k,v),m))
# dedup by hex
seen=set(); out=[]
for name,m in cands:
    if m.hex() in seen: continue
    seen.add(m.hex()); out.append((name,m))
for name,m in out: print("%s\t%s"%(name,m.hex()))
