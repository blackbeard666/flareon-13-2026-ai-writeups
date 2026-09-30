# FLARE-On 13 — Challenge 8: crux

**Status:** ✅ Solved — the flag comes back from the real `check()` in the unmodified `main.wasm`.

**Flag:** `Pr4tt_Pr1M4lItY_C3rt5_4nd_Wa4aA4aAA4aAA4a4a5M@flare-on.com`

## Prompt
> Since you haven't seen natural sunlight in weeks, we ask that you would install a shiny new browser extension on your terminal to keep your remaining few synapses firing. It only asks for one little input string to verify your worth, though our lab notes suggest the underlying code was compiled by someone who genuinely despises humanity. Satisfy its inscrutable standards to dispense your next ration pellet, or stare into the decompiler until the abyss stares back.

## TL;DR
`extension.zip` is a Chrome MV3 popup that loads a **5.8 MB Go WASM** (`main.wasm` + the stock `wasm_exec.js`). The WASM is **garble-obfuscated**: names are stripped, the pclntab magic is randomized, string literals are garbled, and control flow is flattened. `window.check(s)` does the following:

1. Base64-decode the input, **AES-256-CBC** decrypt it (hardcoded key/IV), and strip the **PKCS#7** padding.
2. Parse the plaintext as a binary **tree** of little-endian big integers.
3. Verify the tree as a **Pratt primality certificate**.
4. Require the root prime to equal a hidden 256-bit prime **N**.
5. Use the certificate's SHA-256 to decrypt the flag.

So the job is to write a Pratt certificate for N. N−1 and every prime under it factor in seconds with sympy. The certificate is *canonical* (sorted factors with multiplicity, minimal byte encodings, smallest primitive root as witness), so exactly one input decrypts the flag.

## Layer 1 — the extension
```
manifest.json  popup.html  popup.js  wasm_exec.js  main.wasm (5,836,781 B)  icons/
```
`popup.js` instantiates `main.wasm` with `new Go()` and calls `window.check(input.value)`. Go's `wasm_exec.js` runs as-is in Node once `globalThis.window = globalThis` is set. That gives a local harness (`ext/run.js`), and every wrong input returns `Bad input`.

## Layer 2 — getting a foothold in a stripped, garbled Go WASM
- **The name section is gone and the pclntab is disguised.** garble replaced the magic `0xfffffff1` with `0xa3c41c63`. The header was found at memory offset `0x51660` by looking for the tell-tale `00 00 01 08` (minLC=1, ptrSize=8), followed by `nfunc = 3255`, which matches the Function section's count exactly. Walking the functab recovers names. Functab entry `k` is wasm function `20 + k`, because there are 20 imports. About 90 % of runtime names are blank, but the user packages survive in garbled form:
  - `main.Kd5oA2q`, `main.R3nNAl`, `main.WtD0ajazVx55`, …
  - `LdUZ4Cb.(*wSlIsLQux).Decrypt`: the AES block
  - `YvzC3gavSva3.(*tHAuYBDO1o).CryptBlocks`: CBC
  - `S_aSa0z1.(*ViyKzO).DecodeString`: base64
  - `MoJe3BRG.EdDX96MwDYra`: SHA-256
- **Standard tools choke.** Go-wasm functions are huge `block×N; br_table` state machines. `wasm2wat` wrote a **1.8 GB** file just from indentation, and `wasm-objdump -d` wrote 1.9 GB. `wasm-decompile` crashed.
- **Custom tooling (`work/`):**
  - `wparse.py` builds the memory image from the data segments.
  - `pcln.py` parses the pclntab.
  - `wdis.py` is a flat disassembler.
  - `dec.py` is a **flat Go-wasm decompiler**. It evaluates the stack symbolically, turns `local.get 1 + k` into `SP[k]`, and labels each br_table target `STATE n`. That makes functions like the parser readable in a few hundred lines.
  - `instr.py` is a **binary-rewriting tracer**, described next.
- **Tracing without adding imports.** Adding an import would shift every function index. Instead, `instr.py` puts a hook at the entry of each chosen Go-ABI function (guarded by `PC_B == 0`, so goroutine resumes are skipped) and before every `return`. The hook calls the existing `runtime.getRandomData` import twice: once with a tag (`0x80000000 | fid<<1`, or `0xC0000000` for exit) and once with `SP|1`. Real Go SPs are 8-aligned, so the JS wrapper (`work/trace.js`) can tell hook calls from real ones. It logs arguments at `SP+8`, guesses strings and slices, and dereferences the custom bigint struct.

## Layer 3 — what `check()` actually does
The trace on 64 × `'A'` shows the whole pipeline. Input lengths other than multiples of 64 chars fail earlier, because the decoded data must be a whole number of 16-byte blocks.

| Step | Function | Notes |
|---|---|---|
| base64 | `S_aSa0z1.DecodeString` (3232) | standard alphabet |
| AES-256-CBC decrypt | `LdUZ4Cb.BArYTLDnX` (3184), CryptBlocks (3168) | key `cabeba7a…cdbf8723`, IV `5ff26040…ecf65d91`; `3188` = InvShiftRows. **Confirmed standard AES:** `AES_dec(k, 0¹⁶) = 9ba0147d…` matches `cryptography` |
| unpad | `LdUZ4Cb.DMCmloGmZ` (3190) | PKCS#7 (`"invalid padding byte"`) |
| hash | `MoJe3BRG.EdDX96MwDYra` (3217) | SHA-256(plaintext), later used to decrypt the flag |
| parse | 3267 | recursive binary tree parser (below) |
| verify | `main.Kd5oA2q` (3269) | Pratt certificate check (below) |
| target | 3270 → 3252 + 3254 | root prime must equal the deobfuscated 32-byte constant **N** |
| flag | 3272 / 3184 / 3190 | AES-decrypt the flag blob with material derived from the hash |

### The bigint type
Custom arbitrary-precision integers, `struct { neg u8; digits []byte }`, with digits stored little-endian:
- `R3nNAl` (3251) = `NewInt(int64)`
- `WtD0ajazVx55` (3252) = `FromBytes(b, neg)`. It **rejects a nonzero-length value whose top byte is 0**, so every number has exactly one encoding.
- 3254 = `Cmp`, 3256 = add, 3257 = sub, 3258 = mul. 3253/3259–3263/3268 are the division, modpow and witness machinery.

### Serialization grammar (func 3267)
```
cert  := 0x00                                    -- leaf: the prime 2 (must be exactly 1 byte)
       | 0x01 u32le(n)  n × ( u32le(len) cert )   -- children = certificates of the prime factors of A-1
              u32le(len) A                        -- the prime, canonical LE bigint
              u32le(len) B                        -- the witness, canonical LE bigint
```
Every length is bounds-checked, and a node must consume its buffer exactly.

### The verifier (func `Kd5oA2q`) = Pratt certificate
`value(leaf) = 2`, `value(node) = A`. For a node:
1. Every child certificate is valid (recursive).
2. Children are **non-decreasing** (`Cmp(v, prev) < 0` → reject), and their **product with multiplicity equals A − 1**.
3. `3268(B, A, children)` holds, i.e. B is a primitive root (Lucas test: `B^((A−1)/q) ≠ 1` for each prime q, `B^(A−1) = 1`). A second loop over witnesses rejects the certificate if a *smaller* value also passes. I read that loop as enforcing the **smallest** primitive root. The chosen witnesses were accepted, but I didn't test other witnesses to confirm they're rejected.

Constraints 2 and 3, plus canonical bigints, make the certificate for a given prime **unique**. That matters because the flag key comes from SHA-256 of the certificate bytes.

A 20-byte certificate for 3, `01 01000000 01000000 00 01000000 03 01000000 02`, passed the verifier. It then reached the comparison against N, which gave away the target:

```
N = 0xd389dfbb379a02ccda7a4ab0b327e8e3655a3c96447c1b5578bee179c930e261   (prime, 256-bit)
N-1 = 2^5 · 1777 · 117013415621 · 14379885447462257985539844615548173977763374139182362877999463
```

## Layer 4 — building the certificate
Factor down the tree with `sympy.factorint`: 50 distinct primes (49 factorizations). The largest steps were the 256-bit N−1 (0.8 s) and the 204-bit q−1 (6.2 s). Emit each node's children sorted and with multiplicity, `A`, and the smallest primitive root. Then serialize, PKCS#7-pad, AES-256-CBC-encrypt and base64-encode.

The result is a **3,891-byte** certificate, or a **5,208-char** input. `check()` takes about 15–28 s on it (lots of bigint modpow in WASM) and returns the flag.

```mermaid
flowchart TD
    A[extension.zip<br/>MV3 popup + Go WASM] --> B[garble-stripped main.wasm<br/>pclntab magic 0xa3c41c63 → names]
    B --> C[flat decompiler dec.py +<br/>getRandomData-hijack tracer]
    C --> D["check(s): base64 → AES-256-CBC dec → PKCS#7"]
    D --> E[parse: 0x00 leaf=2 / 0x01 node {children, A, B}]
    E --> F[Kd5oA2q: Pratt certificate<br/>sorted factors · ∏=A−1 · minimal primitive root]
    F --> G[root A == N 0xd389dfbb…c930e261]
    G --> H[sympy: factor N−1 recursively<br/>50 primes, ~7 s]
    H --> I[canonical cert 3,891 B → AES → base64 5,208 chars]
    I --> J[FLAG Pr4tt_Pr1M4lItY_C3rt5_4nd_Wa4aA4aAA4aAA4a4a5M@flare-on.com]
```

## Reproduce
```bash
cd 8-crux-attempt-2
"C:/Program Files/7-Zip/7z.exe" x -pflare 8-crux.7z -oext && cd ext && unzip extension.zip -d x && cd ..
python solve8.py --run     # -> Pr4tt_Pr1M4lItY_C3rt5_4nd_Wa4aA4aAA4aAA4a4a5M@flare-on.com
```
`solve8.py` is self-contained: sympy factoring, certificate builder, AES wrap. `--run` feeds the input to the untouched `main.wasm` through `ext/run.js`.

## First attempt (unsolved) — what went wrong
An earlier multi-agent session (`8-crux/`, Opus 4.8 then continued on Opus 4.8/Fable 5/Opus 5.5, ~24 h+ of wall clock across a compaction, ~4.3 M+ output tokens) got the AES layer and the parser grammar right. Its **early** phase burned budget on two wrong assumptions:
- **Message length pinned to 32–47 bytes (one 48-byte ciphertext).** Nothing requires that: the real certificate is 3.9 KB.
- **3269 was modeled as an "S-expression arithmetic evaluator" with a treap.** It's a primality-certificate verifier. It was attacked as a flag byte-VM, and parts of the 1,800-state `3270` flag decoder were reversed by hand, when the flag appears on its own once the certificate is valid.

Its **later/continuation** phase actually recovered the correct model — Pratt certificate of the 256-bit prime N, `flag = pkcs7_unpad(AES-dec(fixed CT, SHA256(M), IV))`, all fields forced — and even proved full branch coverage of the `3270` decode. But it got trapped for many hours on **one wrong byte in the leaf encoding**, the single most instructive mistake of the whole set:

- **The crux bug: it encoded the prime-2 leaf as a 14-byte `0x01`-node** `01 00000000 01000000 02 00000000` (a childless node with key=2 and an empty value field) **instead of the canonical single `0x00` byte.** The verifier's `value()` returns 2 for *both* forms, so the non-canonical cert *passed the verifier and reached the final AES* — masking the error. But it made the cert 6,699 bytes instead of 3,891, with a **different SHA-256**, so the flag key was always wrong.
- Because the `0x01`-node form carries a value field the verifier ignores, the session concluded there were "216 free leaf-value bytes" and spent enormous effort — a validated SHA-NI brute over the entire uniform 4-byte space, ~50 deterministic value conventions, modexp-residue analysis, and full state-coverage instrumentation — hunting a **SHA-256 preimage that never existed.** With the correct `0x00` leaf there is no free field at all; the certificate is unique and deterministic.
- **Lesson:** "passes the checker" ≠ "canonical." When a downstream step hashes the *raw input bytes*, a lenient parser that accepts multiple encodings of the same value will happily verify a non-canonical input that then hashes wrong. Re-read the grammar for the *minimal/expected* encoding of every terminal (here: the leaf is literally one `0x00` byte), don't just find *an* accepted encoding.

The second attempt (this write-up) started fresh in `8-crux-attempt-2/` and got to the flag in about 19 minutes. What made the difference:
- Tracing **arguments and bigint values** at every call gave concrete data, instead of modeling the state machines.
- **Building a tiny valid input first** (the certificate for 3) exposed the target prime directly, so the flag decoder never had to be reversed.
- Reading the parser grammar precisely, so the leaf was the canonical `0x00` byte from the start.

(A later continuation of the first-attempt session independently re-derived the whole mechanism and, once shown the `0x00`-leaf grammar, reproduced the flag byte-for-byte through the unmodified `main.wasm` — confirming this write-up.)

## Tooling used
- `wabt` (npm), but only for `wasm-objdump -x`; its disassembler, decompiler and wat printer can't handle garble's nesting depth.
- Custom Python: `wparse.py` (sections, memory image), `pcln.py` (garbled pclntab), `wdis.py` (flat disassembler), `dec.py` (Go-wasm state-machine decompiler), `instr.py` (entry/exit hook rewriter).
- Node 24 + stock `wasm_exec.js`: `ext/run.js` runner and `work/trace.js` tracer.
- `cryptography` (AES-CBC), `sympy` (primality, `factorint`).
