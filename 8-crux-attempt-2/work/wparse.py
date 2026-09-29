import struct,sys
def leb(d,i,signed=False):
    r=s=0
    while True:
        b=d[i];i+=1;r|=(b&0x7f)<<s;s+=7
        if b<0x80:break
    if signed and b&0x40: r-=1<<s
    return r,i
def parse(path):
    d=open(path,'rb').read();i=8;secs=[]
    while i<len(d):
        sid=d[i];i+=1;n,i=leb(d,i);secs.append((sid,i,n));i+=n
    return d,secs
def memimage(path):
    d,secs=parse(path);mem=bytearray(0)
    for sid,o,n in secs:
        if sid==11:
            cnt,i=leb(d,o)
            for _ in range(cnt):
                flag,i=leb(d,i); assert flag==0
                assert d[i]==0x41; off,i=leb(d,i+1,True); assert d[i]==0x0b;i+=1
                sz,i=leb(d,i)
                if len(mem)<off+sz: mem.extend(b'\0'*(off+sz-len(mem)))
                mem[off:off+sz]=d[i:i+sz];i+=sz
    return bytes(mem)
if __name__=='__main__':
    m=memimage(sys.argv[1]);open(sys.argv[2],'wb').write(m);print(len(m))
