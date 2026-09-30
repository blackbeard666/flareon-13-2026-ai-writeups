import sys, struct

data=open("main.wasm","rb").read()
def u(o):
    r=0;s=0
    while True:
        b=data[o];o+=1;r|=(b&0x7f)<<s
        if not(b&0x80):break
        s+=7
    return r,o
def su(b,o):  # from bytes
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s
        if not(x&0x80):break
        s+=7
    return r,o
def sleb(b,o):
    r=0;s=0
    while True:
        x=b[o];o+=1;r|=(x&0x7f)<<s;s+=7
        if not(x&0x80):
            if x&0x40 and s<64: r|=(-1)<<s
            break
    return r,o

# parse sections
sections={}
o=8
while o<len(data):
    sid=data[o];o+=1
    sz,o=u(o)
    sections.setdefault(sid,[]).append((o,sz))
    o+=sz

# types
types=[]  # list of (params, results)
if 1 in sections:
    o,sz=sections[1][0]
    n,o=u(o)
    for _ in range(n):
        assert data[o]==0x60; o+=1
        pc,o=u(o); params=list(data[o:o+pc]); o+=pc
        rc,o=u(o); results=list(data[o:o+rc]); o+=rc
        types.append((params,results))

# imports: count funcs
num_imp_funcs=0
imp_func_types=[]
if 2 in sections:
    o,sz=sections[2][0]
    n,o=u(o)
    for _ in range(n):
        ml,o=u(o); mod=data[o:o+ml];o+=ml
        nl,o=u(o); nm=data[o:o+nl];o+=nl
        kind=data[o];o+=1
        if kind==0:
            ti,o=u(o); imp_func_types.append(ti); num_imp_funcs+=1
        elif kind==1:
            o+=1; # elemtype
            fl=data[o];o+=1
            mn,o=u(o)
            if fl: mx,o=u(o)
        elif kind==2:
            fl=data[o];o+=1; mn,o=u(o)
            if fl: mx,o=u(o)
        elif kind==3:
            o+=2 # valtype + mut

# func section: type index per defined func
func_types=[]
if 3 in sections:
    o,sz=sections[3][0]
    n,o=u(o)
    for _ in range(n):
        ti,o=u(o); func_types.append(ti)

# code section: bodies
code_bodies=[]  # (start_off, size) of each defined func body (the whole entry incl locals)
if 10 in sections:
    o,sz=sections[10][0]
    n,o=u(o)
    for _ in range(n):
        bsz,o=u(o)
        code_bodies.append((o,bsz))
        o+=bsz

def func_type_of(idx):
    if idx<num_imp_funcs: return imp_func_types[idx]
    return func_types[idx-num_imp_funcs]

# minimal opcode disassembler
def disasm_func(absidx):
    di=absidx-num_imp_funcs
    if di<0 or di>=len(code_bodies):
        print("func %d is an import"%absidx); return
    start,bsz=code_bodies[di]
    b=data[start:start+bsz]
    o=0
    # locals
    nl,o=su(b,o)
    locals_=[]
    for _ in range(nl):
        cnt,o=su(b,o); vt=b[o];o+=1; locals_.append((cnt,vt))
    ti=func_types[di]
    print("=== func[%d] type=%d params=%s results=%s locals=%s ==="%(absidx,ti,types[ti][0],types[ti][1],locals_))
    out=[]
    depth=1
    while o<len(b):
        opoff=o
        op=b[o];o+=1
        s=None
        if op==0x0b: depth-=1; s="end"
        elif op==0x02: bt=b[o];o+=1; s="block"; depth+=1
        elif op==0x03: bt=b[o];o+=1; s="loop"; depth+=1
        elif op==0x04: bt=b[o];o+=1; s="if"; depth+=1
        elif op==0x05: s="else"
        elif op==0x0c: x,o=su(b,o); s="br %d"%x
        elif op==0x0d: x,o=su(b,o); s="br_if %d"%x
        elif op==0x0e:
            cnt,o=su(b,o); tbl=[]
            for _ in range(cnt): t,o=su(b,o); tbl.append(t)
            d,o=su(b,o); s="br_table %s default %d"%(tbl,d)
        elif op==0x10: x,o=su(b,o); s="call %d"%x
        elif op==0x11: ty,o=su(b,o); tb,o=su(b,o); s="call_indirect type=%d"%ty
        elif op==0x1a: s="drop"
        elif op==0x1b: s="select"
        elif op==0x1c:
            cnt,o=su(b,o); o+=cnt; s="select_t"
        elif op in (0x20,0x21,0x22): x,o=su(b,o); s=("local.get","local.set","local.tee")[op-0x20]+" %d"%x
        elif op in (0x23,0x24): x,o=su(b,o); s=("global.get","global.set")[op-0x23]+" %d"%x
        elif op in (0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e):
            al,o=su(b,o); off,o=su(b,o)
            names={0x28:"i32.load",0x29:"i64.load",0x2a:"f32.load",0x2b:"f64.load",0x2c:"i32.load8_s",0x2d:"i32.load8_u",0x2e:"i32.load16_s",0x2f:"i32.load16_u",0x30:"i64.load8_s",0x31:"i64.load8_u",0x32:"i64.load16_s",0x33:"i64.load16_u",0x34:"i64.load32_s",0x35:"i64.load32_u",0x36:"i32.store",0x37:"i64.store",0x38:"f32.store",0x39:"f64.store",0x3a:"i32.store8",0x3b:"i32.store16",0x3c:"i64.store8",0x3d:"i64.store16",0x3e:"i64.store32"}
            s="%s off=%d"%(names[op],off)
        elif op==0x3f: o+=1; s="memory.size"
        elif op==0x40: o+=1; s="memory.grow"
        elif op==0x41: v,o=sleb(b,o); s="i32.const %d (%#x)"%(v,v&0xffffffff)
        elif op==0x42: v,o=sleb(b,o); s="i64.const %d (%#x)"%(v,v&0xffffffffffffffff)
        elif op==0x43: v=struct.unpack("<f",b[o:o+4])[0];o+=4; s="f32.const %r"%v
        elif op==0x44: v=struct.unpack("<d",b[o:o+8])[0];o+=8; s="f64.const %r"%v
        elif op==0xfc:
            sub,o=su(b,o)
            if sub in (8,10): # memory.init/copy
                x,o=su(b,o); y,o=su(b,o); s="fc:%d %d %d"%(sub,x,y)
            elif sub in (9,11,12,13,14,15,16,17):
                x,o=su(b,o); s="fc:%d %d"%(sub,x)
            else: s="fc:%d"%sub
        else:
            # single-byte numeric/comparison ops
            M={0x45:"i32.eqz",0x46:"i32.eq",0x47:"i32.ne",0x48:"i32.lt_s",0x49:"i32.lt_u",0x4a:"i32.gt_s",0x4b:"i32.gt_u",0x4c:"i32.le_s",0x4d:"i32.le_u",0x4e:"i32.ge_s",0x4f:"i32.ge_u",
               0x50:"i64.eqz",0x51:"i64.eq",0x52:"i64.ne",0x53:"i64.lt_s",0x54:"i64.lt_u",0x55:"i64.gt_s",0x56:"i64.gt_u",0x57:"i64.le_s",0x58:"i64.le_u",0x59:"i64.ge_s",0x5a:"i64.ge_u",
               0x67:"i32.clz",0x68:"i32.ctz",0x69:"i32.popcnt",0x6a:"i32.add",0x6b:"i32.sub",0x6c:"i32.mul",0x6d:"i32.div_s",0x6e:"i32.div_u",0x6f:"i32.rem_s",0x70:"i32.rem_u",0x71:"i32.and",0x72:"i32.or",0x73:"i32.xor",0x74:"i32.shl",0x75:"i32.shr_s",0x76:"i32.shr_u",0x77:"i32.rotl",0x78:"i32.rotr",
               0x79:"i64.clz",0x7a:"i64.ctz",0x7b:"i64.popcnt",0x7c:"i64.add",0x7d:"i64.sub",0x7e:"i64.mul",0x7f:"i64.div_s",0x80:"i64.div_u",0x81:"i64.rem_s",0x82:"i64.rem_u",0x83:"i64.and",0x84:"i64.or",0x85:"i64.xor",0x86:"i64.shl",0x87:"i64.shr_s",0x88:"i64.shr_u",0x89:"i64.rotl",0x8a:"i64.rotr",
               0xa7:"i32.wrap_i64",0xac:"i64.extend_i32_s",0xad:"i64.extend_i32_u",0xc0:"i32.extend8_s",0xc1:"i32.extend16_s",0xc2:"i64.extend8_s",0xc3:"i64.extend16_s",0xc4:"i64.extend32_s",0x1a:"drop",0x0f:"return",0x00:"unreachable",0x01:"nop"}
            s=M.get(op, "op_%#x"%op)
        out.append("  %04x %s"%(opoff,s))
    print("\n".join(out))

if __name__=="__main__":
    print("num_imp_funcs=%d num_defined=%d"%(num_imp_funcs,len(code_bodies)))
    for a in sys.argv[1:]:
        disasm_func(int(a))
        print()
