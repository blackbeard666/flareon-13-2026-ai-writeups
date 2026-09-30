import struct
FN=open("main_instr2.wasm","rb").read()
data=bytearray(FN)
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
    elif k==1: o+=1; fl=pl[o];o+=1; mn,o=u(pl,o);
    elif k==2:
        fl=pl[o];o+=1; mn,o=u(pl,o)
        if fl: mx,o=u(pl,o)
    elif k==3: o+=1; o+=1
NIMP=fidx
print("nimp_func",NIMP,"trace_idx",trace_idx)
code=getsec(10); cpl=code[3]; o=0; nf,o=u(cpl,0); bodies=[]
for i in range(nf):
    bsz,o=u(cpl,o); bodies.append((o,bsz)); o+=bsz
tb=3271-NIMP
bstart,bsz=bodies[tb]; body=bytearray(cpl[bstart:bstart+bsz])
# parse locals header
p=0; nl,p=u(body,p); hdr_start=0
groups=[]
for _ in range(nl):
    st=p; cnt,p=u(body,p); vt=body[p];p+=1; groups.append((cnt,vt))
locals_end=p
print("local groups:",groups)
# add one i64 local. i64 valtype=0x7e
# rebuild locals header with an extra group (1, 0x7e)
newhdr=bytearray()
newhdr+=enc_u(nl+1)
for cnt,vt in groups:
    newhdr+=enc_u(cnt)+bytes([vt])
newhdr+=enc_u(1)+bytes([0x7e])
# total locals count = sum cnt. new local index = NIMP-independent: locals are indexed after params.
# params: func type params. Need param count to know new local index.
# func3270 type params=[127] -> 1 param. locals: sum of group counts. existing = 1(i32)+16(i64)=17 locals -> indices 1..17 (0=param). new local index = 1(params)+17 = 18.
NEWLOC=1+sum(c for c,_ in groups)
print("new local index",NEWLOC)
codebytes=body[locals_end:]
# find 6dcf pattern: local.get 1(20 01); i64.extend_i32_u(ad); i64.const 56(42 38); i64.add(7c); i32.wrap_i64(a7); i64.load off=0 (29 ?? ??)
pat=bytes([0x20,0x01,0xad,0x42,0x38,0x7c,0xa7,0x29])
idx=codebytes.rfind(pat)   # 0x6dcf check is the last occurrence (~0x6dd1)
print("pattern at 0x%x"%idx)
if idx<0: raise SystemExit("not found")
# the load: 0x29 align(u) offset(u). parse length
q=idx+len(pat)
al,q=u(codebytes,q); off,q=u(codebytes,q)
print("load align",al,"off",off,"load ends at",q)
# inject AFTER the load (at q): local.set NEWLOC; i32.const 900002; local.get NEWLOC; i32.wrap; call trace; local.get NEWLOC
inj=b'\x21'+enc_u(NEWLOC)+b'\x41'+enc_s(900002)+b'\x20'+enc_u(NEWLOC)+b'\xa7'+b'\x10'+enc_u(trace_idx)+b'\x20'+enc_u(NEWLOC)
newcode=codebytes[:q]+inj+codebytes[q:]
newbody=bytes(newhdr)+bytes(newcode)
# rebuild code section
newcpl=bytearray(enc_u(nf))
for i in range(nf):
    bs,bz=bodies[i]
    b=cpl[bs:bs+bz]
    if i==tb: b=newbody
    newcpl+=enc_u(len(b))+b
code[3]=newcpl
out=bytearray(data[:8])
for sid,so,sz,pld in secs:
    out+=bytes([sid])+enc_u(len(pld))+pld
open("main_off56.wasm","wb").write(out)
print("wrote main_off56.wasm",len(out))
