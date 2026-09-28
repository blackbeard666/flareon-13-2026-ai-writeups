# FLARE-On 13 — Challenge 5: catthief

| | |
|---|---|
| **Challenge** | catthief |
| **Artifacts** | `catthief.exe` (Rust Windows implant), `capture.pcapng` |
| **Category** | Malware RE / network protocol / custom compression + RC4 |
| **Flag** | `th3r3_b3_tr34sure_1n_th4t_pc4p@flare-on.com` |

## Prompt (paraphrased)
A cat burglar's implant exfiltrated some contraband. Reconstruct the heist from the executable and the packet capture and recover what was stolen.

## Files provided
- `catthief/catthief.exe` — PE32+ x86-64 **Rust** implant (`implant.pdb`); uses `ureq`/`rustls`/`ring`/`flate2`/`miniz_oxide`.
- `catthief/capture.pcapng` — 6 `POST /exfil` requests + responses to the C2.

Solver: **`5-catthief/decoder.py`** (+ recovered images in `5-catthief/recovered/`).

## Tools used
- **Ghidra** (headless) to reverse the exfil routine and identify RC4 (KSA `FUN_1400052e2`, PRGA `FUN_140005281`) and the custom `compress.rs`
- **Frida 16.5.9** as a **compression oracle** — redirect `connect`→local C2 and `CreateFileW`→known probe files, replay the real pcap commands, feed inputs with known byte-frequencies
- **Python** for the RC4/Huffman decoder; **Pillow** to render the recovered JPEGs
- Defender evasion: extract to memory with `7z e -so` + patch a DOS-stub byte to change the file hash before detonation

## Methodology

### 1. Map the protocol
The implant reads a target file, **custom-Huffman-compresses** it, **RC4-encrypts** it, and `POST`s to `/exfil`. Responses carry the next file path command. The pcap holds 5 exfiltrated JPEGs (plus a READY beacon).

### 2. RC4 layer
The cipher is **standard RC4** with a 25-byte key decoded in-binary via `^0x33`:

```
key = b"i11_b3_p1und3r1n_y3r_d474"   # "ill be plunderin yer data" (pirate speak)
```

The keystream is **reused from position 0 for every message** — decrypting the pcap *response* bodies yields clean Windows file paths, confirming the key.

### 3. The custom Huffman format (the hard part)
`catthief` ships its **own** `compress.rs` (not flate2). After RC4 decryption each message is:

| Region | Meaning |
|---|---|
| byte `0` | magic `0x20` |
| bytes `1..262` | a **big-endian integer**; the 256-entry **code-length table** = `int.from_bytes(pt[1:262],'big') >> 5` (base-256 digits → `length[symbol]`) |
| from **bit 2091** | Huffman **bitstream**, read **MSB-first**, **standard canonical** codes (sort by `(length, symbol)`) |

The `>>5` (×32) storage is why all-length-8 files show the telltale `01 01 01 …` header. Validated by the **Kraft equality** `Σ 2^-len == 1.000000` on every real capture.

```python
# core of decoder.py
def parse_lengths(pt):
    T = int.from_bytes(pt[1:262], 'big'); L = T >> 5
    lb = L.to_bytes(261, 'big')
    return [lb[s+5] for s in range(256)]

def canonical(lengths):               # standard canonical Huffman
    syms = sorted((lengths[s], s) for s in range(256) if lengths[s] > 0)
    codes = {}; code = 0; prev = 0
    for l, s in syms:
        code <<= (l - prev); codes[s] = (code, l); code += 1; prev = l
    return codes
# decode MSB-first from bit 2091 until EOI (ff d9)
```

### 4. Cracking the format with a compression oracle
The table serialization and the constant **bit-2091** data offset were reverse-engineered empirically: under Frida we fed the implant tiny inputs with **known byte frequencies** (e.g. `[10,11,…,17]` → all length-3) and read back the exact code assignment, proving the codes are plain canonical and pinning the data start.

### 5. Recover the loot
All 5 messages decoded to valid JPEGs (`SOI ffd8ffe0` → `EOI ffd9`), 2816×1536 pirate cats. The flag is **painted on a scroll on the treasure chest** in `catcatcat.jpg`:

```
th3r3_b3_tr34sure_1n_th4t_pc4p@flare-on.com
```
("there be treasure in that pcap")

## Decode pipeline

```mermaid
flowchart TD
    PCAP[capture.pcapng<br/>6x POST /exfil] --> CT[ciphertext body]
    CT --> RC4["RC4 decrypt<br/>key = i11_b3_p1und3r1n_y3r_d474<br/>(keystream reused)"]
    RC4 --> MSG[plaintext message]
    MSG --> HDR["byte0 = 0x20 magic"]
    MSG --> TAB["bytes[1:262] big-endian int<br/>lengths = int&gt;&gt;5 (base256)"]
    MSG --> BITS["bitstream @ constant bit 2091<br/>MSB-first"]
    TAB --> CANON["canonical codes<br/>sort by (length, symbol)"]
    CANON --> DEC[Huffman decode to EOI ff d9]
    BITS --> DEC
    DEC --> JPG[5 valid JPEGs 2816x1536]
    JPG --> FLAG["scroll in catcatcat.jpg:<br/>th3r3_b3_tr34sure_1n_th4t_pc4p@flare-on.com"]
```

## Notes / dead-ends
- Initial "many-time-pad" keystream-reuse recovery worked but was superseded once RC4 + the 25-byte key were identified outright.
- A subagent dispatched for the Huffman reversal was killed by the platform's `[cyber]` safeguard; the deep RE was completed inline instead.
- The `<<5` table scaling and the non-byte-aligned **bit-2091** data start were the two subtle blockers; both were resolved with the Frida compression oracle rather than by guessing.

## Session stats
| Metric | Value |
|---|---|
| Model | Claude Opus 4.8 (+ continued in a later session) |
| Assistant turns (with usage, original transcript) | ~708 |
| Output tokens (original transcript) | ~2,034,480 |
| Cache-read tokens (original transcript) | ~379,101,610 |
| Wall-clock (original transcript) | ~537 minutes, **partial** — solve finished in a follow-up session |

*(Approximate, measured from the Claude Code transcript. Challenge 5 spans two sessions; only the first is captured in the metrics file.)*
