import sys, json, struct, os
sys.path.insert(0, os.path.dirname(__file__))
from wparse import leb
import wdis as D
d = D.d; names = D.names; bodies = D.bodies
RN = json.load(open(os.path.join(os.path.dirname(__file__), 'rtnames.json'))) if os.path.exists(os.path.join(os.path.dirname(__file__), 'rtnames.json')) else {}

fsec = [x for x in D.secs if x[0] == 3][0]
n, q = leb(d, fsec[1]); types = []
for _ in range(n):
    t, q = leb(d, q); types.append(t)
TY = {0: (1, 1), 1: (1, 0), 2: (4, 1), 3: (3, 1), 4: (3, 1), 5: (1, 1), 6: (0, 1), 7: (0, 0), 8: (2, 0), 9: (0, 1), 10: (2, 1)}

BI = {'add': '+', 'sub': '-', 'mul': '*', 'div_s': '/s', 'div_u': '/u', 'rem_s': '%s', 'rem_u': '%u', 'and': '&', 'or': '|',
      'xor': '^', 'shl': '<<', 'shr_s': '>>s', 'shr_u': '>>', 'rotl': 'rotl', 'rotr': 'rotr', 'eq': '==', 'ne': '!=',
      'lt_s': '<s', 'lt_u': '<u', 'gt_s': '>s', 'gt_u': '>u', 'le_s': '<=s', 'le_u': '<=u', 'ge_s': '>=s', 'ge_u': '>=u',
      'lt': '<', 'gt': '>', 'le': '<=', 'ge': '>=', 'min': 'min', 'max': 'max', 'div': '/'}
UN = {'i32.eqz': '!', 'i64.eqz': '!', 'i32.clz': 'clz', 'i64.clz': 'clz', 'i32.ctz': 'ctz', 'i64.ctz': 'ctz', 'i32.popcnt': 'popcnt', 'i64.popcnt': 'popcnt'}


def cname(a):
    return RN.get(str(a)) or names.get(a) or f'f{a}'


def memref(a, of, nm):
    t = nm.split('.')[1]
    if '8' in t: ty = 'u8'
    elif '16' in t: ty = 'u16'
    elif '32' in t: ty = 'u32'
    else: ty = 'u64' if nm[:3] == 'i64' else ('u32' if nm[:3] == 'i32' else nm[:3])
    if a == 'SP':
        return f'SP[{of}]' if ty == 'u64' else f'SP[{of}]:{ty}'
    if a.startswith('SP+') and a[3:].lstrip('-').isdigit():
        o = int(a[3:]) + of
        return f'SP[{o}]' if ty == 'u64' else f'SP[{o}]:{ty}'
    return f'{ty}[{a}+{of}]' if of else f'{ty}[{a}]'


def decomp(fi, out):
    o, sz = bodies[fi]; end = o + sz; i = o
    n, i = leb(d, i)
    for _ in range(n):
        c, i = leb(d, i); i += 1
    W = out.write
    W(f'\n######## func[{fi}] {names.get(fi, "")}\n')
    st = []; ctl = []; lab = 0; state_labels = {}; first = True

    def pop():
        return st.pop() if st else '?'

    def tgt(a):
        k, L = ctl[-1 - a]
        return f'loop_{L}' if k == 'loop' else f'end_{L}'
    pend = []  # deferred label names: we need labels before output of block ends; print at end
    lines = []
    W = lines.append
    while i < end:
        op = d[i]; i += 1
        if op in (2, 3, 4):
            i += 1; lab += 1; L = lab
            if op == 2: ctl.append(('block', L))
            elif op == 3: ctl.append(('loop', L)); W(f'loop_{L}:\n')
            else:
                c = pop(); ctl.append(('if', L)); W(f'  if !({c}) goto else_{L}\n')
            continue
        if op == 5:
            k, L = ctl[-1]; ctl[-1] = ('else', L); W(f'  goto end_{L}\nelse_{L}:\n'); continue
        if op == 0xb:
            if not ctl:
                continue
            k, L = ctl.pop()
            if k == 'if': W(f'else_{L}:\n')
            elif k != 'loop': W(('LBL', L))
            continue
        if op == 0xc:
            a, i = leb(d, i); W(f'  goto {tgt(a)}\n'); st = []; continue
        if op == 0xd:
            a, i = leb(d, i); c = pop(); W(f'  if ({c}) goto {tgt(a)}\n'); continue
        if op == 0xe:
            n2, i = leb(d, i); ts = []
            for _ in range(n2 + 1):
                a, i = leb(d, i); ts.append(a)
            c = pop()
            if first:
                first = False
                for sidx, a in enumerate(ts):
                    k, L = ctl[-1 - a]; state_labels.setdefault(L, []).append(sidx)
                W(f'  dispatch({c})\n')
            else:
                W(f'  switch({c}) {[tgt(a) for a in ts]}\n')
            st = []; continue
        if op == 0xf:
            W(f'  return {pop()}\n'); st = []; continue
        if op == 0x10:
            a, i = leb(d, i)
            if a < 20:
                x = pop(); W(f'  JS {names.get(a)}({x})\n'); continue
            t = types[a - 20]
            if t == 0:
                pop(); W(f'  CALL {cname(a)}  [{a}]\n'); st.append(f'ret{a}')
            else:
                np_, nr = TY[t]
                args = [pop() for _ in range(np_)][::-1]
                if nr: st.append(f'{cname(a)}({",".join(args)})')
                else: W(f'  {cname(a)}({",".join(args)})\n')
            continue
        if op == 0x11:
            a, i = leb(d, i); b, i = leb(d, i); c = pop()
            np_, nr = TY[a]; args = [pop() for _ in range(np_)][::-1]
            W(f'  CALLIND table[{c}] ({",".join(args)})\n')
            if nr: st.append('callind_ret')
            continue
        if op == 0x1a:
            x = pop()
            if '(' in x: W(f'  drop {x}\n')
            continue
        if op == 0x1b:
            c = pop(); b = pop(); a = pop(); st.append(f'({c}?{a}:{b})'); continue
        if op == 0x20:
            a, i = leb(d, i); st.append('SP' if a == 1 else ('PC' if a == 0 else f'r{a}')); continue
        if op in (0x21, 0x22):
            a, i = leb(d, i); v = pop(); nm = 'SP' if a == 1 else ('PC' if a == 0 else f'r{a}')
            W(f'  {nm} = {v}\n')
            if op == 0x22: st.append(nm)
            continue
        if op == 0x23:
            a, i = leb(d, i); st.append({0: 'gSP', 1: 'gCTXT', 2: 'gG'}.get(a, f'g{a}')); continue
        if op == 0x24:
            a, i = leb(d, i); v = pop(); W(f'  {"gSP" if a == 0 else "g" + str(a)} = {v}\n'); continue
        if 0x28 <= op <= 0x3e:
            al, i = leb(d, i); of, i = leb(d, i); nm = D.OP[op]
            if 'store' in nm:
                v = pop(); a = pop(); W(f'  {memref(a, of, nm)} = {v}\n')
            else:
                a = pop(); st.append(memref(a, of, nm))
            continue
        if op in (0x3f, 0x40):
            i += 1; st.append('memsize'); continue
        if op in (0x41, 0x42):
            a, i = leb(d, i, True)
            st.append(str(a) if -4096 < a < 4096 else hex(a & (0xffffffffffffffff if op == 0x42 else 0xffffffff))); continue
        if op == 0x43:
            st.append(str(struct.unpack('<f', d[i:i + 4])[0])); i += 4; continue
        if op == 0x44:
            st.append(str(struct.unpack('<d', d[i:i + 8])[0])); i += 8; continue
        if op == 0xfc:
            a, i = leb(d, i)
            if a == 10:
                i += 2; c = pop(); s = pop(); dd = pop(); W(f'  memcpy({dd},{s},{c})\n')
            elif a == 11:
                i += 1; c = pop(); v = pop(); dd = pop(); W(f'  memset({dd},{v},{c})\n')
            else:
                x = pop(); st.append(f'trunc_sat({x})')
            continue
        nm = D.OP.get(op, hex(op))
        if op in (0xa7, 0xac, 0xad):
            continue  # wrap/extend transparent
        if nm in UN:
            x = pop(); st.append(f'{UN[nm]}({x})'); continue
        base = nm.split('.')[-1]
        if base in BI and nm[0] in 'if':
            b = pop(); a = pop()
            if base == 'add' and a == 'SP' and b.lstrip('-').isdigit(): st.append(f'SP+{b}')
            else: st.append(f'({a} {BI[base]} {b})')
            continue
        x = pop(); st.append(f'{nm}({x})')
    # emit, removing labels nobody jumps to
    import re
    refs = set(re.findall(r'end_(\d+)', ''.join(l for l in lines if isinstance(l, str))))
    for l in lines:
        if isinstance(l, tuple):
            L = l[1]
            if L in state_labels:
                out.write(f'STATE {state_labels[L]}:\n')
            elif str(L) in refs:
                out.write(f'end_{L}:\n')
        else:
            out.write(l)


if __name__ == '__main__':
    with open(sys.argv[2], 'w') as out:
        for part in sys.argv[1].split(','):
            ab = part.split('-'); a = int(ab[0]); b = int(ab[-1])
            for f in range(a, b + 1):
                decomp(f, out)
