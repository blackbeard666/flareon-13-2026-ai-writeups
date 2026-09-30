import struct
data=bytearray(open("main.wasm","rb").read())
def u(b,o):
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s
        if not(x&0x80):break
        s+=7
    return r,o
# parse sections
o=8; secs=[]
while o<len(data):
    sid=data[o];o+=1; sz,o2=u(data,o); start=o2
    secs.append((sid,start,sz)); o=start+sz
# code section id=10
code=[s for s in secs if s[0]==10][0]
o=code[1]; n,o=u(data,o)
# count imported funcs to map index. From wdis: num_imp_funcs=20, so defined func i has code index (i-20).
IMP=20
target_fn=3270
ci=target_fn-IMP
bodies=[]
for fi in range(n):
    bsz,o2=u(data,o); body_start=o2; body_end=o2+bsz
    bodies.append((body_start,body_end)); o=body_end
bstart,bend=bodies[ci]
# The code offsets from wdis are relative to the start of the *expression* (after locals decl).
# wdis prints offsets starting 0005 at 'global.get 0'. Let me find locals header length.
# locals: read count then each (count,valtype)
p=bstart; nl,p=u(data,p)
for _ in range(nl):
    c,p=u(data,p); p+=1  # valtype byte
expr_start=p
print("func3270 body_start=%x expr_start=%x body_end=%x"%(bstart,expr_start,bend))
# wdis offset 0x0005 corresponds to first opcode after some prologue? Actually wdis 0005 = global.get 0.
# In raw, expr_start should be 'global.get 0' (0x23 0x00). Verify:
print("bytes at expr_start:", data[expr_start:expr_start+6].hex())
# The instruction offset in wdis: 0005 for 'global.get 0'. So wdis_off maps to expr_start + (wdis_off-5)?
# Let's find the exact mapping by locating the 3 target bytes 50 ad 50 near expected file offset.
# Target instruction offset 0x4995 (i64.eqz), preceded by load off40. Search for pattern around expr_start+0x4995-5.
approx = expr_start + (0x4995-5)
print("approx file off for 0x4995:", hex(approx), "bytes:", data[approx-4:approx+6].hex())
