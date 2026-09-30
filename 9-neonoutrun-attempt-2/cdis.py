import sys,bisect,struct
from capstone import *
d=open('neon_outrun','rb').read()
TO,TV=0x4c1ac0,0x4c2ac0
def load_fdes(h=0x2f708c):
    # .eh_frame_hdr binary search table -> (func_start, size)
    n=struct.unpack_from('<I',d,h+8)[0]; out=[]
    for i in range(n):
        ip,fde=struct.unpack_from('<ii',d,h+12+8*i)
        out.append((ip+h,struct.unpack_from('<I',d,fde+h+12)[0]))
    return sorted(out)
fdes=load_fdes(); starts=[f[0] for f in fdes]
def fn(a):
    i=bisect.bisect_right(starts,a)-1; return fdes[i]
md=Cs(CS_ARCH_X86,CS_MODE_64)
def dis(a):
    s,r=fn(a)
    out=[]
    for i in md.disasm(d[s-TV+TO:s-TV+TO+r],s): out.append(f'{i.address:x}: {i.mnemonic} {i.op_str}')
    return s,r,out
if __name__=='__main__':
    for x in sys.argv[1:]:
        s,r,o=dis(int(x,16)); print(f'==== func {s:x} size {r:x}'); print('\n'.join(o))
