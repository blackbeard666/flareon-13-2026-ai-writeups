from unicorn import *
from unicorn.x86_const import *
import pefile, struct
pe=pefile.PE('ToxicMiner.exe'); ib=pe.OPTIONAL_HEADER.ImageBase
size=pe.OPTIONAL_HEADER.SizeOfImage
img=bytearray(size)
hdr=pe.get_memory_mapped_image(ImageBase=ib)
img[:len(hdr)]=hdr
mu=Uc(UC_ARCH_X86,UC_MODE_64)
BASE=ib
mu.mem_map(BASE,(size+0xfff)&~0xfff)
mu.mem_write(BASE,bytes(img))
STK=0x10000000; mu.mem_map(STK,0x100000)
def key_for(serial):
    sp=STK+0x80000
    outbuf=STK+0x90000
    mu.mem_write(outbuf,b'\0'*64)
    mu.reg_write(UC_X86_REG_RSP,sp)
    mu.reg_write(UC_X86_REG_RCX,serial)
    mu.reg_write(UC_X86_REG_RDX,0x0b501e7e)
    mu.reg_write(UC_X86_REG_R8,outbuf)
    RET=0x5000000
    mu.mem_write(sp,struct.pack('<Q',RET))
    mu.emu_start(0x140134ca0, RET)
    return bytes(mu.mem_read(outbuf,32))
for s in (0,0x12345678,0xdeadbeef):
    print('%08x'%s, key_for(s).hex())
