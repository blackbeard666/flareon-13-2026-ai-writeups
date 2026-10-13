# Replication Guide — FLARE-On 13 (1–9)

How to reproduce each solve from the provided archives.

## Environment
- **OS:** Windows 11 (x64). A Linux box works for most static steps, but the Frida/harness dynamic steps assume Windows.
- **Archives:** each challenge ships as a `.7z`; **password is `flare`**.
  ```bash
  "C:/Program Files/7-Zip/7z.exe" x -pflare 5-catthief.7z
  # WIMs (challenge 2) need alternate data streams:
  "C:/Program Files/7-Zip/7z.exe" x -pflare -sns GhostStream.wim
  ```
- **Malware safety (ch4, ch5):** avoid touching samples on disk where Defender may quarantine. Extract into memory and, if you must detonate, patch a stub byte to change the hash:
  ```bash
  # read bytes without writing the sample to disk
  7z e -pflare -so 5-catthief.7z catthief/catthief.exe > /tmp/sample
  # then patch one DOS-stub byte (e.g. the 'T' in "This program cannot") before spawning
  ```

## Toolchain
| Tool | Version / notes |
|---|---|
| Ghidra | 12.1.2 (headless `support/analyzeHeadless.bat`, scripts `DecompAll.java` / `DecompOne.java`) |
| Frida | 16.5.9 (Python venv) — used for ch2 pipe sniffing and ch5 compression oracle |
| Python | 3.12+ |
| Python packages | `capstone`, `unicorn`, `pefile`, `z3-solver`, `pycryptodome`, `numpy`, `pillow`, `cryptography`, `sympy` (ch8), `lief` (ch9) |
| Node.js | 24.x — runs Go WASM via the stock `wasm_exec.js` (ch8); `npm i wabt` only for `wasm-objdump -x` |
| WSL Ubuntu | 26.04 with WSLg, `libwebkit2gtk-4.1-0`, `gdb`, `strace`. Only needed to run ch9 or dump its script; not needed for the solve |
| C compiler | `python -m ziglang cc` (used for ch4 `harness.c` / `recover.c` when no native toolchain) |

Install the Python deps:
```bash
python -m pip install capstone unicorn pefile z3-solver pycryptodome numpy pillow
```

## Per-challenge reproduction

### 1 — flarecaptcha
- Open `flarecaptcha.html`, read the inline `<script>`, satisfy the CAPTCHA gate (theme: *fear of 13* → `triskaidekaphobia`). Flag assembled by the success branch.

### 2 — GhostStream
1. `7z x -sns -oextracted GhostStream.wim` (keeps the ADS `PolyjuicePotion.txt:LordVoldemort`). Defender may lock the extracted WIM; extract it in an excluded folder if so.
2. `python carve_child.py` — writes `child.exe` (the dropped `Partner_CTF.exe`) from the parent's PE resources.
3. `python flag.py` → `y0u_kn0w_n07h1n6_j0n_5n0w@flare-on.com`. It runs the child's **modified RC4** (PRGA step `i += 18`, output masked by `Dt[k] ^ ((18+C[k])&0xff)`) keyed with `HarryPotter`.
4. *(Where the key comes from)* `HarryPotter` is what the parent writes to `\\.\pipe\FlareChallenge`. To observe it live: `python patch_parent.py` (rebuilds `run/` with the parent's two checks NOPed at `0xe93`/`0xfae`), then `python sniff.py`, which pre-locks the child drop path, launches the parent with a redirected `%TEMP%`, and prints `PIPE: b'HarryPotter'`.
5. `dec.py` reproduces the multi-mode (byte-sum-selected) string decryptor. `solve.py` / `brute.py` are the exploratory key-candidate searches.

### 3 — flareon13.doc (polyglot)
1. `python carve.py` — `flareon13.doc` is a raw-mode CD image (2352-byte sectors); joining each sector's 2048-byte data block gives `cd.iso`, 7-Zip pulls `udf/click_me` out of its UDF, and the fat Mach-O's slices are written to `macho/click_me~.arm64` and `macho/click_me~.arm64-3`. (Running 7-Zip directly on the `.doc` gives a different, decoy Mach-O.)
2. `python final.py` — verify the 6 fragments against their embedded MD5s, build `key = XOR of SHA256(frag)`, RC4-decrypt the blob → flag.
3. *(Other layers, not needed for the flag)* `com_emu.py` / `small_emu.py` — Unicorn 16-bit emulation of the DOS COM stage (hook `int 0x21` AH=09h/02h); the ZIP (`layer.zip`) uses **Reduce** → `unreduce.py` (+ `zipr.py`); the PDF objects via `pdfdec.py`.

### 4 — ToxicMiner
1. Produce the mapped image `image.bin` and build the harness:
   ```bash
   7z e -so -pflare 4-ToxicMiner.7z ToxicMiner.exe | python make_image.py -   # sample never touches disk
   python -m ziglang cc -O2 harness.c -o harness.exe -lkernel32   # maps image.bin @0x140000000, calls the sample's own key+RC4 fns
   ./harness.exe 0x01CEC000 0x01CEC100                           # quick check around the winning serial
   ```
   The standalone `recover.c` (pure-C SHA-256d + RC4) does **not** reproduce the flag: the sample's SHA is modified, which is why the harness calls the sample's own code.
2. Brute the 32-bit volume serial space (sharded via `h_*.txt`/`hit_*.txt`), select the plaintext containing `flare-on.com`.
3. Winning serial `0x01CEC01D` → flag. `emu_key.py` / `emu_comp.py` were used to validate the derivation.

### 5 — catthief
1. Recover the exfiltrated files from the pcap:
   ```bash
   cd 5-catthief
   7z x -pflare 5-catthief.7z catthief/capture.pcapng   # only the pcap is needed
   python extract_bodies.py   # pure-Python pcapng parser -> streams/req_<port>.bin, streams/body_<port>.bin
   python solve5.py           # writes recovered/*.jpg (5 files)
   ```
   `solve5.py` uses `decoder.py`'s primitives:
   - RC4 with `key=b"i11_b3_p1und3r1n_y3r_d474"` (keystream from pos 0),
   - `parse_lengths` = `int.from_bytes(pt[1:262],'big') >> 5` (base-256 code lengths),
   - standard **canonical** codes, decode MSB-first from **bit 2091**, trimmed at the last `ff d9`.
2. The flag is painted on the treasure-chest scroll in `recovered/catcatcat.jpg`.
3. *(Only if re-deriving the format)* the Frida **compression oracle** scripts (`c2.py`, `decoracle*.py`, etc.) replay the pcap commands and feed known-frequency probe files to confirm the table layout and the bit-2091 data start — **not required** to reproduce the flag from the provided pcap.

### 6 — ThreatInvaders
1. `solve.py` recovers the flag from **`challenge.pcapng` alone** (no runtime needed):
   ```bash
   cd 6-threatinvaders/ThreatInvaders && python solve.py
   ```
   It reassembles the client TCP stream (telemetry POSTs are LSO/GRO frames with `ip.len == 0`, so read to end-of-frame), then:
   - `tableA = session_id.ToByteArray()` (from the pcap), `TEL#3 = reverse(tableA) ^ tableB` ⇒ `MachineGuid_bytes = TEL#3 ⊕ reverse(session_id_bytes)`,
   - `seed = splitmix64_variant(MachineGuid_bytes)` (consts `0x9e3779b97f4a7c15`, `0xff51afd7ed558ccd`, `0xc4ceb9fe1a85ec53`),
   - keystream `state = state*0x5851f42d4c957f2d + 0x14057b7ef767814f`, output byte = `state >> 56`,
   - `TEL#4 ⊕ keystream` (offset 18) = the updater's `dir` output (shows `flag.txt`), `TEL#5 ⊕ keystream` (offset 576) = **flag**.
2. *(Only if re-deriving the algorithm from the binary)* the exe uses a **modified static CoreCLR** that installs MinHook detours; the injected `EncodeFeedbackBuffer` is at RVA `0xC6BA0`, the PCG/LCG cipher at `0xC65E0`. Reversed dynamically via a custom **EventPipe** dumper (`csharp/eptrace`, gets JIT'd native code without a working DAC) + **Frida** hooks on the cipher (`exp/`). Not required to reproduce the flag from the pcap.

### 7 — FlareCalc
1. `solve7.py` recovers the flag from `FlareCalc.exe` alone (offline):
   ```bash
   cd 7-flarecalc && python solve7.py     # -> t3mplat3s_asn_and_j1t_0h_my@flare-on.com
   ```
   It unpacks the flag-ciphertext blob `9990` with the recovered de-interleave `SEED=1116755918` + fold `90`, then runs the real blob-`4485` **XTEA** decryptor (via Unicorn) with the labyrinth-derived `keybuf` → the flag.
2. *(Only if re-deriving from scratch)*:
   - `map_entries.pkl` = the 1035 `{key, blob}` records parsed from the cert's custom OID `1.3.6.1.4.1.1337.1` (`cryptography`/`pefile` on `FlareCalc.exe`).
   - `seedscan.c` (`ziglang cc`) brute-forces the `2^32` de-interleave seed using an x64-validity oracle (calibrated on the plaintext loader blob `3821`); folds are recovered per-blob by common-byte frequency.
   - `chain_dfs.py` solves the `'3'`-command 32-blob "labyrinth" (input `FLAREON_ASN1_Labyrinth_Key_2026!`) to derive the XTEA `keybuf`; `chain_result.pkl` holds the result.
   - `unpack.py` has the `deinterleave`/`xor_fold` primitives.
   - The calc's hidden self-loader (`FUN_1400019d0`) maps its own cert RWX and calls the stub at cert-offset `0x6d3a` with `(A<<32|B, C)` where `A=(int)n1, B=(int)n2, C=(int)(n3*1e7)` from 3 calc-stack numbers.

### 8 — crux
1. Extract and run the solver (flag comes from the **unmodified** `main.wasm`):
   ```bash
   cd 8-crux-attempt-2
   "C:/Program Files/7-Zip/7z.exe" x -pflare 8-crux.7z -oext && (cd ext && unzip -o extension.zip -d x)
   python solve8.py --run    # -> Pr4tt_Pr1M4lItY_C3rt5_4nd_Wa4aA4aAA4aAA4a4a5M@flare-on.com  (~15–30 s)
   ```
   `solve8.py`:
   - recursively factors `N−1` with sympy, starting from `N = 0xd389dfbb…c930e261`;
   - emits the canonical Pratt certificate: leaf `0x00` = 2; node `0x01 u32 n, n×(u32 len, child), u32 len+A, u32 len+B`, with children sorted and repeated by multiplicity, minimal LE bigints, and B = smallest primitive root;
   - PKCS#7-pads it, AES-256-CBC-encrypts it (key `cabeba7a…cdbf8723`, IV `5ff26040…ecf65d91`) and base64-encodes it.
2. *(Only if re-deriving from the binary)* the tools are in `8-crux-attempt-2/work/`:
   - `wparse.py` builds the memory image (`mem.bin`).
   - `pcln.py` parses the garble pclntab (magic `0xa3c41c63` @ `0x51660`, 3255 funcs, wasm func = functab index + 20) → `funcs.json`.
   - `wdis.py` / `dec.py`: flat disassembler / Go-wasm state-machine decompiler (`python dec.py 3251-3274 dmain.txt`).
   - `instr.py` + `trace.js`: splices entry/exit hooks into chosen functions through the `runtime.getRandomData` import (tag, then `SP|1`). Usage: `python instr.py 3140-3274 i.wasm && node trace.js <input>` → `trace.txt`, with string and bigint arguments decoded.
   - `cert.py` / `enc.py` / `build.py` / `pratt.py`: the original solve path (`facts.json` = the factor tree).

### 9 — NeonOutRun
1. Extract, then solve offline from the binary alone:
   ```bash
   cd 9-neonoutrun-attempt-2
   "C:/Program Files/7-Zip/7z.exe" x -pflare 9-NeonOutRun.7z
   python emu.py      # unicorn: per-lap (K, sign), D=180, 16 Taylor terms -> params.json
   python solve2.py   # -> R3_ag3nt_4b0ut_t0_f33l_d1zzy@flare-on.com
   ```
   - `emu.py` maps the ELF LOAD segments, applies the RELATIVE relocations, and runs:
     - the constant byte chain `0x67ed5b..0x67eec7` (→ 90);
     - the 64-bit chains `0x67ef9f..0x67f8b8` (→ D, term count);
     - the per-lap helpers `0x67f9d8(i, 90)` → `0x68003e`.
   - `solve2.py` solves `K_i + s_i*t_i ≡ 90 (mod 360)` for `t_i ∈ [0,255]`. It appends `@f1are-on.com` and applies the host's `[0x1e] += 0x3b` patch.
2. *(Optional: the decoy layer)*
   - Run `dump.sh` in WSL Ubuntu. It launches the game detached and `gcore`s it; ptrace_scope must be 0, and the core is ~15 GB.
   - Grep the core for `carRatio` to carve `game.js`. `python solve.py` then prints the decoy, `decode_this_system_to_win_it@f1are-on.com`.
   - Delete the core afterwards.
3. *(Re-deriving the hooks)* `python cdis.py <addr>` disassembles the function containing an address, using `.eh_frame_hdr` bounds. `python xref.py <addr>...` finds RIP-relative references. The hooks are:
   - `Array.sort` = `0x67deb2`
   - `Math.min` = `0x67eb83`
   - `replaceAll` = `0x67e81e`
   - G1 @ `0x1438590`, G2 @ `0x1438580`

   Saved disassembly is in `disasm/`.

## Sanity checks
- ch5: `Σ 2^-len == 1.000000` (Kraft equality) confirms the length-table parse; every recovered file starts `ff d8 ff e0` and ends `ff d9`.
- ch4: expect exactly one serial in `[0, 2^32)` whose plaintext contains `flare-on.com`.
- ch6: `TEL#4` decrypts to a `dir` listing containing `flag.txt (46 bytes)`; `TEL#5` decrypts to a 46-byte string ending `@flare-on.com`.
- ch7: the plaintext loader blob `3821` linear-disassembles with **0** invalid opcodes (seed calibration); blob `9990` de-interleaves to exactly **40 bytes** (5 XTEA blocks); the 32-step labyrinth lands entirely on valid map keys and terminates at blob `4485`; `solve7.py` asserts the decrypt equals the flag.
- ch8:
  - `AES_dec(key, 0¹⁶) = 9ba0147dcb8e3ac4d9dd815bbc2a4be1` (plain AES-256).
  - The 20-byte certificate for 3 (`0101000000010000000001000000030100000002`) passes `Kd5oA2q` and reaches the comparison against `N`.
  - The full certificate is 3,891 bytes (5,208 base64 chars), and every node satisfies ∏children = A−1.
- ch9:
  - `emu.py` reports the byte chain = `0x5a` (90), D = 180.0 and 16 terms.
  - Each of the 28 congruences has **exactly one** solution in 0..255, and all are printable ASCII.
  - The unique `add byte ptr [rcx+0x1e], 0x3b` in `.text` is at `0x67ea68`.
