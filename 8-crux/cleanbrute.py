import struct, hashlib, sys
from Crypto.Cipher import AES
CT=bytes.fromhex("78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232ff619632797e3708ad29b2cdd4491a3c2")
IV=bytes.fromhex("5ff26040c4c20b9f2ffdefa7ecf65d91")
tmpl=bytearray(open('tmpl.bin','rb').read())
f=open('positions.bin','rb'); n=struct.unpack('<I',f.read(4))[0]; ps=[struct.unpack('<I',f.read(4))[0] for _ in range(n)]
lo=int(sys.argv[1]); hi=int(sys.argv[2])
sha=hashlib.sha256; newc=AES.new
for x in range(lo,hi):
    vb=x.to_bytes(4,'little')
    if vb[3]==0: continue
    for p in ps: tmpl[p:p+4]=vb
    pt=newc(sha(bytes(tmpl)).digest(),AES.MODE_CBC,IV).decrypt(CT)
    if b'flare' in pt.lower():
        print("*** REAL HIT x=%d pt=%r"%(x,pt),flush=True)
    if (x&0xffffff)==0: print("progress x=%d"%x,flush=True)
print("DONE %d..%d"%(lo,hi),flush=True)
