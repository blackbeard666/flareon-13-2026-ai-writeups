import struct
# crux (FLARE-On) message grammar for func3267 parser.
# subtree := 0x01
#          || u32le(childCount)
#          || ( u32le(childByteLen) || <subtree bytes> ) * childCount
#          || u32le(keyLen)  || key[keyLen]      # key   = canonical little-endian big-integer
#          || u32le(valLen)  || val[valLen]      # value = canonical little-endian big-integer
# canonical little-endian int: empty => 0; if non-empty the LAST byte must be != 0 (no trailing zero bytes).
# The whole 32..47-byte message must be exactly ONE subtree, consuming all bytes.

def u32(n): return struct.pack('<I', n)

def int_le(n):
    """canonical little-endian bytes of non-negative int n (0 -> b'')."""
    if n == 0: return b''
    out=bytearray()
    while n:
        out.append(n & 0xff); n >>= 8
    return bytes(out)  # last byte is the most-significant, always != 0 -> canonical

class Node:
    def __init__(self, children=None, key=0, val=0, key_bytes=None, val_bytes=None):
        self.children = children or []
        self.key_bytes = key_bytes if key_bytes is not None else int_le(key)
        self.val_bytes = val_bytes if val_bytes is not None else int_le(val)
    def serialize(self):
        out = bytearray()
        out.append(0x01)
        out += u32(len(self.children))
        for c in self.children:
            cb = c.serialize()
            out += u32(len(cb))
            out += cb
        out += u32(len(self.key_bytes)); out += self.key_bytes
        out += u32(len(self.val_bytes)); out += self.val_bytes
        return bytes(out)

if __name__ == '__main__':
    # example that reaches func3269 (verified): single node, key=0, value=19 bytes of 0x01
    n = Node(children=[], val_bytes=b'\x01'*19)
    m = n.serialize()
    print("len", len(m), "hex", m.hex())
    # a nested example
    child = Node(children=[], key=0, val=5)
    root = Node(children=[child], key=0, val_bytes=b'\x01\x02\x03')
    mr = root.serialize()
    print("nested len", len(mr), "hex", mr.hex())
