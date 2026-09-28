from unicorn import *
from unicorn.x86_const import *
import pefile, struct
pe=pefile.PE('ToxicMiner.exe'); ib=pe.OPTIONAL_HEADER.ImageBase
size=pe.OPTIONAL_HEADER.SizeOfImage
mu=Uc(UC_ARCH_X86,UC_MODE_64)
mu.mem_map(ib,(size+0xfff)&~0xfff)
mu.mem_write(ib,pe.get_memory_mapped_image(ImageBase=ib))
STK=0x10000000; mu.mem_map(STK,0x200000)
IV=[0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19]
def compress_emu(Hwords, Wwords, third):
    sp=STK+0x100000; state=STK+0x120000; block=STK+0x140000
    mu.mem_write(state, b''.join(struct.pack('<I',x) for x in Hwords))
    mu.mem_write(block, b''.join(struct.pack('<I',x) for x in Wwords))
    mu.reg_write(UC_X86_REG_RSP,sp)
    mu.reg_write(UC_X86_REG_RCX,state); mu.reg_write(UC_X86_REG_RDX,block); mu.reg_write(UC_X86_REG_R8,third)
    RET=0x5000000; mu.mem_write(sp,struct.pack('<Q',RET))
    mu.emu_start(0x140135240,RET)
    return list(struct.unpack('<8I', mu.mem_read(state,32)))
W=[0x11111111,0x22222222]+[0]*13+[0x40]
out=compress_emu(IV[:],W,0)
print('emu   ',[ '%08x'%x for x in out])
# my python
K=[0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2]
M=0xffffffff; r=lambda x,n:((x>>n)|(x<<(32-n)))&M
def comp(H,Win):
  w=list(Win)
  for i in range(16,64): w.append((w[i-16]+(r(w[i-15],7)^r(w[i-15],18)^(w[i-15]>>3))+w[i-7]+(r(w[i-2],17)^r(w[i-2],19)^(w[i-2]>>10)))&M)
  a,b,c,d,e,f,g,h=H
  for i in range(64):
    t1=(h+(r(e,6)^r(e,11)^r(e,25))+((e&f)^(~e&g))+K[i]+w[i])&M
    t2=((r(a,2)^r(a,13)^r(a,22))+((a&b)^(a&c)^(b&c)))&M
    h,g,f,e,d,c,b,a=g,f,e,(d+t1)&M,c,b,a,(t1+t2)&M
  return [(x+y)&M for x,y in zip(H,[a,b,c,d,e,f,g,h])]
print('mine  ',[ '%08x'%x for x in comp(IV[:],W)])

# dump several vectors for the search
import json
vecs=[]
tests=[[0x11111111,0x22222222]+[0]*13+[0x40],
       [1]+[0]*15,
       [0]*15+[0x40],
       list(range(16)),
       [0xdeadbeef,0x0b501e7e,0x80000000]+[0]*12+[0x40]]
for W in tests:
    vecs.append([W, compress_emu(IV[:],W,0)])
open('vecs.json','w').write(json.dumps(vecs))
print('wrote',len(vecs),'vectors')
