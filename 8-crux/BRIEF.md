# Challenge 8 "crux" — shared brief (established facts)

Dir: `C:\Users\cavila\Desktop\ctf\flareon13-2026\8-crux\`. Go 1.26 WASM compiled with garble (flattened
state machines: `loop{ block*N; local.get 0; br_table[...] }`, state var = local0).

## Tools
- `python wdis.py <absfuncidx>` → disassembly (num_imp_funcs=20). Redirect to a file for big funcs.
- `node run.js "<base64input>"` → runs check(), prints result ("Bad input" or flag).
- Oracle: `main_instr2.wasm` has `env.trace(idx,sp)` called at EVERY function entry (idx=original abs func index, sp=Go stack pointer). Build a message and feed via check(mk(msg)); see cap3269.js/cappair.js for the harness + `dumpIface` tree reconstructor.
- Build msg→input: AES-256-CBC encrypt. key=`cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723`, iv=`5ff26040c4c20b9f2ffdefa7ecf65d91`. `mk(msg)` in cap*.js: pad msg to 48 with PKCS#7-style (padlen byte), AES-CBC enc, base64. msg length must be 32..47.

## Stage 1 (SOLVED)
input = 64 base64 chars → 48-byte ct → AES-256-CBC decrypt → 48B → PKCS#7 unpad → message M (32..47 bytes).
SHA-256(M[:32]) also computed (func 3217, then AES func = 3190).

## Parser grammar (func 3267, SOLVED)
M is ONE tree consuming all bytes. node = 0x01 || u32le(childCount) || childCount×(u32le(childByteLen)||subtree)
|| u32le(keyLen)||key || u32le(valLen)||val. key/val = canonical little-endian big-ints (empty=0; if
non-empty, last byte must be !=0 else func3252 rejects). Parser builds nested Go interfaces of 3 itab types:
- 0x4ef80 = VALUE/atom (wraps a big.Int; node key & value each become this)
- 0x4ef60 = PAIR [car,cdr] (cons cell; typehash 0x83c733b)
- 0x4ef40 = NIL/empty list (typehash 0xb49d0978)
A node with children becomes a cons LIST (PAIR chain) of its children; a leaf node's key/value become VALUE atoms.

## Eval (func 3269) — recursive evaluator (state graph decomposed; see below)
Frame = local1, size 0xd0 (208). Arg interface at off216(itab)/off224(data). Returns i32 code; writes
result interface + ok-bool back to caller's arg slot. Helpers: 3251, 3254, 3256, 3257, 3258, 3268.

### CONFIRMED helper semantics (custom base-256 little-endian big.Int; struct {neg@0, abs.ptr@8, abs.len@16, abs.cap@24}):
- func 3251 = `makeBigInt(n int64) *BigInt` (big.NewInt equiv). arg int64 @SP+8, returns *BigInt @SP+16. NOT an accessor. Used to materialize integer constants/counters. Pair car/cdr are read by DIRECT memory loads from the memcpy'd 40-byte pair at frame+0x70 (car iface @+0x70, cdr iface @+0x80), not via a function.
- func 3254 = `Cmp(a,b *BigInt) int` = sign(a-b) ∈ {-1,0,+1}. a@SP+8, b@SP+16, result@SP+24.
- func 3256 = signed ADD `z=x+y` (*BigInt). x@SP+8,y@SP+16,z@SP+24.
- func 3257 = signed SUB `z=x-y` = x+(-y).
- func 3258 = signed MUL `z=x*y` (schoolbook, sign=neg⊕neg).
=> func 3269 is a big.Int ARITHMETIC EXPRESSION EVALUATOR over an S-expression tree (Add/Sub/Mul/Cmp/NewInt).
State→segment via br_table. Segments (T##) and flow (FALL=fall through to next on success, JMP=br back to
loop dispatch, fail branches set an error state):
- T00-T02 (st0-3): require arg is PAIR (itab 0x4ef60, typehash 0x83c733b) else code13/9.
- T03-T05 (st4-8): memcpy pair.data(40B)→frame+0x70; 2× call 3251; set off64=limit, off184, state=17.
- T11 (st17): depth check: if off56+1 >= off64(limit) → state 70 (BASE CASE, leads to SUCCESS T40-T44); else FALL (recurse).
- T12 (st18/19): call 3269 RECURSE on a sub-node. FALL.
- T13-T16: require recurse result is PAIR+ok else 68/37/30. 
- T17 (st28/29): memcpy result→frame+0x48; state=38.
- T23 (st38-40): call 3254. T24: check (fail 66). T25 (st42/43): call 3258. T26 (st44-47): call 3268(treap). 
- T27 (st48): check (fail 64). T28 (st49/50): call 3251. T29: state=58.
- MAIN LOOP: T30(st53/54,call3251) → T31(call3256 compare) → T32 → T33(call3254) → T34(check<0 fail15) →
  T35(call3268) → T36(st63: branch state82=EXIT or state53=LOOP again).
- SUCCESS returns ok=1: T08 (st12) and T44 (st79/80). T44 reached via base case T40(3251)→T41(3257)→T42(3254)→T43→T44.
- FAIL returns ok=0: T09(st13/14),T37,T38,T39,T45,T46(st82/83).

## Accept condition (func 3270, post-eval, VERIFIED @0x4a00-0x4ae1)
After call 3269: (a) result ok-byte != 0; (b) result interface itab != 0, typehash==0x83c733b, itab==0x4ef60 (PAIR);
(c) memcpy result.data(40B)→frame+0x2a0; cdr must be NIL (0xb49d0978). => eval must return [car, nil] (1-elt list).
Then getWithKey = call 3251 @0x4ae1 extracts car; byte39 of looked-up value feeds the flag decode.

## Flag decode (func 3270, 0x4b7a onward) — deterministic byte-VM + final AES
Static blobs: blob@0x469f7(32B), blob@0x469d7(32B), schedule@0x4efa0(32B). Globals: 0x20aba0=0x3bdfe0e3eb80a09e,
0x20aba8=0x45, 0x20abb0=ptr 0x20a6a0, byte@0x20ab72. Many byte xor/add/sub transforms + an index-gather
(0x4f4f: control bytes buf+0x11d..0x11f index into buf+0x120, bounds-checked <32 else fail). Then calls
3272/2992 (bigint decimal), 3252, 3254, 3166, 3184, and finally AES func 3190 @0x6dc4 → the flag string.
The flag depends on the eval result via one looked-up byte feeding the AES key. mem_after.bin = full memory dump
(has all static blobs at their offsets).

## DYNAMIC ORACLE FINDINGS (agent ac282, confirmed via main_instr2.wasm 3190-count)
- Accept signal: count of AES func 3190 per check(). ==1 → eval rejected (only stage-1 decrypt). >=2 (or 3272/2992 firing) → accepted/final decrypt reached.
- Grammar budget is tiny (32-47B). Feasible programs: `list[leaf(K,V)]` with |K|+|V|<=17; `list[leaf,leaf]` (all-zero, 47B); `list[list[leaf]]` chain (all-zero, 47B).
- THE OPERATOR/OPCODE = the leaf's KEY (VAL never selects behavior). Keys 0,4..300 → generic reject ("Bad input"). Keys 1,2,3 are SPECIAL.
- Key=2 is the furthest: engages func3268 + extra Cmp/Add, then the Go program does os.Exit(2) (NOT a printed panic — silent hard exit; check() returns undefined). Key=3 same. => opcode 2 is a real binary operator that hard-exits when given wrong/insufficient operands. Need the right operand structure.
- NO accepting input found in the naive single-(key,val)-leaf encoding.
- run.js helpers: `node run.js "<b64>"`. Build trees with node()/leaf()/bigLE() (see dumptree2.js/panicmsg.js/oracle_map.js). Gate-bypass artifact `main_gatebypass.wasm` (patches func3270 gate fail-states 862/844/837→845): reaches the decode but fails at the decode-internal integrity check 0x60a0 (call 3254 Cmp result must==0), confirming the flag needs the CORRECT accepting input (decode is not trivially static).

## ARITHMETIC TRACER BREAKTHROUGH (arith_trace2.js / at4.js — hook helper entries, read *Int operands from memory)
Feeding trees and reading the big.Int operands reveals the eval computation directly. CONFIRMED:
- Every node's KEY is the OPCODE. eval(node): computes `Cmp(1, key-1)` and requires ==0 → KEY MUST BE 2 for any valid node. (keys 1,3 fail this; key 2 is the only operator.)
- A node is `(key=2, val=a0, children=[...])`. After the key check it calls `PRED(a0=node.val, a1=eval(firstChild)=2 for a leaf child, list=children, n=childCount)` = func3268.
- eval(leaf key=2, no children) = 2 (the axiom / base value). So children (operands) must themselves be key=2 nodes; recursion builds numbers.
- PRED (func3268) does: d=Sub(a1,1); DivMod(a0,d); Cmp(quot,1); then loops over list doing Sub/DivMod/Cmp — a recursive certificate/primality-style verifier. With a leaf child (a1=2 → d=1) DivMod(a0,1)=a0 trivial; malformed operands cause DivMod(x,0) → Go os.Exit(2) hard crash (seen with wrong children).
- Message MUST be 32..47 bytes and parse as ONE tree. node min=13B; a `(key=2,val,1 child)` node = ~32B fits; 2 explicit children = ~48B just over. So the accepting certificate must be compact.
- Base case (eval T40-T44): Sub then Cmp(target,X)==0. For a leaf, target=1 → requires key-1==1 → key=2. Need to find if a larger embedded target is checked for the full program.
Tools: `node at4.js "<jsExpr building tree via nd(children,k,v)>"` prints the full arithmetic op log incl PRED(a0,a1,n,list). nd/leaf/bLE builders inline. Verify final answers with `node run.js "<b64>"`.

## EVAL FULLY SOLVED (Pratt primality certificate)
- func3262 = MODULAR EXPONENTIATION base^exp mod m (NOT DivMod). func3261 = makeValue.
- The tree is a recursive PRATT PRIMALITY CERTIFICATE. Node = {Children[], key=prime p, val=witness g}.
- Leaf (axiom for 2) = node(children=[], key=2, val=<free>). For odd prime p: node(key=p, val=g, children=[cert(q) for each prime factor q of p-1 WITH multiplicity, sorted ASCENDING]). eval enforces ∏children=p-1, ascending order, and Pratt test g^(p-1)≡1 and g^((p-1)/q)≢1 mod p for each q.
- The eval USES the provided val as the witness AND requires it to be the SMALLEST valid primitive root (certP2 with top witness=5 (a valid primitive root, but not smallest=3) is REJECTED before AES#2; certP with witness=3 reaches AES#2). So witnesses are FORCED = smallest primitive root (sympy.primitive_root).
- TARGET PRIME P = 95681613235744740119807961018865688051340183696570761153419351987106658443873 (256-bit).
  P-1 = 2^5 · 1777 · 117013415621 · 14379885447462257985539844615548173977763374139182362877999463.
- BUILD: build_cert.py produces certP.hex/certP.b64 (leaf val=0). It PASSES the eval and reaches the flag decode.
- MESSAGES ARE NOT capped at 47 bytes: pad M to next multiple of 16 (pad byte = padlen, 16 if already aligned), AES-CBC-encrypt with stage-1 key/iv, base64. certP.b64 = the eval-passing input (~8940 b64 chars).

## FLAG DECODE STATE (func3270 0x4b06→end) — NOT fully cracked
- func 3184 = AES key-expansion (NewCipher); receives the 32-byte key at sp+8. func 3190 = AES-CBC (sp+8=plaintext, sp+40=ciphertext; for decrypt sp+8=output). Two AES calls total: #1 = stage-1 decrypt (key=stage1 static), #2 = final @0x6dc4.
- **KEY FINDING: AES#2 key = SHA-256(M)** (M = the entire decrypted message bytes). Verified: sha256(certP bytes)=a1c0cf649ab8c16f8ade1d226bd804884463fc7afc0f134d652202a04606e3b9 = captured AES#2 key.
- **AES#2 ciphertext is FIXED = 78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232f** — identical across leaf-val variants; depends only on P/structure, NOT on M's free fields. (It is NOT in the static data section — it's computed by the byte-VM from static blobs 0x469f7/0x469d7 + P's decimal (func 3272 = bigint→decimal, 0xcccccccd) + M.)
- AES#2 decrypt output for certP = b757e1cbcc569f8b53eb945b80e071e7... (garbage) → post-AES check fails → "Bad input".
- Leaf val is NOT checked by eval/decode (lv=0/1/2 all reach AES#2, same ct, different key). Brute of uniform leaf val 0..255 → no flag in AES_dec(ct, SHA256(M)) blocks 2-3.
- After AES#2 (0x6dc7→end): checks off56!=0 (fail code 1414), reads globals 0x20abb0(byte60/off112/off40), 0x20ab98(u16), stores const 0x6c606940640f5c34, calls 291(alloc) — MORE processing/validation. The flag construction is multi-step, not just AES#2 output.

## OPEN: reverse the decode's full flag construction (0x4b06→end): what SHA-256 is computed over exactly, how the fixed ct is derived from P, how the AES#2 output is validated/transformed into the flag, and whether M's leaf val (or another field) is uniquely determined. Tools: at4.js, decdump3.js, getkey.js, chkaes.js (AES#2 ct/key capture), findkey2.js. certP.b64 is the eval-passing input to trace the real decode.

## Flag is GATED, not static
Flag decode (func3270 0x4b7a→AES 3190 @0x6dc4) reads static blobs + globals + decode-internal integrity checks (0x60a0: Cmp==0). Bypassing the eval gate reaches the decode but fails integrity. => must find the real accepting message M so the eval returns [value,nil] and the natural flow computes the flag.

## Goal
Determine the accepting message M (tree/program) that makes eval return [car,nil] with the RIGHT looked-up
value, so the final AES decrypt yields the flag `...@flare-on.com`. Verify ONLY via `node run.js`.
