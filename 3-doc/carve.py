# flareon13.doc is a raw-mode CD image (2352-byte sectors: 16B sync/header + 2048B data + 288B EDC/ECC)
import struct, subprocess, os
d=open('flareon13.doc','rb').read()
n=len(d)//2352
open('cd.iso','wb').write(b''.join(d[i*2352+16:i*2352+16+2048] for i in range(n)))   # md5 d8228cac...
subprocess.run(['C:/Program Files/7-Zip/7z.exe','x','-y','-tudf','-oudf','cd.iso'],check=True,stdout=subprocess.DEVNULL)
c=open('udf/click_me','rb').read()              # fat Mach-O, 2 arm64 slices (cpusubtype 0 and 3)
assert struct.unpack('>I',c[:4])[0]==0xcafebabe
os.makedirs('macho',exist_ok=True)
for i in range(struct.unpack('>I',c[4:8])[0]):
    ct,st,off,sz,al=struct.unpack('>5I',c[8+20*i:28+20*i])
    nm='macho/click_me~.arm64'+('-%d'%st if st else '')   # 7-Zip naming
    open(nm,'wb').write(c[off:off+sz]); print(nm,hex(off),sz)
