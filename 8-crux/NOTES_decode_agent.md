# crux — decode reversal notes (agent, this session)

## Confirmed pipeline (func3270, flattened state machine; state var = local0, dispatch br_table @0x0557)
1. stage-1: AES-256-CBC-dec(input) -> M (cert bytes). key=SHA256(M) computed (a1c0cf... for certP).
2. parse M -> tree; eval (func3269) = Pratt cert for P (forced). certP PASSES eval + accept.
3. accept @0x4a00-0x4ae1: result must be PAIR [car,nil]; car extracted; makeBigInt(2) @0x4ae1 (3251=makeBigInt, NOT getWithKey).
4. **byte-VM decode is STATIC** (states 845/1199/1196/1205, code 0x4b06-0x5f94):
   - copies blob@0x469f7 (32B, static) to sp+240
   - control table = schedule@0x4efa0 (32B, static) = 1508180608191f19081a1a03091f0c020b021104140810071f02100a11131b13
   - byte39 = mem[*(0x20abb0).off112 + 39] = 0xe3 (static)
   - transforms sp+240 -> **P** (95681...873). VERIFIED sp+240 == P.little_endian(32).
   - I initially mistook schedule@0x4efa0 for "eval result control bytes" — it is STATIC.
5. integrity @0x60a0: Cmp(claimed_P, decoded_P). **Cmp==0 (equal) -> state 1378** (certP path). Cmp!=0 -> 0x60bc.
   - captured: last 3254 = Cmp(P, P) = 0. This FORCES P == 95681... (only that prime reaches AES#2).
6. state 1378 handler (0x6a37-0x6dcf): globals -> stack; 3272 (decimal of P); keyexp#2 @0x6b8b (key=SHA256(M)); 3166 @0x6c96; AES#2 @0x6dc4.
   - **AES#2 = AES-256-CBC-DECRYPT(ct=78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232f, key=SHA256(M), iv=5ff26040c4c20b9f2ffdefa7ecf65d91)** = b757e1cbcc569f8b53eb945b80e071e7... (garbage for certP). VERIFIED offline: CBC-dec with iv=5ff2 reproduces b757 exactly.
   - ct is P-derived/static (identical across leaf-val variants).
7. off56 check @0x6dcf: `if mem[sp+56]==0 -> state 1414 else -> "Bad input" builder (state 1678)`.
   - off56 = 0x4ef80 (VALUE itab) for certP AND certP_lv1/lv2 (structural; NOT plaintext-dependent).
   - certP: off56!=0 -> state 1678.

## "Bad input" builder (states 1678->1675x6->1684, code 0x6ebf-0x7f6e)
- template consts 0x6c606940640f5c34 @0x6ebf, 0x9088936c60694064 @0x6ed0 -> permutation/XOR loop (index table 0x0a04000604070204 @sp+72) -> spells "Bad input" (VERIFIED by dumping the buffer byte-by-byte as it decodes to `.Bad input`).

## Flag build candidate (0x60bc, Cmp!=0 path): memory.copy blob@0x45b9a (28B) -> sp+212, transforms w/ static globals (0x20abb0 off41=0x75, 0x20ab90) -> 0x67xx 14-byte gather (bounds<28) -> return @0x6a35.
- Forcing certP down this path (nop integrity i32.eqz @0x60af) -> returns "Bad input" (so blob@0x45b9a likely = an error string too, OR needs correct data).

## GATE-FORCING RESULTS (all via patched wasm, certP input)
- invert integrity (Cmp) -> "Bad input"
- invert off56 (force state 1414) -> "" (empty). state 1414 uses a garbage pointer (local2=0x1c4c0000) for certP.
- => forcing paths does NOT yield flag; the flag build needs correct DATA that only the true accepting input provides.

## KEY BLOCKER / CONTRADICTION (needs fresh analysis)
- certP passes eval+accept+integrity, reaches AES#2, but off56=0x4ef80 (structural) -> "Bad input", DETERMINISTICALLY.
- off56 identical for leaf-val variants (lv0/1/2) -> leaf vals do NOT change the outcome.
- P, structure, witnesses (smallest primitive root) are all forced -> eval result is fixed for certP.
- => a standard Pratt cert for P deterministically -> "Bad input". The flag path (off56==0, state 1414) is never taken.
- Open question: what makes off56==0? off56 (mem[sp+56]) = 0 at 0x6b0a (before AES setup) but 0x4ef80 at 0x6dcf (after). Set during 3272/keyexp/3166/AES region. It is the itab of some VALUE interface. The correct accepting input must make this interface nil (itab 0). This likely means the eval must return a DIFFERENT car (not a VALUE atom), OR there is an aspect of the correct input not captured by the Pratt-cert-with-empty-leaf-vals model.

## Static data (from mem_after.bin)
- blob@0x469f7 (32B): 61e20712920aa233bc316ccb233c9f65faf5275bdacf7ada331adf2e31df8963  (-> P via schedule+byte39)
- blob@0x469d7 (32B): 4648e91eab15127b31c56b58ebd16a73fb17d5ac735272970a2728cfbeacd5b8
- blob@0x45b9a (28B): bd0debc44752680f096112f88825490735d84859b9f00e3c343f34d5
- schedule@0x4efa0 (32B): 1508180608191f19081a1a03091f0c020b021104140810071f02100a11131b13
- byte39 (mem[0x209b80+39]) = 0xe3 ; globals 0x20aba0=0x3bdfe0e3eb80a09e, 0x20aba8=0x45, 0x20abb0->0x20a6a0
- "Bad input" string @0x30fdd9

## Verification
- `node run.js "$(cat certP.b64)"` => "Bad input" (literal, confirmed).
- All leaf-val brute (uniform 0..255, via check()) => "Bad input".

## Tools written this session (z_*.js / z_*.py, main_*.wasm patched variants)
- z_patch_state.py -> main_state.wasm/main_state2.wasm: inject state-trace (900000+state) + local2 into func3270 dispatch.
- z_patch_off56.py -> main_off56.wasm: log mem[sp+56] at 0x6dcf.
- z_dec.js/main_dec.wasm: capture sp+240 (decoded=P) and sp+672 (schedule) at integrity.
- z_globcmp.js: proves globals 0x20abb0/0x20ab98/0x20ab50 are static across inputs.
- main_flagpath.wasm / main_off56flag.wasm: gate-inverted variants.
