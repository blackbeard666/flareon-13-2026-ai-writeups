import struct
data=open("main_gatebypass.wasm","rb").read()

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

# split into sections (id, payload bytes) preserving order
o=8
secs=[]  # (id, payload)
while o<len(data):
    sid=data[o];o+=1
    sz,o=u(data,o)
    secs.append([sid, bytearray(data[o:o+sz])])
    o+=sz

def get(id):
    for s in secs:
        if s[0]==id: return s
    return None

# count imports (funcs) and parse type count
def count_imports(pl):
    o=0; n,o=u(pl,o); nf=0
    for _ in range(n):
        ml,o=u(pl,o);o+=ml; nl,o=u(pl,o);o+=nl
        k=pl[o];o+=1
        if k==0: ti,o=u(pl,o); nf+=1
        elif k==1: o+=1; fl=pl[o];o+=1; mn,o=u(pl,o);
        elif k==2: fl=pl[o];o+=1; mn,o=u(pl,o)
        elif k==3: o+=2
        if k==1:
            # table: re-handle limits (fixed above we only advanced flag+min; add max)
            pass
    return nf
# simpler robust import parse
def parse_imports(pl):
    o=0; n,o=u(pl,o); nf=0; entries=[]
    for _ in range(n):
        ml,o=u(pl,o); mod=pl[o:o+ml];o+=ml; nl,o=u(pl,o); nm=pl[o:o+nl];o+=nl
        k=pl[o];o+=1
        if k==0: ti,o=u(pl,o); nf+=1
        elif k==1:
            et=pl[o];o+=1; fl=pl[o];o+=1; mn,o=u(pl,o)
            if fl: mx,o=u(pl,o)
        elif k==2:
            fl=pl[o];o+=1; mn,o=u(pl,o)
            if fl: mx,o=u(pl,o)
        elif k==3:
            vt=pl[o];o+=1; mut=pl[o];o+=1
    return n, nf

typesec=get(1); impsec=get(2); funcsec=get(3); expsec=get(7); elemsec=get(9); codesec=get(10); startsec=get(8); globalsec=get(6)
nimp_total, nimp_func = parse_imports(impsec[1])
print("imports total=%d func=%d"%(nimp_total,nimp_func))
SHIFT=nimp_func   # threshold: func index >= SHIFT is a defined func -> +1
TRACE=nimp_func   # new trace import index

# 1) add a type for trace: (func (param i32)) -> find or append
def parse_types(pl):
    o=0;n,o=u(pl,o); tl=[]
    for _ in range(n):
        assert pl[o]==0x60;o+=1
        pc,o=u(pl,o); params=list(pl[o:o+pc]);o+=pc
        rc,o=u(pl,o); results=list(pl[o:o+rc]);o+=rc
        tl.append((params,results))
    return n,tl
ntypes, tlist = parse_types(typesec[1])
trace_type=None
for i,(p,r) in enumerate(tlist):
    if p==[0x7f] and r==[]: trace_type=i;break
if trace_type is None:
    trace_type=ntypes
    # append type
    newt=b'\x60'+enc_u(1)+b'\x7f'+enc_u(0)
    body=enc_u(ntypes+1)+typesec[1][len(enc_u(ntypes)):]+newt
    typesec[1]=bytearray(body)
    print("added trace type at",trace_type)
else:
    print("reuse trace type",trace_type)

# 2) add trace import  (module "env", name "trace")
def rebuild_imports(pl):
    o=0;n,o=u(pl,o); rest=pl[o:]
    newimp=enc_u(3)+b'env'+enc_u(5)+b'trace'+b'\x00'+enc_u(trace_type)
    return bytearray(enc_u(n+1)+rest+newimp)
impsec[1]=rebuild_imports(impsec[1])

def ren(idx):  # renumber a func index
    return idx+1 if idx>=SHIFT else idx

# 3) rewrite code section: for each body, renumber call/ref.func and prepend trace call
def rewrite_code(pl):
    o=0;n,o=u(pl,o)
    out=bytearray(); out+=enc_u(n)
    for fi in range(n):
        orig_absidx=SHIFT+fi   # original absolute index of this defined function
        bsz,o=u(pl,o)
        body=pl[o:o+bsz]; o+=bsz
        # parse locals header
        p=0; nl,p=u(body,p)
        loc=bytearray(); loc+=body[0:p]  # includes count
        for _ in range(nl):
            st=p
            cnt,p=u(body,p); vt=body[p];p+=1
            loc+=body[st:p]
        code=body[p:]
        newcode=rewrite_expr(code)
        # prepend trace: i32.const orig_absidx ; call TRACE
        pre=b'\x41'+enc_s(orig_absidx)+b'\x10'+enc_u(TRACE)
        nb=bytes(loc)+pre+newcode
        out+=enc_u(len(nb))+nb
    return out

def rewrite_expr(code):
    b=code; o=0; out=bytearray()
    while o<len(b):
        op=b[o]; st=o; o+=1
        if op==0x10:  # call
            x,o=u(b,o); out+=b'\x10'+enc_u(ren(x)); continue
        if op==0xd2:  # ref.func
            x,o=u(b,o); out+=b'\xd2'+enc_u(ren(x)); continue
        # otherwise copy opcode + its immediates unchanged: need to know immediate sizes
        o=skip_imm(b,o,op)
        out+=b[st:o]
    return out

def skip_imm(b,o,op):
    if op in (0x02,0x03,0x04): o+=1  # blocktype (single byte here; could be s33 but Go uses 0x40/valtype)
    elif op==0x0c or op==0x0d: _,o=u(b,o)
    elif op==0x0e:
        cnt,o=u(b,o)
        for _ in range(cnt): _,o=u(b,o)
        _,o=u(b,o)
    elif op==0x11: _,o=u(b,o); _,o=u(b,o)
    elif op==0x1c:
        cnt,o=u(b,o); o+=cnt
    elif op in (0x20,0x21,0x22,0x23,0x24): _,o=u(b,o)
    elif op>=0x28 and op<=0x3e: _,o=u(b,o); _,o=u(b,o)
    elif op==0x3f or op==0x40: o+=1
    elif op==0x41: _,o=slebv(b,o)
    elif op==0x42: _,o=slebv(b,o)
    elif op==0x43: o+=4
    elif op==0x44: o+=8
    elif op==0xfc:
        sub,o=u(b,o)
        if sub in (8,): _,o=u(b,o); _,o=u(b,o)
        elif sub in (9,): _,o=u(b,o)
        elif sub in (10,): _,o=u(b,o); _,o=u(b,o)
        elif sub in (11,): _,o=u(b,o)
        elif sub in (12,13,14,15): _,o=u(b,o)  # table ops (approx)
        # 0-7 (trunc_sat) no imm
    elif op==0xd0: o+=1  # ref.null t
    # else: no immediate
    return o

codesec[1]=rewrite_code(codesec[1])

# 4) exports: renumber func exports
def rewrite_exports(pl):
    o=0;n,o=u(pl,o); out=bytearray(enc_u(n))
    for _ in range(n):
        nl,o=u(pl,o); nm=pl[o:o+nl];o+=nl; k=pl[o];o+=1; idx,o=u(pl,o)
        if k==0: idx=ren(idx)
        out+=enc_u(nl)+nm+bytes([k])+enc_u(idx)
    return out
expsec[1]=rewrite_exports(expsec[1])

# 5) elem: renumber func indices (Go uses elem type 0: func idx vec)
def rewrite_elem(pl):
    o=0;n,o=u(pl,o); out=bytearray(enc_u(n))
    for _ in range(n):
        st=o
        flags,o=u(pl,o)
        seg=bytearray(enc_u(flags))
        if flags==0:
            # active, table 0, offset expr, func idx vec
            # copy offset expr until 0x0b
            eo=o
            while pl[o]!=0x0b: o=skip_instr(pl,o)
            o+=1
            seg+=pl[eo:o]
            cnt,o=u(pl,o); seg+=enc_u(cnt)
            for _ in range(cnt): fx,o=u(pl,o); seg+=enc_u(ren(fx))
        else:
            # fallback: copy raw remainder of this segment is hard; assume only flags==0 present
            raise Exception("unexpected elem flags %d"%flags)
        out+=seg
    return out
def skip_instr(b,o):
    op=b[o];o+=1; return skip_imm(b,o,op)
if elemsec:
    elemsec[1]=rewrite_elem(elemsec[1])

# 6) start section
if startsec:
    o=0; idx,o=u(startsec[1],0); startsec[1]=bytearray(enc_u(ren(idx)))

# 7) global section: ref.func in init exprs
def rewrite_globals(pl):
    o=0;n,o=u(pl,o); out=bytearray(enc_u(n))
    for _ in range(n):
        vt=pl[o];o+=1; mut=pl[o];o+=1; seg=bytes([vt,mut])
        eo=o
        while pl[o]!=0x0b: o=skip_instr_rf(pl,o,seg_out:=None)
        o+=1
        # rewrite ref.func inside
        seg+=rewrite_expr(pl[eo:o])
        out+=seg
    return out
# globals rarely have ref.func in Go; try, else leave
try:
    if globalsec: globalsec[1]=rewrite_globals(globalsec[1])
except Exception as e:
    print("global rewrite skipped:",e)

# reassemble
outb=bytearray(data[:8])
for sid,pl in secs:
    outb+=bytes([sid])+enc_u(len(pl))+pl
open("main_gb_instr.wasm","wb").write(outb)
print("wrote main_gb_instr.wasm",len(outb))
