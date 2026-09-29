import sympy,sys,json,time
from sympy.ntheory import factorint
memo={}
def fac(n):
    if n in memo:return memo[n]
    t=time.time();f=factorint(n);memo[n]=f;print('factored',n.bit_length(),'bits in',round(time.time()-t,1),f,file=sys.stderr);return f
def tree(p):
    if p==2:return 2
    f=fac(p-1)
    for q in f: assert sympy.isprime(q)
    return {q:tree(q) for q in f}
N=0xd389dfbb379a02ccda7a4ab0b327e8e3655a3c96447c1b5578bee179c930e261
T=tree(N)
json.dump({str(k):{str(a):b for a,b in v.items()} for k,v in memo.items()},open('facts.json','w'))
print('done')
