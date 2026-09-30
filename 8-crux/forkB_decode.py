m=open('mem_after.bin','rb').read()
def blob(a,n): return list(m[a:a+n])
def permute(buf, sched):
    buf=buf[:]
    L=len(sched)
    for i in range(0,L-1,2):
        a=sched[i]; b=sched[i+1]
        if a>=len(buf) or b>=len(buf): 
            return None
        k=((a^b)+i)&0xff
        oa,ob=buf[a],buf[b]
        buf[a]=(ob-k+8)&0xff
        buf[b]=(oa-k+8)&0xff
    return buf
def show(name,buf):
    if buf is None: print(name,"OOB"); return
    s=''.join(chr(c) if 32<=c<127 else '.' for c in buf)
    print(name, s)
datas={'0x469f7/32':blob(0x469f7,32),'0x469d7/32':blob(0x469d7,32),'0x44d0e/24':blob(0x44d0e,24),'0x44d26/24':blob(0x44d26,24),'0x45b9a/28':blob(0x45b9a,28),'0x4a78a/64':blob(0x4a78a,64)}
scheds={'0x4efa0/32':blob(0x4efa0,32),'0x4ea20/18':blob(0x4ea20,18)}
print("=== raw schedule values ===")
for sn,sv in scheds.items(): print(sn, sv)
print("=== permute attempts (no mods) ===")
for dn,dv in datas.items():
    for sn,sv in scheds.items():
        show(f"{dn} x {sn}:", permute(dv,sv))
    # also show raw ascii
    show(f"{dn} RAW:", dv)
