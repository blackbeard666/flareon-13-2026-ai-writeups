import struct
sbox=bytes.fromhex('637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16')
invsbox=bytearray(256)
for i,v in enumerate(sbox): invsbox[v]=i
def xt(a):
    a<<=1
    return (a^0x11b)&0xff if a&0x100 else a
def mul(a,b):
    r=0
    for _ in range(8):
        if b&1:r^=a
        a=xt(a);b>>=1
    return r
def _rounds_enc(state,xk):
    s=list(struct.unpack('>4I',state)); s=[s[i]^xk[i] for i in range(4)]
    for rnd in range(1,14):
        b=b''.join(struct.pack('>I',x) for x in s)
        sub=[sbox[b[i]] for i in range(16)]
        ns=[0]*16
        for c in range(4):
            for r in range(4): ns[4*c+r]=sub[4*((c+r)%4)+r]
        out=[0]*16
        for c in range(4):
            a0,a1,a2,a3=ns[4*c:4*c+4]
            out[4*c+0]=mul(a0,2)^mul(a1,3)^a2^a3
            out[4*c+1]=a0^mul(a1,2)^mul(a2,3)^a3
            out[4*c+2]=a0^a1^mul(a2,2)^mul(a3,3)
            out[4*c+3]=mul(a0,3)^a1^a2^mul(a3,2)
        s=list(struct.unpack('>4I',bytes(out))); s=[s[i]^xk[4*rnd+i] for i in range(4)]
    b=b''.join(struct.pack('>I',x) for x in s)
    sub=[sbox[b[i]] for i in range(16)]
    ns=[0]*16
    for c in range(4):
        for r in range(4): ns[4*c+r]=sub[4*((c+r)%4)+r]
    s=list(struct.unpack('>4I',bytes(ns))); s=[s[i]^xk[56+i] for i in range(4)]
    return b''.join(struct.pack('>I',x) for x in s)
def enc_words(pt,xk): return _rounds_enc(pt,xk)
Rcon=[0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36]
def _sw(w): return (sbox[(w>>24)&0xff]<<24)|(sbox[(w>>16)&0xff]<<16)|(sbox[(w>>8)&0xff]<<8)|sbox[w&0xff]
def _rw(w): return ((w<<8)|(w>>24))&0xffffffff
def expand(key):
    w=[struct.unpack('>I',key[4*i:4*i+4])[0] for i in range(8)]
    for i in range(8,60):
        t=w[i-1]
        if i%8==0: t=_sw(_rw(t))^(Rcon[i//8-1]<<24)
        elif i%8==4: t=_sw(t)
        w.append(t^w[i-8])
    return w
