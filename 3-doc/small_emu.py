import struct
d=open('macho/click_me~.arm64','rb').read()
def va(a,n): return d[a-0x100000000:a-0x100000000+n]
print(va(0x1000012e2,4))
s=bytes(c^0x80 for c in va(0x100001200,0x50)); print('xor80:',s)
q=lambda a: va(a,8)
blk=q(0x100001270)+q(0x100001278)+q(0x100001260)+q(0x100001268)+b'\0'*16+q(0x100001250)+q(0x100001258)
W=list(struct.unpack('<16I',blk))
for i in range(16,80): W.append(W[i-8]^W[i-3]^W[i-14]^W[i-16])
M=0xffffffff; rol=lambda x,n:((x<<n)|(x>>(32-n)))&M
a,b,c,dd,e=0x67452301,0xefcdab89,0x98badcfe,0x10325476,0xc3d2e1f0
for t in range(80):
    r=t//20
    if r==0: f=(dd&~b)|(b&c); K=0x5a827999
    elif r==1: f=b^c^dd; K=0x6ed9eba1
    elif r==2: f=(c|dd)&b|(c&dd); K=0x8f1bbcdc
    else: f=b^c^dd; K=0xca62c1d6
    tmp=(rol(a,5)+e+f+K+W[t])&M
    e,dd,c,b,a=dd,c,rol(b,30),a,tmp
A=(a+0x67452301)&M; B=(b+0xefcdab89)&M; C=(c+0x98badcfe)&M
hx=b'0123456789abcdef'
def nib(x,k): return hx[(x>>(28-4*k))&0xf]
D1=va(0x100001280,8); D2=va(0x100001288,8)
out=bytes(nib(A,k)^D1[k] for k in range(8))+bytes(nib(B,k)^D2[k] for k in range(8))+bytes([nib(C,0)^0x50,nib(C,1)^0x4a,nib(C,2)^7])
print('footer19:',out)
print('hash words',hex(A),hex(B),hex(C))
