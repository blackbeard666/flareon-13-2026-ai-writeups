# Decode the 5 pcap exfil bodies (from extract_bodies.py) into recovered/*.jpg.
# RC4 + table parsing from decoder.py; Huffman bitstream starts at bit 2091, decoded to end, trimmed at last FFD9.
# File names come from the decrypted C2 responses (resp on port N names the file sent on the next port).
# usage: python extract_bodies.py && python solve5.py   -> flag on the scroll in recovered/catcatcat.jpg
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import decoder as D

FILES = [(49681, 'important'), (49682, 'anothercat'), (49683, 'yetanothercat'),
         (49685, 'catcatcat'), (49686, 'myfavoritecat')]

def decode_full(pt, lengths, startbit=2091):
    lut = {(l, c): s for s, (c, l) in D.canonical_codes(lengths).items()}
    out = bytearray(); cur = cl = 0
    for bp in range(startbit, len(pt) * 8):
        cur = (cur << 1) | ((pt[bp >> 3] >> (7 - (bp & 7))) & 1); cl += 1
        if (cl, cur) in lut: out.append(lut[(cl, cur)]); cur = cl = 0
    return bytes(out)

os.makedirs('recovered', exist_ok=True)
for port, name in FILES:
    pt = D.decrypt('streams/body_%d.bin' % port)
    res = decode_full(pt, D.parse_lengths(pt))
    res = res[:res.rfind(b'\xff\xd9') + 2]
    open('recovered/%s.jpg' % name, 'wb').write(res)
    print('wrote recovered/%s.jpg %d bytes' % (name, len(res)))
