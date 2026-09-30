import sys, pefile, hashlib
from capstone import *
sys.stdout.reconfigure(encoding='utf-8')

BR = {'jmp','call','je','jne','jz','jnz','ja','jae','jb','jbe','jg','jge','jl','jle',
      'jo','jno','js','jns','jp','jnp','jc','jnc','jcxz','jecxz','jrcxz','loop','loope','loopne'}

def load(path):
    pe=pefile.PE(path, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_EXCEPTION']])
    base=pe.OPTIONAL_HEADER.ImageBase
    # section map
    secs=[]
    for s in pe.sections:
        secs.append((s.VirtualAddress, s.VirtualAddress+max(s.Misc_VirtualSize,s.SizeOfRawData), s.get_data(), s.Name.rstrip(b'\0')))
    def read(rva, n):
        for a,b,d,nm in secs:
            if a<=rva<b:
                off=rva-a
                return d[off:off+n]
        return b''
    # pdata
    funcs=[]
    pd=None
    for s in pe.sections:
        if s.Name.rstrip(b'\0')==b'.pdata': pd=s.get_data()
    import struct
    for i in range(0,len(pd)-11,12):
        beg,end,unw=struct.unpack_from('<III',pd,i)
        if beg==0 and end==0: continue
        if end>beg and end-beg<0x20000:
            funcs.append((beg,end))
    return pe, base, read, funcs

md=Cs(CS_ARCH_X86, CS_MODE_64); md.detail=True
HAS_ENC=True

def norm(code, va):
    """return (skeleton_hash, valbytes) where skeleton masks all imm+addr, valbytes keeps data imm but masks addr."""
    skel=bytearray(); val=bytearray()
    for ins in md.disasm(code, va):
        b=bytearray(ins.bytes)
        v=bytearray(ins.bytes)
        # zero rip-relative disp
        try:
            enc=ins.encoding
            if enc.disp_size:
                for k in range(enc.disp_offset, enc.disp_offset+enc.disp_size):
                    if k<len(b): b[k]=0;
                # only mask disp in val if it's rip-relative (address); detect via op_str '[rip'
                if 'rip' in ins.op_str:
                    for k in range(enc.disp_offset, enc.disp_offset+enc.disp_size):
                        if k<len(v): v[k]=0
            if enc.imm_size:
                for k in range(enc.imm_offset, enc.imm_offset+enc.imm_size):
                    if k<len(b): b[k]=0
                # in val, mask imm only if this is a branch (address)
                if ins.mnemonic in BR:
                    for k in range(enc.imm_offset, enc.imm_offset+enc.imm_size):
                        if k<len(v): v[k]=0
        except Exception:
            pass
        skel+= bytes([ins.bytes[0]])  # opcode-ish; plus masked
        skel+= b
        val+= v
    return hashlib.md5(bytes(skel)).hexdigest(), bytes(val), bytes(skel)

def build(path):
    pe,base,read,funcs=load(path)
    m={}  # skel_hash -> list of (va, valbytes, rawbytes)
    for beg,end in funcs:
        code=read(beg, end-beg)
        if not code: continue
        try:
            sh,val,skel=norm(code, base+beg)
        except Exception:
            continue
        m.setdefault(sh,[]).append((beg, val, code))
    return m

print("building stock coreclr...");
stock={}
for p in ["C:/Users/cavila/Desktop/tools/dotnet10ref/runtimes/win-x64/native/coreclr.dll",
          "C:/Users/cavila/Desktop/tools/dotnet10ref/runtimes/win-x64/native/clrjit.dll"]:
    mm=build(p)
    for k,v in mm.items(): stock.setdefault(k,[]).extend(v)
    print("  ",p.split('/')[-1], "funcs skeletons:", len(mm))

print("building exe...")
exe=build("C:/Users/cavila/Desktop/ctf/flareon13-2026/6-threatinvaders/ThreatInvaders/ThreatInvaders.exe")
print("exe skeletons:", len(exe))

# Find exe functions whose skeleton matches a UNIQUE stock skeleton but valbytes differ
mods=[]
for sh, lst in exe.items():
    if sh not in stock: continue
    st=stock[sh]
    # unique-ish: compare valbytes sets
    stock_vals=set(v for (_,v,_) in st)
    for (va, val, raw) in lst:
        if val not in stock_vals:
            # modification: matched structure, different data constants
            # pick a stock representative of same length
            rep=None
            for (_,sv,sr) in st:
                if len(sr)==len(raw): rep=(sv,sr); break
            if rep is None: rep=(st[0][1], st[0][2])
            mods.append((va, len(raw), raw, rep[1]))
print("candidate modified functions:", len(mods))
mods.sort(key=lambda x:x[1])
import struct
for va,ln,raw,sraw in mods[:40]:
    # byte diff positions
    diffs=[i for i in range(min(len(raw),len(sraw))) if raw[i]!=sraw[i]]
    print("="*60)
    print("EXE func VA=%x len=%d  diffbytes=%d"%(0x140000000+va, ln, len(diffs)))
    print("  diff offsets:", diffs[:20])

# STATS
exact=0; skelmatch_valdiff=0; exeonly=0; total=0
for sh,lst in exe.items():
    for (va,val,raw) in lst:
        total+=1
        if sh in stock:
            if val in set(v for (_,v,_) in stock[sh]): exact+=1
            else: skelmatch_valdiff+=1
        else: exeonly+=1
print("STATS total exe funcs=%d exact=%d skelmatch_valdiff=%d exeonly=%d"%(total,exact,skelmatch_valdiff,exeonly))
