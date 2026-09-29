# instrument selected funcs with entry/exit hooks via import 4 (getRandomData) using odd/high-bit markers
import sys;sys.path.insert(0,'work')
from wparse import leb,parse
def uleb(v):
    o=bytearray()
    while True:
        b=v&0x7f;v>>=7
        if v:o.append(b|0x80)
        else:o.append(b);return bytes(o)
def sleb(v):
    o=bytearray()
    while True:
        b=v&0x7f;v>>=7
        if (v==0 and not b&0x40) or (v==-1 and b&0x40):o.append(b);return bytes(o)
        o.append(b|0x80)
HOOK=4
def hk(tag):  # tag i32 ; then SP|1
    return b'\x41'+sleb(tag-(1<<32) if tag>=1<<31 else tag)+b'\x10'+uleb(HOOK)+b'\x23\x00\x41\x01\x72\x10'+uleb(HOOK)
import wdis as D
def instrument(fids,out):
    d,secs=parse('ext/x/main.wasm')
    code=[s for s in secs if s[0]==10][0]
    fs=[x for x in secs if x[0]==3][0];n,q=leb(d,fs[1]);types=[]
    for _ in range(n):t,q=leb(d,q);types.append(t)
    fidset=set(f for f in fids if types[f-20]==0)
    cnt,i=leb(d,code[1]);newbodies=[]
    for k in range(cnt):
        fi=k+20;sz,j=leb(d,i);body=d[j:j+sz]
        if fi in fidset:
            # parse locals
            p=0;n,p=leb(body,p)
            for _ in range(n):c,p=leb(body,p);p+=1
            head=body[:p]
            entry=b'\x20\x00\x45\x04\x40'+hk(0x80000000|(fi<<1))+b'\x0b'
            # find return opcodes by walking instructions
            o=bytearray(head+entry);q=p;ext=hk(0xC0000000|(fi<<1))
            while q<len(body):
                st=q;op=body[q];q+=1
                if op in(2,3,4):q+=1
                elif op in(0xc,0xd,0x10,0x20,0x21,0x22,0x23,0x24):_,q=leb(body,q)
                elif op==0xe:
                    n2,q=leb(body,q)
                    for _ in range(n2+1):_,q=leb(body,q)
                elif op==0x11:_,q=leb(body,q);_,q=leb(body,q)
                elif 0x28<=op<=0x3e:_,q=leb(body,q);_,q=leb(body,q)
                elif op in(0x3f,0x40):q+=1
                elif op in(0x41,0x42):_,q=leb(body,q,True)
                elif op==0x43:q+=4
                elif op==0x44:q+=8
                elif op==0xfc:
                    a,q=leb(body,q)
                    if a in(10,):q+=2
                    elif a==11:q+=1
                    elif a>=8: _,q=leb(body,q); 
                if op==0x0f:o+=ext
                o+=body[st:q]
            body=bytes(o)
        newbodies.append(uleb(len(body))+body);i=j+sz
    cs=uleb(cnt)+b''.join(newbodies)
    res=d[:code[1]-1-len(uleb(code[2]))]
    # rebuild: replace code section
    pre=d[:8];outb=bytearray(pre)
    for sid,o2,n in secs:
        payload=cs if sid==10 else d[o2:o2+n]
        outb+=bytes([sid])+uleb(len(payload))+payload
    open(out,'wb').write(outb)
if __name__=='__main__':
    spec=sys.argv[1];fids=[]
    for part in spec.split(','):
        if '-' in part:a,b=map(int,part.split('-'));fids+=range(a,b+1)
        else:fids.append(int(part))
    instrument(fids,sys.argv[2])
