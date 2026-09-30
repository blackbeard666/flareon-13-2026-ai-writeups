import re
lines=open('f3267.txt').read().splitlines()
# parse instructions after header
insns=[]
for ln in lines:
    m=re.match(r'\s+([0-9a-f]+) (.*)',ln)
    if m: insns.append((int(m.group(1),16),m.group(2).strip()))
# Find br_table line, compute block depth mapping.
# Strategy: simulate block/loop/if nesting to map each 'br N' / br_table target depth -> resume offset.
# In wasm, 'block'/'loop'/'if' open a label; 'br N' jumps to the (N)th enclosing label's target
# (for block/if: the matching 'end'; for loop: the 'loop' start). We compute, at the br_table location,
# the list of enclosing labels and their resume points, then table[state]=depth -> resume offset.
# Build a stack while scanning; record for br_table the enclosing structure.
stack=[] # each: (kind, start_index)
# first find matching ends by scanning
kindstack=[]
resume={} # index of opener -> resume instruction index (after matching end for block/if; opener+? for loop)
openers=[]
for i,(off,txt) in enumerate(insns):
    op=txt.split()[0]
    if op in ('block','loop','if'):
        kindstack.append((op,i))
    elif op=='end':
        if kindstack:
            k,oi=kindstack.pop()
            # resume for block/if = i+1 (after end); for loop = oi (loop start)
            resume[oi]= (oi if k=='loop' else i+1)
# Now find br_table and its enclosing stack
kindstack=[]
labels_at={}
for i,(off,txt) in enumerate(insns):
    op=txt.split()[0]
    if op in ('block','loop','if'):
        kindstack.append((op,i))
    if 'br_table' in txt:
        # enclosing labels innermost first
        enc=list(reversed(kindstack))
        # depth d -> opener enc[d]
        tbl=re.search(r'br_table \[([0-9, ]+)\] default (\d+)',txt)
        arr=[int(x) for x in tbl.group(1).split(',')]
        dflt=int(tbl.group(2))
        print("br_table at off %x, num states=%d, enclosing depth=%d"%(off,len(arr),len(enc)))
        # map state-> resume offset
        st_resume={}
        for state,depth in enumerate(arr):
            op_i=enc[depth][1]
            r=resume.get(op_i)
            st_resume[state]= insns[r][0] if r is not None and r<len(insns) else None
        # print first ~40 states
        for s in range(len(arr)):
            print("  state %3d -> depth %2d -> offset %s"%(s,arr[s], hex(st_resume[s]) if st_resume[s] is not None else "?"))
        break
    if op=='end':
        if kindstack: kindstack.pop()
