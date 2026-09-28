# Replication Guide — FLARE-On 13 (1–7)

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
| Python packages | `capstone`, `unicorn`, `pefile`, `z3-solver`, `pycryptodome`, `numpy`, `pillow` |
| C compiler | `python -m ziglang cc` (used for ch4 `harness.c` / `recover.c` when no native toolchain) |

Install the Python deps:
```bash
python -m pip install capstone unicorn pefile z3-solver pycryptodome numpy pillow
```

## Per-challenge reproduction

### 1 — flarecaptcha
- Open `flarecaptcha.html`, read the inline `<script>`, satisfy the CAPTCHA gate (theme: *fear of 13* → `triskaidekaphobia`). Flag assembled by the success branch.

### 2 — GhostStream
1. `7z x -pflare -sns GhostStream.wim` (grab the ADS files, incl. `PolyjuicePotion.txt`).
2. (Optional) `sniff.py` — pre-locks the child drop path, launches `GhostStream.exe` with a redirected `%TEMP%`, and reads `\\.\pipe\FlareChallenge`.
3. `dec.py` reproduces the multi-mode (byte-sum-selected) string decryptor.
4. `solve.py` / `brute.py` implement the **modified RC4** (`i += 19` step, output masked by `Dt[k] ^ ((19+C[k])&0xff)`), enumerate the themed key candidates, and print the output containing `flare-on`.

### 3 — flareon13.doc (polyglot)
1. `com_emu.py` / `small_emu.py` — Unicorn 16-bit emulation of the DOS COM stage (hook `int 0x21` AH=09h/02h).
2. Carve the container layers: ISO/UDF (`cd.iso`, `udf`), the ZIP (`layer.zip`) whose entries use **Reduce** → `unreduce.py` (+ `zipr.py`), and the PDF via `pdfdec.py`.
3. Extract the Mach-O `macho/click_me~.arm64-3`.
4. `final.py` — verify the 6 fragments against their embedded MD5s, build `key = XOR of SHA256(frag)`, RC4-decrypt the blob → flag.

### 4 — ToxicMiner
1. Produce the mapped image `image.bin` (pefile) and build the harness:
   ```bash
   python -m ziglang cc harness.c -o harness.exe -lkernel32   # maps image.bin @0x140000000, calls the sample's own key+RC4 fns
   ```
   or use the standalone `recover.c` (pure-C SHA-256d + RC4).
2. Brute the 32-bit volume serial space (sharded via `h_*.txt`/`hit_*.txt`), select the plaintext containing `flare-on.com`.
3. Winning serial `0x01CEC01D` → flag. `emu_key.py` / `emu_comp.py` were used to validate the derivation.

### 5 — catthief
1. `decoder.py` does the whole recovery from the pcap bodies:
   - RC4 with `key=b"i11_b3_p1und3r1n_y3r_d474"` (keystream from pos 0),
   - `parse_lengths` = `int.from_bytes(pt[1:262],'big') >> 5` (base-256 code lengths),
   - standard **canonical** codes, decode MSB-first from **bit 2091** to `EOI ff d9`.
   ```bash
   cd 5-catthief && python decoder.py    # writes recovered/*.jpg
   ```
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

## Sanity checks
- ch5: `Σ 2^-len == 1.000000` (Kraft equality) confirms the length-table parse; every recovered file starts `ff d8 ff e0` and ends `ff d9`.
- ch4: expect exactly one serial in `[0, 2^32)` whose plaintext contains `flare-on.com`.
- ch6: `TEL#4` decrypts to a `dir` listing containing `flag.txt (46 bytes)`; `TEL#5` decrypts to a 46-byte string ending `@flare-on.com`.
- ch7: the plaintext loader blob `3821` linear-disassembles with **0** invalid opcodes (seed calibration); blob `9990` de-interleaves to exactly **40 bytes** (5 XTEA blocks); the 32-step labyrinth lands entirely on valid map keys and terminates at blob `4485`; `solve7.py` asserts the decrypt equals the flag.
