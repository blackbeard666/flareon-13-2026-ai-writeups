import hashlib, pickle, struct, sys

MAP = {k:v for k,v in pickle.load(open("map_entries.pkl","rb"))}

def deinterleave(buf, inp_bytes):
    # seed
    s = 0x2437
    for c in inp_bytes:
        c = c - 256 if c >= 128 else c   # signed char
        s = (s*0x81 + c) & 0xffffffff
    state = s
    def nxt():
        nonlocal state
        state = (state*1103515245 + 12345) & 0xffffffff
        return state
    out = bytearray()
    i = 0
    n = len(buf)
    while i < n:
        out.append(buf[i])
        skip = (nxt() % 3) + 1
        for _ in range(skip):
            nxt()
        i += 1 + skip
    return bytes(out)

def xor_decrypt(buf, key16):
    b = 0
    for k in key16:
        b = (b*0x1f + k) & 0xff
    out = bytearray(buf)
    for i in range(len(out)):
        b = (b*0x6d + 0x39) & 0xff
        out[i] ^= b
    return bytes(out)

def unpack(blobkey, input_str):
    """Reproduce FUN_14000a21c: lookup -> xor_decrypt(MD5(input||key)) -> deinterleave(prng(input))."""
    blob = MAP[blobkey]
    inp = input_str.encode() if isinstance(input_str,str) else input_str
    key16 = hashlib.md5(inp + struct.pack("<I", blobkey)).digest()
    dec = xor_decrypt(blob, key16)
    code = deinterleave(dec, inp)
    return code

if __name__ == "__main__":
    key = int(sys.argv[1]) if len(sys.argv)>1 else 3822
    inp = sys.argv[2] if len(sys.argv)>2 else "1-2-3"
    c = unpack(key, inp)
    print("blob %d, input %r: stored=%d -> code=%d bytes"%(key,inp,len(MAP[key]),len(c)))
    print(c[:64].hex())
