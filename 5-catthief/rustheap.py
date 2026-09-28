import itertools

class RustBinaryHeap:
    """Faithful port of Rust std BinaryHeap (max-heap). `key(x)` gives the ordering value;
    larger key = pops first. Ties handled exactly like Rust's <= comparisons."""
    def __init__(self, key):
        self.data=[]; self.key=key
    def _lt(self,a,b): return self.key(a) <  self.key(b)
    def _le(self,a,b): return self.key(a) <= self.key(b)
    def push(self,x):
        self.data.append(x); self._sift_up(0, len(self.data)-1)
    def _sift_up(self,start,pos):
        d=self.data; elt=d[pos]; hole=pos
        while hole>start:
            parent=(hole-1)//2
            if self._le(elt, d[parent]): break   # elt <= parent -> stop
            d[hole]=d[parent]; hole=parent
        d[hole]=elt; return hole
    def pop(self):
        d=self.data
        if not d: return None
        item=d.pop()
        if d:
            item, d[0] = d[0], item
            self._sift_down_to_bottom(0)
        return item
    def _sift_down_to_bottom(self,pos):
        d=self.data; end=len(d); start=pos; elt=d[pos]; hole=pos
        child=2*hole+1
        while child <= end-2:
            # child += (get(child) <= get(child+1))  -> pick larger; on tie pick right
            if self._le(d[child], d[child+1]): child+=1
            d[hole]=d[child]; hole=child; child=2*hole+1
        if child==end-1:
            d[hole]=d[child]; hole=child
        d[hole]=elt
        self._sift_up(start,hole)
    def __len__(self): return len(self.data)

class Node:
    _ids=itertools.count()
    def __init__(self,freq,sym=None,l=None,r=None):
        self.freq=freq; self.sym=sym; self.l=l; self.r=r; self.id=next(Node._ids)

def build_tree(freqs, key_mode, merge_mode):
    # freqs: dict sym->count. key_mode picks heap ordering. merge_mode picks a/b -> left/right
    nodes=[Node(f,sym=s) for s,f in freqs.items()]
    if key_mode=='freq_only':
        key=lambda n: -n.freq                      # max-heap pops smallest freq
    elif key_mode=='freq_id':
        key=lambda n: (-n.freq, -n.id)             # tie: smaller id pops first (max of -id)
    elif key_mode=='freq_id_rev':
        key=lambda n: (-n.freq, n.id)              # tie: larger id pops first
    elif key_mode=='freq_sym':
        key=lambda n: (-n.freq, -(n.sym if n.sym is not None else 1<<20))
    h=RustBinaryHeap(key)
    # push in symbol order (as leaves are created)
    for n in nodes: h.push(n)
    while len(h)>1:
        a=h.pop(); b=h.pop()
        if merge_mode=='a_left':
            m=Node(a.freq+b.freq,l=a,r=b)
        else:
            m=Node(a.freq+b.freq,l=b,r=a)
        h.push(m)
    return h.pop()

def tree_codes(root):
    codes={}
    def dfs(n,code,depth):
        if n.sym is not None:
            codes[n.sym]=(code,depth); return
        dfs(n.l, code<<1, depth+1)
        dfs(n.r, (code<<1)|1, depth+1)
    if root.sym is not None:  # single symbol
        codes[root.sym]=(0,1)
    else:
        dfs(root,0,0)
    return codes

def canonical_from_lengths_order(order_lengths):
    # order_lengths: list of (symbol, length) already in the tie-order to assign codes
    codes={}; code=0; prev=0
    for sym,l in order_lengths:
        code <<= (l-prev)
        codes[sym]=(code,l); code+=1; prev=l
    return codes

GT = {10:'101',11:'001',12:'110',13:'010',14:'111',15:'011',16:'100',17:'000'}
freqs={s:1 for s in range(10,18)}
for km in ['freq_only','freq_id','freq_id_rev','freq_sym']:
    for mm in ['a_left','a_right']:
        root=build_tree(dict(freqs), km, mm)
        c=tree_codes(root)
        s=' '.join('%d:%s'%(k,format(v[0],'0%db'%v[1])) for k,v in sorted(c.items()))
        match=all(format(c[k][0],'0%db'%c[k][1])==GT[k] for k in GT)
        print('TREE key=%s merge=%s match=%s  %s'%(km,mm,match,s))
