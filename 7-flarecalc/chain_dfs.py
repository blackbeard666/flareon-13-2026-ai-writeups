import pickle,sys
from unicorn import *
from unicorn.x86_const import *
from capstone import Cs,CS_ARCH_X86,CS_MODE_64
cs=Cs(CS_ARCH_X86,CS_MODE_64)
MAP={k:v for k,v in pickle.load(open('map_entries.pkl','rb'))}
keys=set(MAP.keys()); SEED=1116755918
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
_dc={}
def decode(key):
    if key in _dc:return _dc[key]
    r=[]
    for fold in range(256):
        s=strong(deinter(xf(MAP[key],fold),SEED))
        if s:r.append((fold,s));break
    _dc[key]=r;return r
def find_loop(code):
    ins=list(cs.disasm(code,0))
    for i in range(len(ins)-1):
        a=ins[i];b=ins[i+1]
        if a.mnemonic=='cmp' and a.op_str.startswith('eax,') and b.mnemonic in('jb','jl','jc','jbe'):
            reg=a.op_str.split(',')[1].strip();top=int(b.op_str,16);exit_=b.address+b.size
            if top>=b.address:continue
            N=0
            for x in ins:
                if x.mnemonic=='mov' and x.op_str.startswith(reg+','):
                    try:N=int(x.op_str.split(',')[1].strip(),16)
                    except:N=0
                    if N:break
            return top,exit_,(N*(N-1)//2)&0xffffffff
    return None
STOP=0x400000
def run(code,IN,kb):
    lp=find_loop(code)
    mu=Uc(UC_ARCH_X86,UC_MODE_64)
    for a in (0x1000000,0x200000,0x300000,STOP): mu.mem_map(a,0x10000)
    mu.mem_write(0x1000000,code); mu.mem_write(0x300000,bytes(kb))
    sp=0x208000; mu.reg_write(UC_X86_REG_RSP,sp); mu.mem_write(sp,STOP.to_bytes(8,'little'))
    mu.reg_write(UC_X86_REG_RCX,IN);mu.reg_write(UC_X86_REG_RDX,0x300000);mu.reg_write(UC_X86_REG_R8,0)
    if lp:
        top,exit_,acc=lp
        def hook(mu,addr,size,ud):
            if addr==0x1000000+top:
                mu.mem_write(sp+0x10, acc.to_bytes(4,'little')); mu.reg_write(UC_X86_REG_RIP,0x1000000+exit_)
        mu.hook_add(UC_HOOK_CODE,hook,begin=0x1000000+top,end=0x1000000+top)
    try: mu.emu_start(0x1000000,STOP,count=20000000)
    except: return None,None
    return mu.reg_read(UC_X86_REG_RAX)&0xffffffff, bytearray(mu.mem_read(0x300000,0x20))
def transitions(state,kb):
    cf=decode(state)
    if not cf:return []
    fold,code=cf[0]; res=[]
    for IN in range(256):
        ns,nkb=run(code,IN,kb)
        if ns is None:continue
        if ns in keys or ns==4485: res.append((IN,ns,nkb))
    return res
import sys
sys.setrecursionlimit(10000)
best=[None]
def dfs(state,kb,path,visited,depth):
    if state==4485:
        best[0]=(bytes(bytearray(p[0] for p in path)),kb,path); return True
    if depth>60: return False
    for IN,ns,nkb in transitions(state,kb):
        if ns in visited: continue
        # prefer printable exploration order
        pass
    trs=sorted(transitions(state,kb),key=lambda t:(0 if 0x20<=t[0]<0x7f else 1,t[0]))
    for IN,ns,nkb in trs:
        if ns in visited: continue
        if dfs(ns,nkb,path+[(IN,ns)],visited|{ns},depth+1): return True
    return False
ok=dfs(52090,bytearray(0x20),[],{52090},0)
if ok:
    inp,kb,path=best[0]
    print('REACHED 4485!')
    print('INPUTS hex',inp.hex())
    print('INPUTS repr',repr(inp))
    print('KEYBUF',bytes(kb).hex())
    print('states',[p[1] for p in path])
    pickle.dump({'inputs':inp,'keybuf':bytes(kb),'states':[p[1] for p in path]},open('chain_result.pkl','wb'))
else:
    print('no path found')
