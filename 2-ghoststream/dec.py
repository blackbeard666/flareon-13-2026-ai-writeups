import struct
def blob(dwords, tail=b'', n=None):
    b=b''.join(struct.pack('<I',d) for d in dwords)+tail
    return b[:n] if n else b
def dec(b, name='GhostStream.exe'):
    k=ord(name[len(name)//2])^ord(name[0])
    s=sum(b)&0xff
    s=s-256 if s>127 else s
    mode={0x1c:0,-0x1b:0,0x24:2,0x62:2,-0x1f:2,0x53:1,0x60:1,0x6a:1,0x74:1,0x7b:1}.get(s,4)
    o=bytearray()
    for c in b:
        if mode==0: o.append((c-k)&0xff)
        elif mode==1: o.append(((c+1)&0xff)^k)
        elif mode==2: o.append((c-2+k)&0xff)
        else: break
    return mode,bytes(o)
S={
 'kernel32 fn A (0xf)': blob([0x85a99a7c,0x9a98a4a7,0x9e89a8a8,0xa89aa2],n=0xf),
 'kernel32 fn B (0x17)': blob([0x20413214,0x32414046,0x3a36213a,0x13400e32,0x21323936],struct.pack('<H',0x3a36)+b'\x32',0x17),
 'potion/path? local_680 (0x23)': blob([0x3c1d40f2,0x42374639,0x1d323036,0x3c36413c,0x4541fb3b,0x3c190741,0x3c23313f,0x3a323139],struct.pack('<H',0x3f3c)+b'\x41',0x23),
 'user32 after GetConsoleWindow (0xd)': blob([0x5a4f4479,0x445b5875,0x46535956,0x50],n=0xd),
 'ntdll fn (0x16)': blob([0x4f65407a,0x525a7b40,0x53574659,0x5a595b40,0x4f465c60],struct.pack('<H',0x5053),0x16),
 'user32 RegisterClass? (0x10)': blob([0x5b514f66,0x464f4045,0x45535875,0x734c6f45],n=0x10),
 'user32 CreateWindow? (0xf)': blob([0x969aa778,0x9e8c9aa9,0xaca499a3,0x76ad7a],n=0xf),
 'pipe/file name (0x17)': blob([0x29fb2929,0x323d363d,0x2e391329,0x3510323f,0x3239392e],struct.pack('<H',0x343b)+b'\x32',0x17),
 'kernel32 CreateFile? (0x10)': blob([0x534f4675,0x537a4f40,0x64504f57,0x734f445b],n=0x10),
 'kernel32 Connect? (0x10)': blob([0x5a5a5975,0x7a40554f,0x504f5753,0x4f445b64],n=0x10),
}
for name in ['GhostStream.exe']:
  for k,v in S.items(): print(k, dec(v,name), 'sum',sum(v)&0xff)
