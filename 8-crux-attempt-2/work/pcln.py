import struct
d=open('work/mem.bin','rb').read();B=0x51660
nfunc,nfiles,text,fno,cuo,fto,pco,plo=struct.unpack('<8Q',d[B+8:B+72])
names={}
for k in range(nfunc):
    e,fo=struct.unpack('<II',d[B+plo+8*k:B+plo+8*k+8])
    f=B+plo+fo
    eo,no=struct.unpack('<Ii',d[f:f+8])
    s=d[B+fno+no:d.index(b'\0',B+fno+no)].decode()
    names[k]=(e,s)
import json
out=[(k,e,s) for k,(e,s) in names.items()]
json.dump(out,open('work/funcs.json','w'))
if __name__=='__main__':
    for k,e,s in out[:5]+out[-5:]:print(k,hex(e),s)
    for k,e,s in out:
        if s.startswith('main.'):print(k,hex(e),s)
