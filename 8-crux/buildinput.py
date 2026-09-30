#!/usr/bin/env python3
# Build the 64-char base64 input from a message (bytes). Auto PKCS7-pad to 48 bytes, AES-256-CBC encrypt.
import sys, base64, binascii
from Crypto.Cipher import AES

KEY = binascii.unhexlify("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723")
IV  = binascii.unhexlify("5ff26040c4c20b9f2ffdefa7ecf65d91")

def build_from_message(msg: bytes) -> str:
    # PKCS7 pad to 48 bytes total (block 16). msg length must be 32..47 (so total==48).
    assert 32 <= len(msg) <= 47, f"msg len {len(msg)} must be 32..47 for a single 48-byte ciphertext"
    padlen = 48 - len(msg)
    p = msg + bytes([padlen])*padlen
    assert len(p) == 48
    ct = AES.new(KEY, AES.MODE_CBC, IV).encrypt(p)
    return base64.b64encode(ct).decode()

def build_from_raw48(p48: bytes) -> str:
    assert len(p48) == 48
    ct = AES.new(KEY, AES.MODE_CBC, IV).encrypt(p48)
    return base64.b64encode(ct).decode()

if __name__ == "__main__":
    if len(sys.argv) >= 2:
        # arg is hex of the message
        msg = binascii.unhexlify(sys.argv[1])
        print(build_from_message(msg))
    else:
        # demo: 32 'A'
        print(build_from_message(b"A"*32))
