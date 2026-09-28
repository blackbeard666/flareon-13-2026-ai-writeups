import hashlib, struct, re, zlib
d=open('flareon13.doc','rb').read()
PAD=bytes.fromhex('28BF4E5E4E758A4164004E56FFFA01082E2E00B6D0683E802F0CA9FE6453697A')
O=bytes.fromhex('2055c756c72e1ad702608e8196acad447ad32d17cff583235f6dd15fed7dab67')
U=bytes.fromhex('7a39b1e0b393575547585235da5d636029f34e50b8bde2ffbcd3d5330d76619f')
ID=bytes.fromhex('466c6172654f6e506f6c79676c6f7431')
P=struct.pack('<i',-44)
def rc4(k,data):
    S=list(range(256)); j=0
    for i in range(256):
        j=(j+S[i]+k[i%len(k)])&255; S[i],S[j]=S[j],S[i]
    i=j=0; o=bytearray()
    for c in data:
        i=(i+1)&255; j=(j+S[i])&255; S[i],S[j]=S[j],S[i]; o.append(c^S[(S[i]+S[j])&255])
    return bytes(o)
def key(pw): return hashlib.md5((pw+PAD)[:32]+O+P+ID).digest()[:5]
k=key(b''); print('empty pw ok:', rc4(k,PAD)==U)
def objkey(n): return hashlib.md5(k+struct.pack('<I',n)[:3]+b'\0\0').digest()[:10]
def stream(n):
    m=re.search(rb'\n%d 0 obj\n<<(.*?)>>\nstream\n'%n,d,re.S)
    L=int(re.search(rb'/Length (\d+)',m.group(1)).group(1))
    return m.group(1), d[m.end():m.end()+L]
for n in (1,5,8):
    hdr,s=stream(n); pt=rc4(objkey(n),s)
    open(f'obj{n}.bin','wb').write(pt)
    print(n,hdr,len(s),pt[:120])
