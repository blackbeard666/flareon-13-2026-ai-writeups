import sys

def rc4ks(key,n):
    S=list(range(256)); j=0
    for i in range(256): j=(j+S[i]+key[i%len(key)])&255; S[i],S[j]=S[j],S[i]
    i=j=0; out=bytearray()
    for _ in range(n):
        i=(i+1)&255; j=(j+S[i])&255; S[i],S[j]=S[j],S[i]; out.append(S[(S[i]+S[j])&255])
    return bytes(out)
KEY=b'i11_b3_p1und3r1n_y3r_d474'

def decrypt(fn):
    d=open(fn,'rb').read(); ks=rc4ks(KEY,len(d)); return bytes(d[i]^ks[i] for i in range(len(d)))

def parse_lengths(pt):
    # table integer = pt[1:262] (byte0=magic 0x20). value = 32 * base256(len_0..len_255)
    T=int.from_bytes(pt[1:262],'big')
    L=T>>5
    lb=L.to_bytes(261,'big')
    lengths=[lb[s+5] for s in range(256)]  # pt byte 6+s -> index s+5 in 261-array
    return lengths

def canonical_codes(lengths):
    # standard canonical huffman: order by (length, symbol)
    syms=[(lengths[s],s) for s in range(256) if lengths[s]>0]
    syms.sort()
    codes={}
    code=0; prev_len=0
    for (l,s) in syms:
        code <<= (l-prev_len)
        codes[s]=(code,l)
        code+=1
        prev_len=l
    return codes

def decode_data(pt, lengths, out_len):
    codes=canonical_codes(lengths)
    # build lookup: (len,code)->sym
    lut={}
    for s,(c,l) in codes.items(): lut[(l,c)]=s
    data=pt[262:]
    bits=[]
    # MSB-first bit iterator
    out=bytearray()
    acc=0; nb=0
    bitpos=0
    total_bits=len(data)*8
    cur=0; curlen=0
    while len(out)<out_len and bitpos<total_bits:
        byte=data[bitpos>>3]
        bit=(byte>>(7-(bitpos&7)))&1
        bitpos+=1
        cur=(cur<<1)|bit; curlen+=1
        if (curlen,cur) in lut:
            out.append(lut[(curlen,cur)])
            cur=0; curlen=0
    return bytes(out)

if __name__=='__main__':
    fn=sys.argv[1]; out_len=int(sys.argv[2]); outfn=sys.argv[3] if len(sys.argv)>3 else None
    pt=decrypt(fn)
    lengths=parse_lengths(pt)
    nz={s:lengths[s] for s in range(256) if lengths[s]}
    print('nonzero lengths (%d symbols): '%len(nz), dict(list(nz.items())[:20]),'...' if len(nz)>20 else '')
    res=decode_data(pt,lengths,out_len)
    print('decoded %d bytes; head=%s'%(len(res), res[:16].hex()))
    if outfn:
        open(outfn,'wb').write(res); print('wrote',outfn)
