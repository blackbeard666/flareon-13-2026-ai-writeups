# Pure-Python pcapng -> streams/req_<sport>.bin + streams/body_<sport>.bin
# (client->server :8080 TCP streams, reassembled by seq; body = bytes after \r\n\r\n).
# Same logic as the original scapy one-liner. usage: python extract_bodies.py [catthief/capture.pcapng] [outdir]
import struct, sys, os
from collections import defaultdict

def packets(fn):
    d = open(fn, 'rb').read(); off = 0; e = '<'; links = []
    while off + 12 <= len(d):
        bt = struct.unpack_from(e + 'I', d, off)[0]
        if bt == 0x0A0D0D0A:                                   # section header: fix endianness
            e = '<' if d[off+8:off+12] == b'\x4d\x3c\x2b\x1a' else '>'; links = []
        bl = struct.unpack_from(e + 'I', d, off + 4)[0]
        if bt == 1:   links.append(struct.unpack_from(e + 'H', d, off + 8)[0])           # IDB
        elif bt == 6:                                                                     # EPB
            iface, _, _, cap = struct.unpack_from(e + 'IIII', d, off + 8)
            yield links[iface], d[off+28:off+28+cap]
        elif bt == 3: yield links[0], d[off+12:off+bl-4]                                 # SPB
        off += bl

def ip_payload(link, f):
    if link == 1:                                              # Ethernet (+ 802.1Q)
        et, p = struct.unpack_from('>H', f, 12)[0], 14
        while et == 0x8100: et, p = struct.unpack_from('>H', f, p + 2)[0], p + 4
        return f[p:] if et == 0x0800 else None
    if link in (101, 228): return f                            # raw IPv4
    if link == 0: return f[4:] if struct.unpack_from('<I', f)[0] == 2 else None   # BSD null
    if link == 113: return f[16:] if struct.unpack_from('>H', f, 14)[0] == 0x0800 else None
    return None

def main():
    fn = sys.argv[1] if len(sys.argv) > 1 else 'catthief/capture.pcapng'
    out = sys.argv[2] if len(sys.argv) > 2 else 'streams'
    streams = defaultdict(dict)                                # sport -> {seq: payload}
    for link, f in packets(fn):
        ip = ip_payload(link, f)
        if not ip or ip[0] >> 4 != 4 or ip[9] != 6: continue
        ihl = (ip[0] & 15) * 4; tot = struct.unpack_from('>H', ip, 2)[0]
        tcp = ip[ihl:tot]
        sport, dport, seq = struct.unpack_from('>HHI', tcp)
        data = tcp[(tcp[12] >> 4) * 4:]
        if dport == 8080 and data: streams[sport][seq] = data
    os.makedirs(out, exist_ok=True)
    for sp, segs in sorted(streams.items()):
        req = b''.join(segs[s] for s in sorted(segs))
        body = req[req.find(b'\r\n\r\n') + 4:]
        open(f'{out}/req_{sp}.bin', 'wb').write(req)
        open(f'{out}/body_{sp}.bin', 'wb').write(body)
        print(sp, len(req), len(body), req.split(b'\r\n', 1)[0].decode(errors='replace'))

if __name__ == '__main__':
    main()
