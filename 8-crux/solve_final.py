#!/usr/bin/env python3
"""End-to-end: build a tree per Fork A grammar -> AES input -> verify with run.js.
Usage: import Node from forkA_serialize, build a tree, call solve(node)."""
import subprocess, base64, binascii, sys, struct
from Crypto.Cipher import AES

KEY = binascii.unhexlify("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723")
IV  = binascii.unhexlify("5ff26040c4c20b9f2ffdefa7ecf65d91")
NODE = "C:/Program Files/nodejs/node.exe"

def u32(n): return struct.pack('<I', n)
def int_le(n):
    if n == 0: return b''
    o = bytearray()
    while n: o.append(n & 0xff); n >>= 8
    return bytes(o)

class Node:
    def __init__(self, children=None, key=0, val=0, key_bytes=None, val_bytes=None):
        self.children = children or []
        self.key_bytes = key_bytes if key_bytes is not None else int_le(key)
        self.val_bytes = val_bytes if val_bytes is not None else int_le(val)
    def serialize(self):
        o = bytearray([0x01]); o += u32(len(self.children))
        for c in self.children:
            cb = c.serialize(); o += u32(len(cb)); o += cb
        o += u32(len(self.key_bytes)); o += self.key_bytes
        o += u32(len(self.val_bytes)); o += self.val_bytes
        return bytes(o)

def msg_to_input(msg: bytes) -> str:
    assert 32 <= len(msg) <= 47, f"message len {len(msg)} not in 32..47"
    padlen = 48 - len(msg)
    p = msg + bytes([padlen]) * padlen
    ct = AES.new(KEY, AES.MODE_CBC, IV).encrypt(p)
    return base64.b64encode(ct).decode()

def run_oracle(inp: str) -> str:
    out = subprocess.run([NODE, "run.js", inp], capture_output=True, text=True,
                         cwd="C:/Users/cavila/Desktop/ctf/flareon13-2026/8-crux/").stdout
    return out.strip()

def solve(node):
    msg = node.serialize()
    print("message:", msg.hex(), "len", len(msg))
    inp = msg_to_input(msg)
    print("input  :", inp)
    print(run_oracle(inp))

if __name__ == "__main__":
    if len(sys.argv) > 1:
        # arg = message hex directly
        msg = binascii.unhexlify(sys.argv[1])
        print("message:", msg.hex(), "len", len(msg))
        inp = msg_to_input(msg)
        print("input  :", inp)
        print(run_oracle(inp))
    else:
        # smoke test with Fork A's verified-parse example
        print(run_oracle(msg_to_input(binascii.unhexlify(
            "0100000000000000001300000001010101010101010101010101010101010101"))))
