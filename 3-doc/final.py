import hashlib, struct
d=open('macho/click_me~.arm64-3','rb').read()
frags=['FLARE-STANDARD-ANTIVIRUS-TEST-FILE!','mainframe_ebcdic_ghost','jbig2_fax_geometry',
       'udf_tagged_descriptor','reduce_not_deflate','Ød1n_373rn4l_fl4r3']
nib=lambda b:''.join('%x'%(c&0xf) for c in b)
for i,f in enumerate(frags):
    assert hashlib.md5(f.encode()).hexdigest()==nib(d[0x35e30+i*32:0x35e30+i*32+32]), f
key=bytearray(32)
for f in frags:
    for i,c in enumerate(hashlib.sha256(f.encode()).digest()): key[i]^=c
S=list(struct.unpack('<256I',d[0x35f50:0x35f50+1024]))
print('S identity?',S==list(range(256)), S[:8])
ct=d[0x35ef0:0x35f40]
def rc4(S,key,ct):
    S=S[:]; j=0
    for i in range(256):
        j=(j+S[i]+key[i%32])&0xff; S[i],S[j]=S[j],S[i]
    i=j=0; o=bytearray()
    for c in ct:
        i=(i+1)&0xff; j=(j+S[i])&0xff; S[i],S[j]=S[j],S[i]; o.append(S[(S[i]+S[j])&0xff]^c)
    return bytes(o)
print(rc4(S,key,ct))
print(rc4(S,key,bytes.fromhex(nib(ct))))
