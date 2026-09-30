import struct, sys
from aeslib import enc_words
PT=bytes.fromhex('0a1b8253d5e0e16ab89f93f271f24659')
CT=bytes.fromhex('1b099147c0f6f672a18588ee6cec5979')
d=open(sys.argv[1],'rb').read()
for off in range(0,len(d)-240,4):
    xk=struct.unpack('<60I', d[off:off+240])
    if enc_words(PT,xk)==CT: print('ENC LE @',hex(off)); sys.stdout.flush()
    if enc_words(CT,xk)==PT: print('DEC LE @',hex(off)); sys.stdout.flush()
print('DONE',sys.argv[1]); sys.stdout.flush()
