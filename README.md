# FLARE-On 13 (2026) — AI-assisted write-ups

Write-ups, solver scripts and working files for all nine FLARE-On 13 challenges, solved with Claude Code on a Windows 11 host. All nine flags were recovered offline.

## Artifacts

| Page | Link | Local copy |
|------|------|------------|
| **FLARE-On 13 Write-ups**: how each challenge was solved, including the failed first attempts at crux and NeonOutRun | [claude.ai/artifact/AwJL5PqBTku6hnMb4TK5qm](https://claude.ai/artifact/AwJL5PqBTku6hnMb4TK5qm) | [`writeups/flareon13-writeups.html`](writeups/flareon13-writeups.html) |
| **FLARE-On 13 Run Report**: costs, token counts, wall-clock time and tooling per challenge | [claude.ai/artifact/HHHxvuztfY72i6gDE4GEk2](https://claude.ai/artifact/HHHxvuztfY72i6gDE4GEk2) | [`writeups/flareon13-report.html`](writeups/flareon13-report.html) |

The local HTML files are self-contained; download one and open it in a browser. The raw metrics behind the report are in [`writeups/session_stats.json`](writeups/session_stats.json).

## Challenges

| # | Challenge | Category | Write-up |
|---|-----------|----------|----------|
| 1 | flarecaptcha | JS deobfuscation | [01-flarecaptcha.md](writeups/01-flarecaptcha.md) |
| 2 | GhostStream | WIM / IPC / modified RC4 | [02-ghoststream.md](writeups/02-ghoststream.md) |
| 3 | flareon13.doc | Polyglot (COM/ISO/ZIP-Reduce/PDF/Mach-O) | [03-flareon13-doc.md](writeups/03-flareon13-doc.md) |
| 4 | ToxicMiner | cpuminer trojan / SHA-256d + RC4 brute | [04-toxicminer.md](writeups/04-toxicminer.md) |
| 5 | catthief | Rust implant / custom Huffman + RC4 | [05-catthief.md](writeups/05-catthief.md) |
| 6 | ThreatInvaders | .NET 10 modified runtime / detour hooks / PCG-XOR exfil | [06-threatinvaders.md](writeups/06-threatinvaders.md) |
| 7 | FlareCalc | Cert-embedded x64 implant / custom packer VM / XTEA labyrinth | [07-flarecalc.md](writeups/07-flarecalc.md) |
| 8 | crux | garble Go WASM extension / AES-CBC / Pratt primality certificate | [08-crux.md](writeups/08-crux.md) |
| 9 | NeonOutRun | Rust Tauri + embedded V8 / hooked JS builtins / lap-time sine gate | [09-neonoutrun.md](writeups/09-neonoutrun.md) |

Flags, models used and per-challenge session metrics are in [`writeups/README.md`](writeups/README.md). Notes for reproducing each solve are in [`writeups/REPLICATION.md`](writeups/REPLICATION.md).

## Repository layout

- `writeups/`: Markdown write-ups, the two HTML pages above, and session metrics
- `1-flarecaptcha/` … `9-neonoutrun/`: per-challenge solver scripts, Ghidra helpers and working notes
- `8-crux-attempt-2/`, `9-neonoutrun-attempt-2/`: the fresh second sessions that solved crux and NeonOutRun

Challenge binaries, archives, captures and large dumps are excluded by `.gitignore`, so the original samples are not in this repo.
