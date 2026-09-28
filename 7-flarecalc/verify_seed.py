import pickle, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_64
md=Cs(CS_ARCH_X86,CS_MODE_64)
MAP={k:v for k,v in pickle.load(open("map_entries.pkl","rb"))}
CODE=[3822,3823,3824,3825,3826,3827,3828,3829]

def deinter_by_seed(buf, seed):
    state=seed & 0xffffffff
    def nxt():
        nonlocal state
        state=(state*1103515245+12345)&0xffffffff
        return state
    out=bytearray(); i=0; n=len(buf)
    while i<n:
        out.append(buf[i])
        skip=(nxt()%3)+1
        for _ in range(skip): nxt()
        i+=1+skip
    return bytes(out)

def xor_by_fold(buf, fold):
    b=fold&0xff; out=bytearray(buf)
    for i in range(len(out)):
        b=(b*0x6d+0x39)&0xff
        out[i]^=b
    return bytes(out)

def unpack_seed(key, seed, fold):
    return deinter_by_seed(xor_by_fold(MAP[key], fold), seed)

def full_decode(code):
    off=0
    while off<len(code):
        g=list(md.disasm(code[off:],0,count=1))
        if not g: return False
        off+=g[0].size
    return True

def find_fold(key, seed):
    """find a fold making blob[key] fully decode (prefilter first byte prologue)"""
    for fold in range(256):
        code=unpack_seed(key,seed,fold)
        if not code: continue
        if code[0] not in (0x48,0x40,0x4c,0x53,0x55,0x56,0x57,0x4d,0x41): continue
        if full_decode(code): return fold, code
    return None, None

def verify(seed):
    folds={}
    okcount=0
    for k in CODE:
        f,code=find_fold(k,seed)
        if f is None: return None
        folds[k]=(f,code)
        okcount+=1
    return folds

if __name__=="__main__":
    seeds=[]
    for line in open("seedbrute.out"):
        line=line.strip()
        if line.startswith("SEED="):
            s=int(line.split()[0].split("=")[1]); seeds.append(s)
    seeds=list(dict.fromkeys(seeds))
    print("candidate seeds:",len(seeds))
    for s in seeds:
        # quick: does blob 3829 fully decode for some fold?
        f,_=find_fold(3829,s)
        if f is None: continue
        # strong: all code blobs decode
        res=verify(s)
        if res:
            print("*** WINNER seed=%u"%s)
            for k in CODE:
                fo,code=res[k]
                print("  blob %d fold=%d codelen=%d head=%s"%(k,fo,len(code),code[:16].hex()))
            pickle.dump({k:res[k][1] for k in CODE}|{"seed":s,"folds":{k:res[k][0] for k in CODE}}, open("unpacked.pkl","wb"))
            break
    else:
        print("no winner among candidates")
