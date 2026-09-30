const29=[173,194,186,188,65,151,115,32,224,140,177,157,105,75,178,107,115,183,180,146,132,116,133,136,158,154,63,55,203]
target=[24,8,17,11,11,17,24,18,25,18,20,10,15,9,15,24,22,19,14,5,2,15,1,20,11,15,23,22,3,14,4,15,17,18,6,0,11,6,14,20,5,8]
X=86; Y=35; Z=3
buf=const29[:]
buf[6]=(buf[6]+22)&0xff
buf[11]=(buf[11]^X)&0xff
buf[13]=(buf[13]+Y)&0xff
buf[22]=(buf[22]-Z)&0xff
print("after mods:",buf)
for i in range(0,42,2):
    a=target[i]; b=target[i+1]
    k=((a^b)+i)&0xffffffffffffffff
    old_a=buf[a]; old_b=buf[b]
    buf[a]=(old_b - k + 8)&0xff
    buf[b]=(old_a - k + 8)&0xff
print("result bytes:",buf)
print("ascii:", ''.join(chr(c) if 32<=c<127 else '.' for c in buf))
