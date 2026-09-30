import struct, sys
def u32(n): return struct.pack('<I', n)
def int_le(n):
    if n==0: return b''
    o=bytearray()
    while n: o.append(n&0xff); n>>=8
    return bytes(o)
class N:
    def __init__(self,children=None,key=0,val=0):
        self.c=children or []; self.k=int_le(key); self.v=int_le(val)
    def ser(self):
        o=bytearray([1]); o+=u32(len(self.c))
        for c in self.c:
            cb=c.ser(); o+=u32(len(cb)); o+=cb
        o+=u32(len(self.k)); o+=self.k
        o+=u32(len(self.v)); o+=self.v
        return bytes(o)
def pad_to(node, target):
    # try to make total length == target by padding the root value with high bytes
    b=node.ser()
    if len(b)==target: return b
    return None

# Emit a labeled set of candidate trees (must be 32..47 bytes)
cands=[]
# single node, key=k, val=v with enough value bytes to hit length 32
def single(key,val_bytes):
    n=N(key=0); n.k=int_le(key); n.v=val_bytes
    return n.ser()
# helpers to hit exact length: root single node, key=key, val = filler
def single_len(L, key=0):
    # 1 + 4(child=0) + 4(keylen)+klen + 4(vallen)+vlen == L
    kb=int_le(key)
    vlen = L - (1+4+4+len(kb)+4)
    if vlen<0: return None
    vb = (b'\x01'*(vlen-1)+b'\x01') if vlen>0 else b''
    if vlen>0: vb=b'\x01'*vlen  # canonical (last byte 0x01 !=0)
    o=bytearray([1]); o+=u32(0); o+=u32(len(kb)); o+=kb; o+=u32(len(vb)); o+=vb
    return bytes(o)

if __name__=='__main__':
    which=sys.argv[1] if len(sys.argv)>1 else 'basic'
    out=[]
    if which=='basic':
        for L in [32,33,34,40,47]:
            b=single_len(L,0)
            if b: out.append(("single L%d key0"%L, b))
        for key in [1,2,10,255,256,65536]:
            b=single_len(32,key)
            if b: out.append(("single L32 key%d"%key, b))
    print(len(out))
    for name,b in out:
        print(name+"\t"+b.hex())
