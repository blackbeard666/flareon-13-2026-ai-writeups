# final step: child's modified RC4 (step 18, mask Dt ^ (18+C[k])) keyed with the pipe message
# key = what the parent writes to \\.\pipe\FlareChallenge (sniff.py prints PIPE: b'HarryPotter')
# prereq: python carve_child.py
import sys
exec(open('solve.py').read().split('potion=open')[0])
key=(sys.argv[1] if len(sys.argv)>1 else 'HarryPotter').encode()
S=list(range(256)); j=0
for i in range(256):
    j=(j+key[i%len(key)]+S[i])&0xff; S[i],S[j]=S[j],S[i]
i=j=0; out=bytearray()
for k in range(38):
    i=(i+18)&0xff; j=(j+S[i])&0xff; S[i],S[j]=S[j],S[i]
    out.append(S[(S[i]+S[j])&0xff]^Dt[k%len(Dt)]^((18+C[k])&0xff))
print(bytes(out).decode())
