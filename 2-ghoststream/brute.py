exec(open('solve.py').read().split('potion=open')[0])
potion=open('extracted/GhostStream/PolyjuicePotion.txt','rb').read()[:255]
ads=b'AlbusDumbledore \r\n'
xk=bytes([0x8b,0x8f,0x92,0x85,0x88,0x96,0x98,0x9b,0x94,0x8b,0x95,0xe6,0xed,0xf0,0xe7])
def cstr(b): return b.split(b'\0')[0]
def wm(base,prev,dopost=True):
    t=bytearray(base+b'\0'*20); i=0
    while i < len(cstr(bytes(t))):
        t[i]^=1^prev; i+=1
    if dopost:
        for n in range(15): t[n]^=xk[n]
    return cstr(bytes(t))
def child_key(k):
    for sep in b'\r\n':
        if sep in k: k=k[:k.index(sep)]
    return k
tried=set()
for base in (ads,potion,ads.rstrip(b'\r\n'),b'AlbusDumbledore'):
    ks=[base]+[wm(base,p) for p in range(256)]+[wm(base,p,False) for p in range(256)]
    for k in ks:
        k=child_key(k)
        if not k or k in tried: continue
        tried.add(k)
        r=run(k)
        if b'flare' in r: print('HIT',k,r)
print(len(tried),'tried')
