import struct, hashlib, sys
from Crypto.Cipher import AES
CT=bytes.fromhex("78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232ff619632797e3708ad29b2cdd4491a3c2")
IV=bytes.fromhex("5ff26040c4c20b9f2ffdefa7ecf65d91")
d=bytes.fromhex(open('certP.hex').read().strip())
pos=0
def u32():
    global pos; v=struct.unpack_from('<I',d,pos)[0]; pos+=4; return v
def parse():
    global pos
    assert d[pos]==1; pos+=1
    nc=u32(); ch=[]
    for _ in range(nc):
        u32(); ch.append(parse())
    kl=u32(); k=d[pos:pos+kl]; pos+=kl
    vl=u32(); v=d[pos:pos+vl]; pos+=vl
    return [ch,k,v]
root=parse()
def ser(nd, tv):
    ch,k,v=nd
    if not ch and k==b'\x02': v=tv
    out=bytearray([1]); out+=struct.pack('<I',len(ch))
    for c in ch:
        cb=ser(c,tv); out+=struct.pack('<I',len(cb)); out+=cb
    out+=struct.pack('<I',len(k)); out+=k
    out+=struct.pack('<I',len(v)); out+=v
    return bytes(out)
sha=hashlib.sha256
def brute_L(L,lo,hi):
    rep=(1<<(8*(L-1))) if L>0 else 0
    tmpl=bytearray(ser(root,rep.to_bytes(L,'little') if L>0 else b''))
    pref=bytes([1,0,0,0,0,1,0,0,0,2])+struct.pack('<I',L)
    positions=[]; i=tmpl.find(pref)
    while i>=0: positions.append(i+len(pref)); i=tmpl.find(pref,i+1)
    aesnew=AES.new
    for v in range(max(lo,rep),min(hi,1<<(8*L))):
        vb=v.to_bytes(L,'little')
        if vb[-1]==0: continue
        for p_ in positions: tmpl[p_:p_+L]=vb
        k=sha(bytes(tmpl)).digest()
        pt=aesnew(k,AES.MODE_CBC,IV).decrypt(CT)
        if b'flare' in pt or b'@fl' in pt or b're-on' in pt:
            print("FLARE HIT v=%d L=%d pt=%r"%(v,L,pt),flush=True)
        n=pt[-1]
        if 3<=n<=16 and pt[64-n:]==bytes([n])*n:
            print("PAD%d v=%d pt=%r"%(n,v,pt),flush=True)
    print("L%d..%d done"%(L,hi),flush=True)
lo=int(sys.argv[1]); hi=int(sys.argv[2])
assert ser(root,b'')==d
for L in (1,2,3,4):
    a=(1<<(8*(L-1))) if L>1 else 1; b=1<<(8*L)
    if hi>a and lo<b: brute_L(L,lo,hi)
print("ALLDONE",flush=True)
