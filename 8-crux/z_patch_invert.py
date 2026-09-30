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
        b=v&0x7f;v>>=7
        if v:out.append(b|0x80)
        else:out.append(b);break
    return bytes(out)
data=bytearray(open("main.wasm","rb").read())
o=8;secs=[]
while o<len(data):
    sid=data[o];o+=1;sz,o=u(data,o);secs.append([sid,o,sz]);o+=sz
NIMP=None
for sid,so,sz in secs:
    if sid==2:
        pl=data[so:so+sz];p=0;n,p=u(pl,0);f=0
        for _ in range(n):
            ml,p=u(pl,p);p+=ml;nl,p=u(pl,p);p+=nl;k=pl[p];p+=1
            if k==0:ti,p=u(pl,p);f+=1
            elif k==1:p+=1;fl=pl[p];p+=1;mn,p=u(pl,p)
            elif k==2:
                fl=pl[p];p+=1;mn,p=u(pl,p)
                if fl:mx,p=u(pl,p)
            elif k==3:p+=2
        NIMP=f
    if sid==10:codeso=so;codesz=sz
print("NIMP",NIMP)
pl=data[codeso:codeso+codesz];o=0;nf,o=u(pl,0);bodies=[]
for i in range(nf):
    bsz,o=u(pl,o);bodies.append((o,bsz));o+=bsz
tb=3270-NIMP
bs,bz=bodies[tb]
# code offset within body: parse locals
p=0;nl,p=u(pl,bs)  # wait need offset relative to bs
# recompute: body starts at bs (abs in pl)
q=bs;nl,q=u(pl,q)
for _ in range(nl):
    c,q=u(pl,q);vt=pl[q];q+=1
codestart=q  # abs offset in pl of code start
# disasm offset 0x60af corresponds to codestart+0x60af
target=bs+0x60af
absfile=codeso+target
print("byte at disasm 0x60af (abs file 0x%x) = 0x%02x (expect 0x45 i32.eqz)"%(absfile,data[absfile]))
# context
print("context:",data[absfile-4:absfile+4].hex())
assert data[absfile]==0x45, "not i32.eqz!"
data[absfile]=0x01  # nop
open("main_flagpath.wasm","wb").write(data)
print("wrote main_flagpath.wasm (60af i32.eqz -> nop, inverts gate)")
