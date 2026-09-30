import re
lines=open('f3267.txt').read().splitlines()
# find br_table line, states start after
# We'll walk instructions, track current "entry state" by the sequence of 'end' after br_table.
# Simpler: collect all "i32.const N ; local.set 0" as transitions, plus preceding conditions.
ops=[]
for ln in lines:
    m=re.match(r'\s*([0-9a-f]+)\s+(.*)',ln)
    if m: ops.append((m.group(1),m.group(2).strip()))
# find comparisons and the state they set on the 'if' branch
out=[]
i=0
while i<len(ops):
    off,op=ops[i]
    # detect "i32.const N (0xNN)\n local.set 0" -> sets state
    m=re.match(r'i32.const (\d+)',op)
    if m and i+1<len(ops) and ops[i+1][1]=='local.set 0':
        state=int(m.group(1))
        # look back a few ops for a comparison/condition context
        ctx=[]
        for j in range(max(0,i-8),i):
            o2=ops[j][1]
            if any(k in o2 for k in ['i64.eq','i64.ne','i64.lt','i64.le','i64.gt','i64.ge','load8','load32','load off=1','load off=184','load off=192','i64.const','i64.and','load16']):
                ctx.append(o2)
        out.append((off,state,' | '.join(ctx[-5:])))
    i+=1
for off,st,ctx in out:
    print(f"@{off} ->S{st}   {ctx}")
