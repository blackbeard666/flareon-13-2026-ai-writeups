import struct, zlib, sys
d=open('flareon13.doc','rb').read()
o=0x1c4e3f
(sig,ver,flag,meth,mt,md,crc,csz,usz,nl,xl)=struct.unpack('<IHHHHHIIIHH',d[o:o+30])
name=d[o+30:o+30+nl]; data=d[o+30+nl+xl:o+30+nl+xl+csz]
print(name,hex(flag),meth,hex(mt),hex(crc),csz,usz)
def crc32b(c,b): return zlib.crc32(bytes([b]),c^0xffffffff)^0xffffffff
def zdec(pw,data):
    k=[0x12345678,0x23456789,0x34567890]
    def upd(c):
        k[0]=(zlib.crc32(bytes([c]),k[0]^0xffffffff)^0xffffffff)
        k[1]=((k[1]+(k[0]&0xff))*134775813+1)&0xffffffff
        k[2]=(zlib.crc32(bytes([k[1]>>24]),k[2]^0xffffffff)^0xffffffff)
    for c in pw: upd(c)
    out=bytearray()
    for c in data:
        t=(k[2]|2)&0xffff; p=c^(((t*(t^1))>>8)&0xff); upd(p); out.append(p)
    return bytes(out)
if __name__=='__main__':
    pw=sys.argv[1].encode()
    pt=zdec(pw,data)
    chk=(mt>>8) if flag&8 else (crc>>24)
    print('check byte',hex(pt[11]),'expect',hex(chk),'crc>>24',hex(crc>>24),'time>>8',hex(mt>>8))
    open('flag_reduced.bin','wb').write(pt[12:])
