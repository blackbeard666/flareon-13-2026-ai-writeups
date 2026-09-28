import zlib
exec(open('zipr.py').read().split("if __name__")[0])
def unreduce(buf, usz, factor=1):
    bitpos=0
    def bits(n):
        nonlocal bitpos
        v=0
        for i in range(n):
            byte=buf[bitpos>>3] if (bitpos>>3)<len(buf) else 0
            v|=((byte>>(bitpos&7))&1)<<i; bitpos+=1
        return v
    S=[None]*256
    for j in range(255,-1,-1):
        n=bits(6); S[j]=[bits(8) for _ in range(n)]
    def B(n): return max(1,(n-1).bit_length()) if n>0 else 0
    out=bytearray(); last=0; state=0; V=Ln=0
    Lmask=(0x7f,0x3f,0x1f,0x0f)[factor-1]
    while len(out)<usz:
        if not S[last]: c=bits(8)
        elif bits(1): c=bits(8)
        else: c=S[last][bits(B(len(S[last])))]
        last=c
        if state==0:
            if c!=144: out.append(c)
            else: state=1
        elif state==1:
            if c: V=c; Ln=V&Lmask; state=2 if Ln==Lmask else 3
            else: out.append(144); state=0
        elif state==2: Ln+=c; state=3
        elif state==3:
            dist=((V>>(8-factor))*256+c)+1
            for _ in range(Ln+3):
                out.append(out[-dist] if dist<=len(out) else 0)
            state=0
    return bytes(out[:usz])
pt=zdec(b'infected',data)[12:]
r=unreduce(pt,usz)
print(r, hex(zlib.crc32(r)), 'expect', hex(crc))
