import struct
data=bytearray(open("main_instr2.wasm","rb").read())
def u(b,o):
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s
        if not(x&0x80):break
        s+=7
    return r,o
def enc_u(v):
    out=bytearray()
    while True:
        b=v&0x7f; v>>=7
        if v: out.append(b|0x80)
        else: out.append(b); break
    return bytes(out)
def enc_s(v):
    out=bytearray(); more=True
    while more:
        b=v&0x7f; v>>=7
        if (v==0 and not(b&0x40)) or (v==-1 and (b&0x40)): more=False
        else: b|=0x80
        out.append(b)
    return bytes(out)
o=8; secs=[]
while o<len(data):
    sid=data[o];o+=1; sz,o=u(data,o); secs.append([sid,o,sz,bytearray(data[o:o+sz])]); o+=sz
def getsec(id):
    for s in secs:
        if s[0]==id: return s
imp=getsec(2); pl=imp[3]
o=0; n,o=u(pl,0); fidx=0; trace_idx=None
for _ in range(n):
    ml,o=u(pl,o); mod=pl[o:o+ml].decode();o+=ml; nl,o=u(pl,o); nm=pl[o:o+nl].decode();o+=nl
    k=pl[o];o+=1
    if k==0:
        ti,o=u(pl,o)
        if mod=='env' and nm=='trace': trace_idx=fidx
        fidx+=1
    elif k==1: o+=1; fl=pl[o];o+=1; mn,o=u(pl,o)
    elif k==2:
        fl=pl[o];o+=1; mn,o=u(pl,o)
        if fl: mx,o=u(pl,o)
    elif k==3: o+=2
NIMP=fidx
code=getsec(10); cpl=code[3]; o=0; nf,o=u(cpl,0); bodies=[]
for i in range(nf):
    bsz,o=u(cpl,o); bodies.append((o,bsz)); o+=bsz
tb=3271-NIMP   # func3270 in main_instr2 (shifted +1)
bstart,bsz=bodies[tb]; body=bytearray(cpl[bstart:bstart+bsz])
p=0; nl,p=u(body,p); groups=[]
for _ in range(nl):
    cnt,p=u(body,p); vt=body[p];p+=1; groups.append((cnt,vt))
locals_end=p
codebytes=body[locals_end:]
# find local.get 0 ; br_table  => 0x20 0x00 0x0e
pat=bytes([0x20,0x00,0x0e])
idx=codebytes.find(pat)
assert idx>=0, "dispatch not found"
# also ensure unique-ish (the big br_table)
print("dispatch at codebyte 0x%x"%idx)
# injection: local.get0; i32.const 800000; i32.add; i32.const 0; call trace  (logs state+800000)
inj=b'\x20\x00'+b'\x41'+enc_s(800000)+b'\x6a'+b'\x41\x00'+b'\x10'+enc_u(trace_idx)
newcode=codebytes[:idx]+inj+codebytes[idx:]
newbody=bytes(body[:locals_end])+bytes(newcode)
newcpl=bytearray(enc_u(nf))
for i in range(nf):
    bs,bz=bodies[i]; b=cpl[bs:bs+bz]
    if i==tb: b=newbody
    newcpl+=enc_u(len(b))+b
code[3]=newcpl
out=bytearray(data[:8])
for sid,so,sz,pld in secs:
    out+=bytes([sid])+enc_u(len(pld))+pld
open("main_allstates.wasm","wb").write(out)
print("wrote main_allstates.wasm  trace_idx",trace_idx)
