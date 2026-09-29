import sys,json,struct
sys.path.insert(0,'work');from wparse import leb,parse
d,secs=parse('ext/x/main.wasm')
names={k+20:s for k,e,s in json.load(open('work/funcs.json'))}
imp=["scheduleTimeoutEvent","clearTimeoutEvent","resetMemoryDataView","wasmWrite","getRandomData","nanotime1","wasmExit","walltime","finalizeRef","stringVal","valueGet","valueSet","valueIndex","valueSetIndex","valueLength","valueCall","valueNew","valuePrepareString","valueLoadString","copyBytesToJS"]
for i,n in enumerate(imp):names[i]='js.'+n
OP={0:'unreachable',1:'nop',2:'block',3:'loop',4:'if',5:'else',0xb:'end',0xc:'br',0xd:'br_if',0xe:'br_table',0xf:'return',0x10:'call',0x11:'call_indirect',0x1a:'drop',0x1b:'select',0x20:'local.get',0x21:'local.set',0x22:'local.tee',0x23:'global.get',0x24:'global.set',0x3f:'memory.size',0x40:'memory.grow',0x41:'i32.const',0x42:'i64.const',0x43:'f32.const',0x44:'f64.const'}
mem=['i32.load','i64.load','f32.load','f64.load','i32.load8_s','i32.load8_u','i32.load16_s','i32.load16_u','i64.load8_s','i64.load8_u','i64.load16_s','i64.load16_u','i64.load32_s','i64.load32_u','i32.store','i64.store','f32.store','f64.store','i32.store8','i32.store16','i64.store8','i64.store16','i64.store32']
for i,m in enumerate(mem):OP[0x28+i]=m
simple="i32.eqz i32.eq i32.ne i32.lt_s i32.lt_u i32.gt_s i32.gt_u i32.le_s i32.le_u i32.ge_s i32.ge_u i64.eqz i64.eq i64.ne i64.lt_s i64.lt_u i64.gt_s i64.gt_u i64.le_s i64.le_u i64.ge_s i64.ge_u f32.eq f32.ne f32.lt f32.gt f32.le f32.ge f64.eq f64.ne f64.lt f64.gt f64.le f64.ge i32.clz i32.ctz i32.popcnt i32.add i32.sub i32.mul i32.div_s i32.div_u i32.rem_s i32.rem_u i32.and i32.or i32.xor i32.shl i32.shr_s i32.shr_u i32.rotl i32.rotr i64.clz i64.ctz i64.popcnt i64.add i64.sub i64.mul i64.div_s i64.div_u i64.rem_s i64.rem_u i64.and i64.or i64.xor i64.shl i64.shr_s i64.shr_u i64.rotl i64.rotr f32.abs f32.neg f32.ceil f32.floor f32.trunc f32.nearest f32.sqrt f32.add f32.sub f32.mul f32.div f32.min f32.max f32.copysign f64.abs f64.neg f64.ceil f64.floor f64.trunc f64.nearest f64.sqrt f64.add f64.sub f64.mul f64.div f64.min f64.max f64.copysign i32.wrap_i64 i32.trunc_f32_s i32.trunc_f32_u i32.trunc_f64_s i32.trunc_f64_u i64.extend_i32_s i64.extend_i32_u i64.trunc_f32_s i64.trunc_f32_u i64.trunc_f64_s i64.trunc_f64_u f32.convert_i32_s f32.convert_i32_u f32.convert_i64_s f32.convert_i64_u f32.demote_f64 f64.convert_i32_s f64.convert_i32_u f64.convert_i64_s f64.convert_i64_u f64.promote_f32 i32.reinterpret_f32 i64.reinterpret_f64 f32.reinterpret_i32 f64.reinterpret_i64 i32.extend8_s i32.extend16_s i64.extend8_s i64.extend16_s i64.extend32_s".split()
for i,m in enumerate(simple):OP[0x45+i]=m
code=[s for s in secs if s[0]==10][0]
cnt,i=leb(d,code[1])
bodies={}
for k in range(cnt):
    sz,i=leb(d,i);bodies[k+20]=(i,sz);i+=sz
def dis(fi,out):
    o,sz=bodies[fi];end=o+sz;i=o
    n,i=leb(d,i);loc=[]
    for _ in range(n):
        c,i=leb(d,i);t=d[i];i+=1;loc.append((c,t))
    out.write(f"=== func[{fi}] {names.get(fi,'')} locals={loc}\n")
    depth=0
    while i<end:
        p=i;op=d[i];i+=1;nm=OP.get(op,hex(op));arg=''
        if op in(2,3,4):
            bt=d[i];i+=1;depth+=1;arg=f'd{depth}'
        elif op==0xb: arg=f'd{depth}';depth-=1
        elif op==5: arg=f'd{depth}'
        elif op in(0xc,0xd):a,i=leb(d,i);arg=f'{a} ->d{depth-a}'
        elif op==0xe:
            n2,i=leb(d,i);ts=[]
            for _ in range(n2+1):a,i=leb(d,i);ts.append(a)
            arg=str(ts) if len(ts)<40 else str(ts[:40])+f'...({len(ts)})'
        elif op==0x10:a,i=leb(d,i);arg=f'{a} <{names.get(a,"")}>'
        elif op==0x11:a,i=leb(d,i);b,i=leb(d,i);arg=f'type{a}'
        elif op in(0x20,0x21,0x22,0x23,0x24):a,i=leb(d,i);arg=str(a)
        elif 0x28<=op<=0x3e:al,i=leb(d,i);of,i=leb(d,i);arg=f'off={of}'
        elif op in(0x3f,0x40):i+=1
        elif op==0x41:a,i=leb(d,i,True);arg=f'{a} ({a&0xffffffff:#x})'
        elif op==0x42:a,i=leb(d,i,True);arg=f'{a} ({a&0xffffffffffffffff:#x})'
        elif op==0x43:arg=str(struct.unpack('<f',d[i:i+4])[0]);i+=4
        elif op==0x44:arg=str(struct.unpack('<d',d[i:i+8])[0]);i+=8
        elif op==0xfc:a,i=leb(d,i);nm=f'fc.{a}'
        out.write(f'{p:06x} {nm} {arg}\n')
if __name__=='__main__':
    lo,hi=int(sys.argv[1]),int(sys.argv[2])
    with open(sys.argv[3],'w') as out:
        for f in range(lo,hi+1):dis(f,out)
