import struct,sys
from faes import enc
P2=bytes.fromhex('0a1b8253d5e0e16ab89f93f271f24659'); C2=bytes.fromhex('1b099147c0f6f672a18588ee6cec5979')
d=open('rk_mem.bin','rb').read()
N=len(d)
for off in range(0,N-240,4):
    xk=struct.unpack('<60I', d[off:off+240])
    if enc(P2,xk)==C2: print('ENC LE @',hex(off));sys.stdout.flush()
    if enc(C2,xk)==P2: print('DEC LE @',hex(off));sys.stdout.flush()
print('DONE')
