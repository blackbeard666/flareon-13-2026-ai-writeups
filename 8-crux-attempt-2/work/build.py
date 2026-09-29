import json,sys
from cert import node,leaf
from enc import enc
F={int(k):{int(a):b for a,b in v.items()} for k,v in json.load(open('facts.json')).items()}
def minroot(p):
    fs=list(F[p-1])
    g=2
    while True:
        if all(pow(g,(p-1)//q,p)!=1 for q in fs):return g
        g+=1
def cert(p,wit=minroot):
    if p==2:return leaf()
    ch=[]
    for q in sorted(F[p-1]):
        ch+= [cert(q,wit)]*F[p-1][q]
    return node(ch,p,wit(p))
N=0xd389dfbb379a02ccda7a4ab0b327e8e3655a3c96447c1b5578bee179c930e261
if __name__=='__main__':
    c=cert(N);print(len(c),file=sys.stderr);open('cert.bin','wb').write(c);print(enc(c))
