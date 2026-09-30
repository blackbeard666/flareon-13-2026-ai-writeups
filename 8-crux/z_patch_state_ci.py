import struct
FN=open("main_instr2_cmpinv.wasm","rb").read()
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
# parse sections
o=8; secs=[]
while o<len(data):
    sid=data[o];o+=1; sz,o=u(data,o); secs.append([sid,o,sz,bytearray(data[o:o+sz])]); o+=sz
def getsec(id):
    for s in secs:
        if s[0]==id: return s
    return None
# parse imports to get func import count and find env.trace index
imp=getsec(2); pl=imp[3]; o=0; n,o=u(pl,0); fidx=0; trace_idx=None
for _ in range(n):
    ml,o=u(pl,o); mod=pl[o:o+ml].decode();o+=ml; nl,o=u(pl,o); nm=pl[o:o+nl].decode();o+=nl
    k=pl[o];o+=1
    if k==0:
        ti,o=u(pl,o)
        if mod=='env' and nm=='trace': trace_idx=fidx
        fidx+=1
    elif k==1:
        o+=1; fl=pl[o];o+=1; mn,o=u(pl,o)
        if fl: mx,o=u(pl,o)
    elif k==2:
        fl=pl[o];o+=1; mn,o=u(pl,o)
        if fl: mx,o=u(pl,o)
    elif k==3:
        o+=1; mut=pl[o];o+=1
NIMP_FUNC=fidx
print("nimp_func=",NIMP_FUNC,"trace import idx=",trace_idx)
# func3270 absolute index -> in main_instr2, defined funcs shifted +1 (trace import added). Original abs 3270 -> new call index 3271, and its position in code section = 3270 - NIMP_FUNC_ORIG. But main_instr2 already renumbered. The code section body index i corresponds to defined func i, whose NEW abs index = NIMP_FUNC + i. Original abs = NIMP_FUNC-1 + i (since one import added). We want original abs 3270 => new abs 3271 => code body index = 3271 - NIMP_FUNC.
code=getsec(10); cpl=code[3]; o=0; nf,o=u(cpl,0)
bodies=[]
for i in range(nf):
    bsz,o=u(cpl,o); bodies.append((o,bsz)); o+=bsz
target_body = 3271 - NIMP_FUNC
print("nf=",nf,"target_body_index=",target_body)
bstart,bsz=bodies[target_body]
body=cpl[bstart:bstart+bsz]
# find dispatch: local.get 0 (0x20 0x00) followed by br_table (0x0e). Search for 0x20 0x00 0x0e
disp=-1
for i in range(len(body)-3):
    if body[i]==0x20 and body[i+1]==0x00 and body[i+2]==0x0e:
        disp=i; break
print("dispatch offset in body:",disp, "hex ctx:", body[disp:disp+6].hex() if disp>=0 else None)
if disp<0: raise SystemExit("dispatch not found")
# injection: before local.get 0 at disp, insert: i32.const 900000; local.get 0; i32.add; local.get 2; i32.wrap_i64; call trace_idx
inj = b'\x41'+enc_s(900000)+b'\x20\x00'+b'\x6a'+b'\x20\x02'+b'\xa7'+b'\x10'+enc_u(trace_idx)
newbody = body[:disp]+inj+body[disp:]
# rebuild code section
newcpl=bytearray(enc_u(nf))
for i in range(nf):
    bs,bz=bodies[i]
    b=cpl[bs:bs+bz]
    if i==target_body: b=newbody
    newcpl+=enc_u(len(b))+b
code[3]=newcpl
# reassemble
out=bytearray(data[:8])
for sid,so,sz,pld in secs:
    out+=bytes([sid])+enc_u(len(pld))+pld
open("main_cmpinv_state.wasm","wb").write(out)
print("wrote main_state.wasm",len(out))
