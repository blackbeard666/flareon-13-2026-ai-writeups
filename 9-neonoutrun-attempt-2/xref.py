import sys,re,struct
from capstone import *
d=open('neon_outrun','rb').read()
TO,TV,TS=0x4c1ac0,0x4c2ac0,0xef0310
t=d[TO:TO+TS]
targets=[int(x,16) for x in sys.argv[1:]]
# brute: for every position, treat 4 bytes as disp32 of rip-relative with instr end at pos+4+k (k=0..1 for imm)
res={x:[] for x in targets}
for pos in range(0,len(t)-4):
    disp=struct.unpack_from('<i',t,pos)[0]
    for k in (0,1,4):
        a=TV+pos+4+k+disp
        if a in res: res[a].append(TV+pos)
md=Cs(CS_ARCH_X86,CS_MODE_64)
for a,l in res.items():
    print('==',hex(a))
    for p in l:
        for back in range(2,8):
            ins=next(md.disasm(t[p-back-TV+TV-TV+ (p-TV) - (p-TV) + 0:0],0),None) if False else None
            s=p-back
            i=next(md.disasm(d[s-TV+TO:s-TV+TO+16],s),None)
            if i and i.address+i.size in (p+4,p+5,p+8) and 'rip' in i.op_str:
                print(hex(i.address),i.mnemonic,i.op_str); break
