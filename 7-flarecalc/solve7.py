#!/usr/bin/env python3
"""
FLARE-On 13 #7 FlareCalc - end-to-end flag recovery (offline).

Chain of custody:
  1. FlareCalc.exe is a decoy calculator; its Authenticode cert carries a custom
     extension (OID 1.3.6.1.4.1.1337.1) = 1035 {key:u16, blob} records -> map_entries.pkl
  2. The calc hides a self-loader (FUN_1400019d0) that maps its own cert RWX and calls
     the x64 stub at cert-offset 0x6d3a (== blob key 3821, entry FUN_140000000) with a
     16-byte arg = (A<<32|B, C) where A=(int)n1, B=(int)n2, C=(int)(n3*1e7) taken from
     3 numbers on the calc stack (op 0xC000008E in FUN_140002a90).
  3. Each blob is unpacked as: deinterleave( xor(blob, fold), prng(input) ), where
     prng seed = func_0x9070(input). The correct input yields deinterleave SEED=1116755918
     (recovered by a 2^32 brute with an x64-validity oracle) and per-blob fold = a byte
     of MD5(input||key) folded (recovered per-blob by frequency; blob 9990 -> fold 90).
  4. The bind-shell backdoor's '3' command walks a 32-blob "labyrinth" (states below),
     each blob mutating a 32-byte keybuf, driven by the command bytes
     b'FLAREON_ASN1_Labyrinth_Key_2026!'; the terminal blob 4485 = XTEA-decrypts the
     embedded ciphertext blob 9990 and returns the flag.

This script reproduces step 4's result directly: unpack blob 9990 (SEED,fold90) and run
the REAL blob 4485 XTEA code (via unicorn) with the derived keybuf.
"""
import pickle, struct
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UcError
from unicorn.x86_const import (UC_X86_REG_RSP, UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8)

SEED = 1116755918                     # deinterleave seed (func_0x9070 of the correct input)
FOLD_9990 = 90                        # xor fold for the flag-ciphertext blob
FOLD_4485 = 226                       # xor fold for the XTEA decryptor code blob
# keybuf produced by the 32-step labyrinth chain (see chain_dfs.py); input bytes:
#   b'FLAREON_ASN1_Labyrinth_Key_2026!'
KEYBUF = bytes.fromhex("670daa0ff05e7d85472eeb55a716a7b88d63019c27ee22ea447fd4fde87c013d")

def xor_fold(buf, fold):
    b = fold; out = bytearray(buf)
    for i in range(len(out)):
        b = (b*0x6d + 0x39) & 0xff
        out[i] ^= b
    return bytes(out)

def deinterleave(buf, seed):
    st = seed & 0xffffffff; i = 0; out = bytearray(); n = len(buf)
    while i < n:
        out.append(buf[i])
        st = (st*1103515245 + 12345) & 0xffffffff
        skip = (st % 3) + 1
        for _ in range(skip):
            st = (st*1103515245 + 12345) & 0xffffffff
        i += 1 + skip
    return bytes(out)

def unpack(mapd, key, fold, seed=SEED):
    return deinterleave(xor_fold(mapd[key], fold), seed)

def run_xtea(code4485, ciphertext, keybuf):
    CODE, STK, OUT, IN, KEY = 0x140000000, 0x200000, 0x300000, 0x310000, 0x320000
    mu = Uc(UC_ARCH_X86, UC_MODE_64)
    mu.mem_map(CODE, 0x10000); mu.mem_write(CODE, code4485.ljust(0x1000, b'\xcc'))
    mu.mem_map(STK-0x10000, 0x20000)
    mu.mem_map(OUT, 0x10000); mu.mem_map(IN, 0x10000); mu.mem_map(KEY, 0x10000)
    mu.mem_write(IN, ciphertext.ljust(0x100, b'\x00'))
    mu.mem_write(KEY, keybuf.ljust(0x40, b'\x00'))
    mu.reg_write(UC_X86_REG_RSP, STK)
    mu.reg_write(UC_X86_REG_RCX, OUT)   # out
    mu.reg_write(UC_X86_REG_RDX, IN)    # in (ciphertext)
    mu.reg_write(UC_X86_REG_R8,  KEY)   # keybuf (xtea key = kb[0:16]^kb[16:32])
    mu.mem_write(STK, (0xdead0000).to_bytes(8, 'little'))
    try: mu.emu_start(CODE, 0xdead0000, count=500000)
    except UcError: pass
    return bytes(mu.mem_read(OUT, 64))

if __name__ == "__main__":
    mapd = {k: v for k, v in pickle.load(open("map_entries.pkl", "rb"))}
    ct   = unpack(mapd, 9990, FOLD_9990)   # 40-byte XTEA ciphertext
    code = unpack(mapd, 4485, FOLD_4485)   # the real XTEA decryptor
    out  = run_xtea(code, ct, KEYBUF)
    flag = out.split(b"\x00")[0].decode()
    print("blob 9990 ciphertext:", ct.hex())
    print("FLAG:", flag)
    assert flag == "t3mplat3s_asn_and_j1t_0h_my@flare-on.com", "mismatch!"
    print("[verified]")
