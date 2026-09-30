# Emulate the Math.min hook's pure helpers to get per-lap angle params
import lief, struct, math
from unicorn import *
from unicorn.x86_const import *
b = lief.parse('neon_outrun'); raw = open('neon_outrun','rb').read()
mu = Uc(UC_ARCH_X86, UC_MODE_64)
mu.mem_map(0, 0x1460000)
for s in b.segments:
    if s.type == lief.ELF.Segment.TYPE.LOAD:
        mu.mem_write(s.virtual_address, raw[s.file_offset:s.file_offset+s.physical_size])
for r in b.relocations:
    if r.type == lief.ELF.Relocation.TYPE.X86_64_RELATIVE and r.address < 0x1460000:
        mu.mem_write(r.address, struct.pack('<Q', r.addend))
STK = 0x7f0000000000; mu.mem_map(STK, 0x100000)
RET = 0x1450000  # unused bss addr as return sentinel
def run(start, end, regs):
    mu.reg_write(UC_X86_REG_RSP, STK + 0x80000)
    for k, v in regs.items(): mu.reg_write(k, v)
    mu.emu_start(start, end)
def call(fn, rdi, rsi=0):
    sp = STK + 0x80000
    mu.mem_write(sp, struct.pack('<Q', RET))
    mu.reg_write(UC_X86_REG_RSP, sp); mu.reg_write(UC_X86_REG_RDI, rdi); mu.reg_write(UC_X86_REG_RSI, rsi)
    mu.emu_start(fn, RET)
    return mu.reg_read(UC_X86_REG_RAX), mu.reg_read(UC_X86_REG_RDX)
R = lambda r: mu.reg_read(r)
# 1. constant byte chain
run(0x67ed5b, 0x67eec7, {})
al = R(UC_X86_REG_RAX) & 0xff
# 2. constant 64-bit chains -> D and term count
run(0x67ef9f, 0x67f8b8, {UC_X86_REG_R14: 0})
rax, rdi, r14, r9, r13 = [R(x) for x in (UC_X86_REG_RAX, UC_X86_REG_RDI, UC_X86_REG_R14, UC_X86_REG_R9, UC_X86_REG_R13)]
M = (1 << 64) - 1
D = float((((rax << 7) & M) | ((rdi << 5) & M) | ((r14 << 4) & M) | ((r9 << 2) & M)))
N = (r13 << 4) & M
print('al=%#x D=%r nterms=%d' % (al, D, N))
laps = []
for i in range(28):
    a2, _ = call(0x67f9d8, i, al)
    K, dl = call(0x68003e, a2 & 0xff)
    K = struct.unpack('<q', struct.pack('<Q', K))[0]
    laps.append((K, dl & 1))
print(laps)
import json; json.dump({'D': D, 'N': N, 'laps': laps}, open('params.json', 'w'))
