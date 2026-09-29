"""FLARE-On 13 #8 crux -- build the canonical Pratt certificate for the target prime,
wrap it (PKCS#7 + AES-256-CBC + base64) and optionally feed it to the real WASM.

    python solve8.py            # writes input.txt
    python solve8.py --run      # also runs ext/x/main.wasm under Node and prints the flag
"""
import base64, os, struct, subprocess, sys
from sympy import factorint, isprime
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

HERE = os.path.dirname(os.path.abspath(__file__))
# root prime the checker compares against (garble-obfuscated 32-byte constant, read at runtime)
N = 0xd389dfbb379a02ccda7a4ab0b327e8e3655a3c96447c1b5578bee179c930e261
# AES-256-CBC key/IV used by check() to decrypt the base64-decoded input
KEY = bytes.fromhex('cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723')
IV = bytes.fromhex('5ff26040c4c20b9f2ffdefa7ecf65d91')

_fac = {}


def fac(n):
    if n not in _fac:
        _fac[n] = factorint(n)
    return _fac[n]


def le(x):  # canonical little-endian bigint: no trailing zero bytes, 0 -> b''
    return x.to_bytes((x.bit_length() + 7) // 8, 'little')


def lp(b):
    return struct.pack('<I', len(b)) + b


def min_primitive_root(p):
    qs = list(fac(p - 1))
    g = 2
    while any(pow(g, (p - 1) // q, p) == 1 for q in qs):
        g += 1
    return g


def cert(p):
    """leaf 0x00 == prime 2; node 0x01 = u32 n, n*(u32 len, child), u32 len+A, u32 len+B"""
    if p == 2:
        return b'\x00'
    assert isprime(p)
    kids = []
    for q, e in sorted(fac(p - 1).items()):  # sorted, with multiplicity (product == p-1)
        kids += [cert(q)] * e
    return (b'\x01' + struct.pack('<I', len(kids)) + b''.join(lp(k) for k in kids)
            + lp(le(p)) + lp(le(min_primitive_root(p))))


def wrap(msg):
    n = 16 - len(msg) % 16
    e = Cipher(algorithms.AES(KEY), modes.CBC(IV)).encryptor()
    return base64.b64encode(e.update(msg + bytes([n]) * n) + e.finalize()).decode()


if __name__ == '__main__':
    c = cert(N)
    inp = wrap(c)
    open(os.path.join(HERE, 'input.txt'), 'w').write(inp)
    print(f'certificate: {len(c)} bytes -> input: {len(inp)} base64 chars (input.txt)')
    if '--run' in sys.argv:
        print('running check() in Node (~30 s)...')
        out = subprocess.run(['node', os.path.join(HERE, 'ext', 'run.js'), inp],
                             capture_output=True, text=True).stdout
        print(out.split('=>', 1)[-1].strip())
