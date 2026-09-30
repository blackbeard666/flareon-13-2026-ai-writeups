m=open('mem_after.bin','rb').read()
def blob(a,n): return list(m[a:a+n])
def permute(buf, sched):
    buf=buf[:]; L=len(sched)
    for i in range(0,L-1,2):
        a=sched[i]; b=sched[i+1]
        if a>=len(buf) or b>=len(buf): return None
        k=((a^b)+i)&0xff
        oa,ob=buf[a],buf[b]
        buf[a]=(ob-k+8)&0xff; buf[b]=(oa-k+8)&0xff
    return buf
def sh(b): return ''.join(chr(c) if 32<=c<127 else '.' for c in b) if b else 'OOB'
sched_ef00=blob(0x4ef00,32)
print("sched@0x4ef00:",sched_ef00)
# dump region around itabs to find more schedules (values all small)
print("=== scan 0x4e900..0x4f800 for small-valued 16-48 byte runs ===")
a=0x4e900
while a<0x4f900:
    # detect run where all bytes <=42
    if all(x<=42 for x in m[a:a+16]) and m[a]<=42:
        j=a
        while j<0x4f900 and m[j]<=42: j+=1
        if j-a>=12: print(hex(a),"len",j-a,list(m[a:j])[:48])
        a=j
    else: a+=1
datas={'0x469f7/32':blob(0x469f7,32),'0x469d7/32':blob(0x469d7,32),'0x44d0e/24':blob(0x44d0e,24),'0x44d26/24':blob(0x44d26,24),'0x45b9a/28':blob(0x45b9a,28),'0x4a78a/64':blob(0x4a78a,64)}
print("=== permute with sched@0x4ef00 ===")
for dn,dv in datas.items(): print(dn,"->",sh(permute(dv,sched_ef00)))
