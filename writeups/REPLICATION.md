# Replication Guide — FLARE-On 13 (1–5)

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

## Sanity checks
- ch5: `Σ 2^-len == 1.000000` (Kraft equality) confirms the length-table parse; every recovered file starts `ff d8 ff e0` and ends `ff d9`.
- ch4: expect exactly one serial in `[0, 2^32)` whose plaintext contains `flare-on.com`.
