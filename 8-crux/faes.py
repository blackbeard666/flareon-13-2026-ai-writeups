import struct
sbox=bytes.fromhex('637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16')
def xt(a):
    a<<=1; return (a^0x11b)&0xff if a&0x100 else a
Te0=[0]*256;Te1=[0]*256;Te2=[0]*256;Te3=[0]*256
for x in range(256):
    s=sbox[x]; s2=xt(s); s3=s2^s
    w=(s2<<24)|(s<<16)|(s<<8)|s3
    Te0[x]=w
    Te1[x]=((w>>8)|(w<<24))&0xffffffffff & 0xffffffff
    Te2[x]=((w>>16)|(w<<16))&0xffffffff
    Te3[x]=((w>>24)|(w<<8))&0xffffffff
def enc(pt, xk):  # xk: list of 60 uint32
    s0=struct.unpack('>I',pt[0:4])[0]^xk[0]
    s1=struct.unpack('>I',pt[4:8])[0]^xk[1]
    s2=struct.unpack('>I',pt[8:12])[0]^xk[2]
    s3=struct.unpack('>I',pt[12:16])[0]^xk[3]
    k=4
    for r in range(13):
        t0=Te0[s0>>24]^Te1[(s1>>16)&0xff]^Te2[(s2>>8)&0xff]^Te3[s3&0xff]^xk[k]
        t1=Te0[s1>>24]^Te1[(s2>>16)&0xff]^Te2[(s3>>8)&0xff]^Te3[s0&0xff]^xk[k+1]
        t2=Te0[s2>>24]^Te1[(s3>>16)&0xff]^Te2[(s0>>8)&0xff]^Te3[s1&0xff]^xk[k+2]
        t3=Te0[s3>>24]^Te1[(s0>>16)&0xff]^Te2[(s1>>8)&0xff]^Te3[s2&0xff]^xk[k+3]
        s0,s1,s2,s3=t0,t1,t2,t3;k+=4
    def fin(a,b,c,d,rk):
        return (((sbox[a>>24]<<24)|(sbox[(b>>16)&0xff]<<16)|(sbox[(c>>8)&0xff]<<8)|sbox[d&0xff])^rk)&0xffffffff
    o0=fin(s0,s1,s2,s3,xk[56]);o1=fin(s1,s2,s3,s0,xk[57]);o2=fin(s2,s3,s0,s1,xk[58]);o3=fin(s3,s0,s1,s2,xk[59])
    return struct.pack('>IIII',o0,o1,o2,o3)
