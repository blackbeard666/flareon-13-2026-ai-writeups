import struct
def bb(x):
    b=b'';
    while x: b+=bytes([x&0xff]);x>>=8
    return b
def lp(b): return struct.pack('<I',len(b))+b
def leaf(): return b'\x00'
def node(children,A,B):
    return b'\x01'+struct.pack('<I',len(children))+b''.join(lp(c) for c in children)+lp(bb(A))+lp(bb(B))
