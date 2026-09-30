# Add a function returning global 0, exported as "g0", to main_instr.wasm
import struct
IN="main_instr.wasm"; OUT="main_g0.wasm"
d=open(IN,'rb').read()
def u(b,o):
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s
        if not(x&0x80):break
        s+=7
    return r,o
def eu(v):
    out=bytearray()
    while True:
        x=v&0x7f;v>>=7
        if v:out.append(x|0x80)
        else:out.append(x);break
    return bytes(out)
o=8;secs=[]
while o<len(d):
    sid=d[o];o+=1;sz,o=u(d,o);secs.append([sid,bytearray(d[o:o+sz])]);o+=sz
def get(i):
    for s in secs:
        if s[0]==i:return s
    return None
# count imported funcs
imp=get(2);o=0;n,o=u(imp[1],o);nif=0
for _ in range(n):
    ml,o=u(imp[1],o);o+=ml;nl,o=u(imp[1],o);o+=nl;k=imp[1][o];o+=1
    if k==0: _,o=u(imp[1],o);nif+=1
    elif k==1:o+=1;fl=imp[1][o];o+=1;_,o=u(imp[1],o); 
    elif k==2:fl=imp[1][o];o+=1;_,o=u(imp[1],o)
    elif k==3:o+=2
# types: add (result i32) type
ts=get(1);o=0;nt,o=u(ts[1],o); tl=[]
p=o
for _ in range(nt):
    assert ts[1][p]==0x60;p+=1
    pc,p=u(ts[1],p);params=list(ts[1][p:p+pc]);p+=pc
    rc,p=u(ts[1],p);res=list(ts[1][p:p+rc]);p+=rc
    tl.append((params,res))
ti=None
for i,(pa,re) in enumerate(tl):
    if pa==[] and re==[0x7f]: ti=i;break
if ti is None:
    ti=nt
    ts[1]=bytearray(eu(nt+1))+ts[1][len(eu(nt)):]+b'\x60'+eu(0)+eu(1)+b'\x7f'
# func section: count defined
fs=get(3);o=0;nd,o=u(fs[1],o)
newfuncidx=nif+nd  # absolute index of new function
fs[1]=bytearray(eu(nd+1))+fs[1][len(eu(nd)):]+eu(ti)
# code section: add body: locals=0; global.get 0; end
cs=get(10);o=0;nc,o=u(cs[1],o)
body=b'\x00'+b'\x23\x00'+b'\x0b'  # 0 locals, global.get 0, end
cs[1]=bytearray(eu(nc+1))+cs[1][len(eu(nc)):]+eu(len(body))+body
# export section: add g0
es=get(7);o=0;ne,o=u(es[1],o)
es[1]=bytearray(eu(ne+1))+es[1][len(eu(ne)):]+eu(2)+b'g0'+b'\x00'+eu(newfuncidx)
out=bytearray(d[:8])
for sid,pl in secs: out+=bytes([sid])+eu(len(pl))+pl
open(OUT,'wb').write(out)
print("wrote",OUT,"g0 idx",newfuncidx)
