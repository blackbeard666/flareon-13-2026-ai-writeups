import pickle
from unicorn import *
from unicorn.x86_const import *
from capstone import Cs,CS_ARCH_X86,CS_MODE_64
cs=Cs(CS_ARCH_X86,CS_MODE_64)
MAP={k:v for k,v in pickle.load(open('map_entries.pkl','rb'))}
SEED=1116755918
def deinter(buf,seed):
    st=seed&0xffffffff
    def nxt():
        nonlocal st;st=(st*1103515245+12345)&0xffffffff;return st
    out=bytearray();i=0;n=len(buf)
    while i<n:
        out.append(buf[i]);sk=(nxt()%3)+1
        for _ in range(sk):nxt()
        i+=1+sk
    return bytes(out)
def xf(buf,fold):
    b=fold&0xff;o=bytearray(buf)
    for i in range(len(o)):b=(b*0x6d+0x39)&0xff;o[i]^=b
    return bytes(o)
def strong(code):
    off=0;ro=None;n=0
    while off<len(code):
        g=list(cs.disasm(code[off:],0,count=1))
        if not g:return None
        ins=g[0];n+=1
        if ins.mnemonic=='ret':ro=off+ins.size;break
        off+=ins.size
    if ro is None or n<4:return None
    if any(b!=0xcc for b in code[ro:]):return None
    return code[:ro]
xtea=strong(deinter(xf(MAP[4485],226),SEED))
kb=bytes.fromhex('670daa0ff05e7d85472eeb55a716a7b88d63019c27ee22ea447fd4fde87c013d')
CB=0x1000000;OUT=0x300000;CT=0x310000;KEY=0x320000;STK=0x330000;STOP=0x400000
def run_xtea(ct):
    mu=Uc(UC_ARCH_X86,UC_MODE_64)
    for a in (CB,OUT,CT,KEY,STK,STOP): mu.mem_map(a,0x10000)
    mu.mem_write(CB,xtea)
    mu.mem_write(CT,ct)
    mu.mem_write(KEY,kb)
    sp=STK+0x8000; mu.reg_write(UC_X86_REG_RSP,sp); mu.mem_write(sp,STOP.to_bytes(8,'little'))
    mu.reg_write(UC_X86_REG_RCX,OUT)   # output
    mu.reg_write(UC_X86_REG_RDX,CT)    # ciphertext
    mu.reg_write(UC_X86_REG_R8,KEY)    # keybuf
    try: mu.emu_start(CB,STOP,count=5000000)
    except Exception as e: return None,None
    rax=mu.reg_read(UC_X86_REG_RAX)&0xffffffffffffffff
    out=bytes(mu.mem_read(OUT,64))
    return rax,out
# brute fold for 9990
for fold in range(256):
    ct=deinter(xf(MAP[9990],fold),SEED)
    rax,out=run_xtea(ct)
    if out is None: continue
    printable=sum(1 for c in out[:40] if 32<=c<127)
    if b'flare' in out.lower() or b'@flare-on' in out.lower() or printable>=30:
        print('fold=%d rax=%s'%(fold,hex(rax)))
        print('  ctlen',len(ct),'ct',ct[:16].hex())
        print('  OUT:',out)
        print('  OUT ascii:',out[:48].decode('latin1'))
