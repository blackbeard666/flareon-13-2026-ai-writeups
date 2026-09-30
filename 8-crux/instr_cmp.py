import struct, sys

INFILE="main.wasm"; OUTFILE="main_cmp.wasm"
# whitelist of ORIGINAL absolute func indices to instrument compares in
WHITELIST=set(int(x) for x in (sys.argv[1:] or ["3270"]))

data=open(INFILE,"rb").read()
def u(b,o):
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s
        if not(x&0x80):break
        s+=7
    return r,o
def slebv(b,o):
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s;s+=7
        if not(x&0x80):
            if x&0x40 and s<64: r|=(-1)<<s
            break
    return r,o
def eu(v):
    out=bytearray()
    while True:
        b=v&0x7f; v>>=7
        if v: out.append(b|0x80)
        else: out.append(b); break
    return bytes(out)
def es(v):
    out=bytearray(); more=True
    while more:
        b=v&0x7f; v>>=7
        if (v==0 and not(b&0x40)) or (v==-1 and (b&0x40)): more=False
        else: b|=0x80
        out.append(b)
    return bytes(out)

# sections
o=8; secs=[]
while o<len(data):
    sid=data[o];o+=1; sz,o=u(data,o); secs.append([sid,bytearray(data[o:o+sz])]); o+=sz
def get(id):
    for s in secs:
        if s[0]==id: return s
    return None

# imports
impsec=get(2)
def parse_imports(pl):
    o=0;n,o=u(pl,o); nf=0
    for _ in range(n):
        ml,o=u(pl,o);o+=ml; nl,o=u(pl,o);o+=nl; k=pl[o];o+=1
        if k==0: ti,o=u(pl,o); nf+=1
        elif k==1: o+=1; fl=pl[o];o+=1; mn,o=u(pl,o); (u(pl,o) if fl else None) and None
        elif k==2: fl=pl[o];o+=1; mn,o=u(pl,o)
        elif k==3: o+=2
    return n,nf
nimp_total,nimp_func=parse_imports(impsec[1])
assert nimp_func==20, nimp_func
NADD_IMP=2
LOG32=nimp_func      # 20
LOG64=nimp_func+1    # 21
SHIFT=NADD_IMP       # defined funcs shift by +2
def ren(x): return x+SHIFT if x>=nimp_func else x

# types
typesec=get(1)
def parse_types(pl):
    o=0;n,o=u(pl,o); tl=[]
    for _ in range(n):
        assert pl[o]==0x60;o+=1
        pc,o=u(pl,o); params=list(pl[o:o+pc]);o+=pc
        rc,o=u(pl,o); results=list(pl[o:o+rc]);o+=rc
        tl.append((params,results))
    return n,tl
ntypes,tlist=parse_types(typesec[1])
def find_or_add_type(params,results):
    global ntypes
    for i,(p,r) in enumerate(tlist):
        if p==params and r==results: return i
    idx=ntypes; tlist.append((params,results)); ntypes+=1
    return idx
T_LOG32=find_or_add_type([0x7f,0x7f,0x7f],[])
T_LOG64=find_or_add_type([0x7f,0x7e,0x7e],[])
T_UN32=find_or_add_type([0x7f],[0x7f])
T_BIN32=find_or_add_type([0x7f,0x7f],[0x7f])
T_UN64=find_or_add_type([0x7e],[0x7f])
T_BIN64=find_or_add_type([0x7e,0x7e],[0x7f])

# func section (defined)
funcsec=get(3)
o=0;ndef,o=u(funcsec[1],o); functypes=[]
for _ in range(ndef):
    ti,o=u(funcsec[1],o); functypes.append(ti)

# helper function indices in NEW numbering: after all defined funcs (shifted)
FIRST_DEF_NEW=nimp_func+NADD_IMP  # 22
T_XOR64R=find_or_add_type([0x7e,0x7e],[0x7e])
NHELP=12
# helper kinds: eqz32,eq32,ne32,eqz64,eq64,ne64,ltu64,gtu64,leu64,geu64,xor32,xor64
help_types=[T_UN32,T_BIN32,T_BIN32,T_UN64,T_BIN64,T_BIN64,T_BIN64,T_BIN64,T_BIN64,T_BIN64,T_BIN32,T_XOR64R]
help_idx=[FIRST_DEF_NEW+ndef+k for k in range(NHELP)]
H_EQZ32,H_EQ32,H_NE32,H_EQZ64,H_EQ64,H_NE64,H_LTU,H_GTU,H_LEU,H_GEU,H_XOR32,H_XOR64=help_idx
# KIND codes
K={0x45:1,0x46:2,0x47:3,0x50:4,0x51:5,0x52:6,0x54:7,0x56:8,0x58:9,0x5a:10,0x73:11,0x85:12}
import os
if os.environ.get("UONLY"):
    REPL={0x54:H_LTU,0x56:H_GTU,0x58:H_LEU,0x5a:H_GEU}
elif os.environ.get("XONLY"):
    REPL={0x73:H_XOR32,0x85:H_XOR64}
else:
    REPL={0x45:H_EQZ32,0x46:H_EQ32,0x47:H_NE32,0x50:H_EQZ64,0x51:H_EQ64,0x52:H_NE64,
          0x54:H_LTU,0x56:H_GTU,0x58:H_LEU,0x5a:H_GEU}

def skip_imm(b,o,op):
    if op in (0x02,0x03,0x04): o+=1
    elif op==0x0c or op==0x0d: _,o=u(b,o)
    elif op==0x0e:
        cnt,o=u(b,o)
        for _ in range(cnt): _,o=u(b,o)
        _,o=u(b,o)
    elif op==0x11: _,o=u(b,o); _,o=u(b,o)
    elif op==0x1c: cnt,o=u(b,o); o+=cnt
    elif op in (0x20,0x21,0x22,0x23,0x24): _,o=u(b,o)
    elif op>=0x28 and op<=0x3e: _,o=u(b,o); _,o=u(b,o)
    elif op==0x3f or op==0x40: o+=1
    elif op==0x41: _,o=slebv(b,o)
    elif op==0x42: _,o=slebv(b,o)
    elif op==0x43: o+=4
    elif op==0x44: o+=8
    elif op==0xfc:
        sub,o=u(b,o)
        if sub in (8,10): _,o=u(b,o); _,o=u(b,o)
        elif sub in (9,11,12,13,14,15,16,17): _,o=u(b,o)
    elif op==0xd0: o+=1
    return o

def rewrite_expr(code, instrument):
    b=code;o=0;out=bytearray()
    while o<len(b):
        op=b[o];st=o;o+=1
        if op==0x10:
            x,o=u(b,o); out+=b'\x10'+eu(ren(x)); continue
        if op==0xd2:
            x,o=u(b,o); out+=b'\xd2'+eu(ren(x)); continue
        if instrument and op in REPL:
            out+=b'\x10'+eu(REPL[op]); continue
        o=skip_imm(b,o,op)
        out+=b[st:o]
    return out

# code section
codesec=get(10)
o=0;ncode,o=u(codesec[1],o)
bodies=[]
for _ in range(ncode):
    bsz,o=u(codesec[1],o); bodies.append(codesec[1][o:o+bsz]); o+=bsz

new_bodies=[]
for fi in range(ncode):
    absidx=nimp_func+fi
    body=bodies[fi]
    p=0;nl,p=u(body,p); hdr=bytearray(body[0:p])
    for _ in range(nl):
        st=p;cnt,p=u(body,p);vt=body[p];p+=1;hdr+=body[st:p]
    code=body[p:]
    newcode=rewrite_expr(code, absidx in WHITELIST)
    new_bodies.append(bytes(hdr)+newcode)

# build helper bodies (no locals): header = 0x00 (0 local groups)
def hbody(*ops):
    return b'\x00'+bytes(ops)
def emit_help():
    bs=[]
    # eqz32(a): const KIND; local0; const0; call LOG32; local0; i32.eqz
    bs.append(b'\x00'+b'\x41'+eu(K[0x45])+b'\x20\x00'+b'\x41\x00'+b'\x10'+eu(LOG32)+b'\x20\x00'+b'\x45'+b'\x0b')
    # eq32(a,b)
    bs.append(b'\x00'+b'\x41'+eu(K[0x46])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG32)+b'\x20\x00\x20\x01'+b'\x46'+b'\x0b')
    # ne32
    bs.append(b'\x00'+b'\x41'+eu(K[0x47])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG32)+b'\x20\x00\x20\x01'+b'\x47'+b'\x0b')
    # eqz64(a): const KIND(i32); local0(i64); i64.const0; call LOG64; local0; i64.eqz
    bs.append(b'\x00'+b'\x41'+eu(K[0x50])+b'\x20\x00'+b'\x42\x00'+b'\x10'+eu(LOG64)+b'\x20\x00'+b'\x50'+b'\x0b')
    # eq64
    bs.append(b'\x00'+b'\x41'+eu(K[0x51])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG64)+b'\x20\x00\x20\x01'+b'\x51'+b'\x0b')
    # ne64
    bs.append(b'\x00'+b'\x41'+eu(K[0x52])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG64)+b'\x20\x00\x20\x01'+b'\x52'+b'\x0b')
    for oc in (0x54,0x56,0x58,0x5a):
        bs.append(b'\x00'+b'\x41'+eu(K[oc])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG64)+b'\x20\x00\x20\x01'+bytes([oc])+b'\x0b')
    # xor32: (i32,i32)->i32
    bs.append(b'\x00'+b'\x41'+eu(K[0x73])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG32)+b'\x20\x00\x20\x01'+b'\x73'+b'\x0b')
    # xor64
    bs.append(b'\x00'+b'\x41'+eu(K[0x85])+b'\x20\x00\x20\x01'+b'\x10'+eu(LOG64)+b'\x20\x00\x20\x01'+b'\x85'+b'\x0b')
    return bs
helper_bodies=emit_help()

# reassemble type section
def build_types():
    out=bytearray(eu(ntypes))
    for (p,r) in tlist:
        out+=b'\x60'+eu(len(p))+bytes(p)+eu(len(r))+bytes(r)
    return out
typesec[1]=build_types()

# imports: append log32, log64
def build_imports():
    pl=impsec[1]; o=0;n,o=u(pl,o); rest=pl[o:]
    add=eu(3)+b'env'+eu(5)+b'log32'+b'\x00'+eu(T_LOG32)
    add+=eu(3)+b'env'+eu(5)+b'log64'+b'\x00'+eu(T_LOG64)
    return bytearray(eu(n+NADD_IMP)+bytes(rest)+add)
impsec[1]=build_imports()

# func section: append helper type indices
def build_funcsec():
    out=bytearray(eu(ndef+NHELP))
    for ti in functypes: out+=eu(ti)
    for ti in help_types: out+=eu(ti)
    return out
funcsec[1]=build_funcsec()

# code section: append helper bodies
def build_code():
    out=bytearray(eu(ncode+NHELP))
    for nb in new_bodies: out+=eu(len(nb))+nb
    for hb in helper_bodies: out+=eu(len(hb))+hb
    return out
codesec[1]=build_code()

# exports renumber
expsec=get(7)
def build_exports():
    pl=expsec[1];o=0;n,o=u(pl,o);out=bytearray(eu(n))
    for _ in range(n):
        nl,o=u(pl,o);nm=pl[o:o+nl];o+=nl;k=pl[o];o+=1;idx,o=u(pl,o)
        if k==0: idx=ren(idx)
        out+=eu(nl)+nm+bytes([k])+eu(idx)
    return out
expsec[1]=build_exports()

# elem renumber
elemsec=get(9)
def build_elem():
    pl=elemsec[1];o=0;n,o=u(pl,o);out=bytearray(eu(n))
    for _ in range(n):
        flags,o=u(pl,o);seg=bytearray(eu(flags))
        assert flags==0
        eo=o
        while pl[o]!=0x0b:
            op=pl[o];o+=1;o=skip_imm(pl,o,op)
        o+=1;seg+=pl[eo:o]
        cnt,o=u(pl,o);seg+=eu(cnt)
        for _ in range(cnt): fx,o=u(pl,o);seg+=eu(ren(fx))
        out+=seg
    return out
if elemsec: elemsec[1]=build_elem()

# start renumber
startsec=get(8)
if startsec:
    idx,_=u(startsec[1],0); startsec[1]=bytearray(eu(ren(idx)))

# globals: renumber ref.func in init exprs
globalsec=get(6)
def build_globals():
    pl=globalsec[1];o=0;n,o=u(pl,o);out=bytearray(eu(n))
    for _ in range(n):
        vt=pl[o];o+=1;mut=pl[o];o+=1;seg=bytearray([vt,mut])
        eo=o
        while pl[o]!=0x0b:
            op=pl[o];o+=1;o=skip_imm(pl,o,op)
        o+=1
        seg+=rewrite_expr(pl[eo:o], False)
        out+=seg
    return out
if globalsec: globalsec[1]=build_globals()

outb=bytearray(data[:8])
for sid,pl in secs:
    outb+=bytes([sid])+eu(len(pl))+pl
open(OUTFILE,"wb").write(outb)
print("wrote",OUTFILE,len(outb),"helpers at",help_idx,"LOG32/64=",LOG32,LOG64)
