import json,glob,sys,os
def load(paths,t0=None,t1=None):
    seen={};tmin=tmax=None
    for p in paths:
        for line in open(p,encoding='utf-8',errors='replace'):
            try:r=json.loads(line)
            except:continue
            if r.get('type')!='assistant':continue
            ts=r.get('timestamp');m=r.get('message',{});u=m.get('usage')
            if not u or not ts:continue
            if t0 and ts<t0:continue
            if t1 and ts>t1:continue
            mid=m.get('id') or r.get('uuid')
            seen[mid]=(u,m.get('model'),ts)
    s=dict(out=0,inp=0,cr=0,cc=0,models={},tmin=None,tmax=None)
    for u,mo,ts in seen.values():
        s['out']+=u.get('output_tokens',0);s['inp']+=u.get('input_tokens',0)
        s['cr']+=u.get('cache_read_input_tokens',0);s['cc']+=u.get('cache_creation_input_tokens',0)
        s['models'][mo]=s['models'].get(mo,0)+1
        s['tmin']=min(s['tmin'] or ts,ts);s['tmax']=max(s['tmax'] or ts,ts)
    return s
if __name__=='__main__':
    mode=sys.argv[1]
    if mode=='cur':
        print(json.dumps(load(glob.glob(os.path.expanduser('~/.claude/projects/C--Users-cavila-Desktop-ctf-flareon13-2026-8-crux-attempt-2/*.jsonl')),t1=sys.argv[2] if len(sys.argv)>2 else None),indent=1))
    else:
        base=os.path.expanduser('~/.claude/projects/C--Users-cavila-Desktop-ctf-flareon13-2026-1-flarecaptcha/8ad03a1c-d47c-470b-9aee-210c2a3d8873')
        print(json.dumps(load([base+'.jsonl']+glob.glob(base+'/subagents/*.jsonl'),t0=sys.argv[2]),indent=1))
