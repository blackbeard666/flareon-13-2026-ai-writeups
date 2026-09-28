from unicorn import *
from unicorn.x86_const import *
d=open('flareon13.doc','rb').read()
code=d[:0x10000-0x100]
mu=Uc(UC_ARCH_X86,UC_MODE_16)
mu.mem_map(0,0x100000)
SEG=0x1000; base=SEG*16
mu.mem_write(base+0x100,code)
mu.mem_write(base,b'\xcd\x20'+b'\0'*0xfe)
for r in (UC_X86_REG_CS,UC_X86_REG_DS,UC_X86_REG_ES,UC_X86_REG_SS): mu.reg_write(r,SEG)
mu.reg_write(UC_X86_REG_SP,0xfffe); mu.reg_write(UC_X86_REG_IP,0x100)
out=bytearray()
def intr(mu,no,ud):
    ah=mu.reg_read(UC_X86_REG_AH)
    ip=mu.reg_read(UC_X86_REG_IP)
    if no==0x21:
        if ah==9:
            ds=mu.reg_read(UC_X86_REG_DS); dx=mu.reg_read(UC_X86_REG_DX)
            m=mu.mem_read(ds*16+dx,0x400); s=bytes(m).split(b'$')[0]; out.extend(s); print('int21/09:',s)
        elif ah==2: out.append(mu.reg_read(UC_X86_REG_DL)); 
        elif ah in (0x4c,0): print('exit'); mu.emu_stop()
        else: print('int21 ah=%02x'%ah)
    elif no==0x20: print('int20 exit'); mu.emu_stop()
    else: print('int %02x ah=%02x at %04x'%(no,ah,ip))
mu.hook_add(UC_HOOK_INTR,intr)
try: mu.emu_start(base+0x100,0,count=5_000_000)
except UcError as e: print('err',e,hex(mu.reg_read(UC_X86_REG_IP)))
print('OUT:',bytes(out))
