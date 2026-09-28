# FLARE-On 13 — Challenge 7: FlareCalc

**Status:** ✅ Solved — flag recovered **fully offline** from `FlareCalc.exe`.

**Flag:** `t3mplat3s_asn_and_j1t_0h_my@flare-on.com`

## Prompt
> A basic Windows calculator. Or is it? `FlareCalc.exe` is quietly plotting your demise.

## TL;DR
`FlareCalc.exe` is a heavily-obfuscated native x64 GUI calculator that is **99 % decoy**. Its real payload is an **x64 implant hidden inside its Authenticode certificate**: the signing cert carries a custom extension **OID `1.3.6.1.4.1.1337.1`** = a **1035-entry `{u16 key, octet-string blob}` map**. A hidden self-loader in the calc maps its own cert as RWX and calls a stub embedded at cert-offset `0x6d3a`, passing a 16-byte argument derived from **three numbers on the calculator's stack**. That stub is a bespoke **VM/packer**: every "blob" is unpacked with `deinterleave(xor(blob, MD5-fold), PRNG(input))`. The unpacked stages form a **bind-shell backdoor**; its `'3'` command walks a **32-blob "labyrinth"**, mutating a key buffer, until it reaches an **XTEA** decryptor that decrypts the embedded ciphertext blob `9990` → the flag, sent to the calculator window over `WM_COPYDATA`.

The whole thing is recoverable statically: recover the de-interleave **seed** by brute force, recover each blob's XOR **fold** by frequency analysis, solve the labyrinth chain to derive the XTEA key, and decrypt.

## Layer 1 — the calculator (mostly decoy)
Native x64 Win32 GUI, obfuscated with opaque predicates (`v + K1 ^ K2` with a runtime-zero base `DAT_1400e9228`, junk `do{i++}while(i<N)` loops). Four troll easter-egg expressions (`525+193`→`FLAG{NICE_TRY}`, `742*186`, `931-482`, and `843*952`→a marquee **rickroll** delivered to itself via `WM_COPYDATA` magic `0xC3F12A8B`). These are red herrings — but the rickroll demonstrates the exact primitives (hash-resolved APIs, threads, `WM_COPYDATA` IPC) the real loader uses.

**The hidden self-loader** (the part easy to miss — the calc imports look innocuous because APIs are resolved by hash at runtime):
- `FUN_140001560` = GetProcAddress-by-hash (rolling hash `h = h*0x21 + c`); `FUN_140002000` PEB-walks for kernel32; a CRT static-init thread wires it all up at startup.
- `FUN_1400019d0` = **self-cert loader**: `GetModuleFileNameW` → parse own PE → `CreateFileW`/`SetFilePointer` to the security directory → `VirtualAlloc(PAGE_EXECUTE_READWRITE, 0x8149d)` → `ReadFile` the cert into RWX → **`(*(cert + 0x6d3a))(A<<32|B, C)`**.
- `FUN_140002a90` (calc op `0xC000008E`) pops **3 numbers** `n1,n2,n3` off the calc stack and builds the argument: **`A = (int)n1`, `B = (int)n2`, `C = (int)(n3 × 10,000,000)`** (`K1=K2=1`, `K3 = 0x2f030e60 ^ 0x2f9b98e0 = 10000000`), packed as `param1 = (A<<32)|B`, `param2 = C`. So the implant's secret input is the string `"A-B-C"`.

## Layer 2 — the payload (cert-embedded implant)
The cert (file offset `0xEEC00`, size `0x814A0`) is both a real PKCS#7 signature **and** an x64 module. Blob key **3821** is the plaintext loader `.text` (its entry is the stub at cert-offset `0x6d3a` = `FUN_140000000`). Blobs `3822`+ are **encrypted stages**; ~1024 other blobs are decoys (clustered repetitive lengths).

**The unpack pipeline** for any blob `key`, given the implant input string:
```
blob  →  xor_decrypt( key16 = MD5(input ‖ u32le(key)) )   # fold = one byte of MD5, LCG keystream b=b*0x6d+0x39
      →  deinterleave( keep 1 byte, skip (rng%3)+1 )       # rng = glibc LCG, seed = func_0x9070(input)
```
`func_0x9070`: `s=0x2437; s = s*0x81 + c`. `MD5`-fold: `f=0; for k in md5: f=(f*0x1f+k)&0xff`.

## Cracking it statically (no runtime, no live C2)
1. **Recover the de-interleave seed.** The seed is `func_0x9070(input)` — a 32-bit value covering *any* input. Brute all `2^32` seeds in C; oracle = "does the largest code blob (`3829`) fully linear-disassemble as valid x64?" (calibrated on the plaintext loader `3821`, which decodes cleanly with no invalid opcodes). A 256-byte code-digram pre-filter keeps it fast. → **`SEED = 1116755918`**, confirmed by *all* code blobs decoding cleanly (and later by 5 more blobs whose filler bitmaps match its keep/skip pattern).
2. **Recover each blob's XOR fold.** The fold is one byte (only 256 options). Real x64 code has a strong excess of common bytes (`0x48`, `0x8b`, …), so the correct fold pops out at ~10σ by frequency. e.g. `3822→146, 3824→116, 3827→90, 3829→190, 4485→226, 9990→90`.
3. **Unpack everything.** With `SEED` + brute-fold, all stages disassemble as clean MSVC x64 — a **bind-shell backdoor** (`socket`/`bind`/`recv`/`send`/`gethostname`, all resolved by a rot-left-7 name hash). Handlers: sysinfo beacon (`3829` = `sprintf "[+] Hostname: %s …"`), OS-name via registry (`3827`), cpuid/timing anti-VM gates (`52090`, `3831`, `9055`, `46774`), and two **XTEA** decryptors (`3833`, `4485`, delta `0x9e3779b9`, 32 rounds, key = `keybuf[0:16] ⊕ keybuf[16:32]`).
4. **Solve the `'3'`-command labyrinth.** The `'3'` command reads bytes; each byte runs the current handler blob, which mutates a 32-byte `keybuf` and returns the *next* blob key. Only one input byte per step keeps the chain landing on a valid blob key — a DFS finds the unique 32-byte path **`FLAREON_ASN1_Labyrinth_Key_2026!`**, ending at blob `4485` with `keybuf = 670daa0f…e87c013d`.
5. **Decrypt the flag.** The terminal runs `XTEA_decrypt(blob 9990, keybuf)`. Blob `9990` unpacks (SEED, fold 90) to a **40-byte** ciphertext = 5 XTEA blocks. Running the *actual* blob `4485` code (emulated with Unicorn) on it yields the 40-char flag.

```
blob 9990 (SEED,fold90) = 64c3d61fe488f41b…c348f0ff49c07783
XTEA_decrypt(·, keybuf) = t3mplat3s_asn_and_j1t_0h_my@flare-on.com
```

```mermaid
flowchart TD
    A[FlareCalc.exe<br/>obfuscated GUI calc = decoy] --> B[hidden self-loader FUN_1400019d0<br/>APIs resolved by hash]
    B --> C[map own Authenticode cert RWX<br/>VirtualAlloc + ReadFile]
    C --> D["call cert+0x6d3a (blob 3821 entry)<br/>arg = A«32|B , C from 3 calc numbers"]
    E[cert OID 1.3.6.1.4.1.1337.1<br/>1035 {key,blob} = map_entries.pkl] --> D
    D --> F[VM unpack: xor(MD5-fold) + deinterleave(PRNG input)]
    F --> G[recover SEED=1116755918 by 2^32 brute<br/>+ per-blob fold by frequency]
    G --> H[bind-shell backdoor stages<br/>socket/bind/recv/send + XTEA]
    H --> I["'3' command: 32-blob labyrinth<br/>input FLAREON_ASN1_Labyrinth_Key_2026!"]
    I --> J[keybuf 670daa0f…e87c013d]
    J --> K[blob 4485 XTEA-decrypt blob 9990]
    K --> L[FLAG t3mplat3s_asn_and_j1t_0h_my@flare-on.com]
```

## Reproduce
```bash
cd 7-flarecalc && python solve7.py     # -> t3mplat3s_asn_and_j1t_0h_my@flare-on.com
```
`solve7.py` unpacks blob 9990 (`SEED`, fold 90) and runs the real blob-4485 XTEA (via Unicorn) with the labyrinth-derived `keybuf`. Supporting: `map_entries.pkl` (parsed cert map), `chain_dfs.py` + `chain_result.pkl` (labyrinth solver / result), `seedscan.c` (2^32 seed brute), `unpack.py` (deinterleave/xor helpers).

## Tooling used
- `pefile` / `cryptography` — PE + Authenticode cert parsing; ASN.1 extension → `map_entries.pkl`.
- **Ghidra 12.1.2** headless — decompiling the calc loader and the unpacked implant stages.
- `capstone` — x64-validity oracle for seed recovery; **`unicorn`** — running the real XTEA/handler code without the input.
- `ziglang cc` — the `2^32` seed brute (`seedscan.c`) and MITM helpers.
