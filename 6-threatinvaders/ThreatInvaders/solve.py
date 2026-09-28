#!/usr/bin/env python3
"""
FLARE-On 13 #6 ThreatInvaders - offline solver.
Recovers the flag purely from challenge.pcapng using the algorithm reversed
from ThreatInvaders.exe (a modified .NET runtime that hooks EncodeFeedbackBuffer).

Mechanism:
  * The game exfiltrates updater.exe stdout in the telemetry feedback_b64 field.
  * Content is XOR-encrypted with a PCG/LCG keystream.
  * Keystream seed = customsplitmix64(tableB), tableB = MachineGuid bytes.
  * tableA = session_id bytes (sent in the pcap).
  * TEL#3 content = reverse(tableA) ^ tableB  -> lets us recover tableB (MachineGuid)
    from the pcap since session_id is also in the pcap.
  * TEL#4/#5 content = keystream-XOR of the updater output (dir listing + flag.txt).
"""
import struct, re, base64, json, uuid
M = (1 << 64) - 1

def reassemble_client_stream(path):
    d = open(path, "rb").read()
    off = 0; pkts = []
    while off + 8 <= len(d):
        bt, bl = struct.unpack_from("<II", d, off)
        if bt == 6:
            cap = struct.unpack_from("<I", d, off + 20)[0]
            pkts.append(d[off + 28: off + 28 + cap])
        if bl < 12: break
        off += bl
    flows = {}
    for p in pkts:
        if len(p) < 54: continue
        ipoff = 14; ihl = (p[ipoff] & 0xf) * 4
        if p[ipoff + 9] != 6: continue
        src = ".".join(map(str, p[ipoff+12:ipoff+16])); dst = ".".join(map(str, p[ipoff+16:ipoff+20]))
        toff = ipoff + ihl
        sport, dport = struct.unpack_from(">HH", p, toff); seq = struct.unpack_from(">I", p, toff + 4)[0]
        doff = ((p[toff + 12] >> 4) & 0xf) * 4
        iptotal = struct.unpack_from(">H", p, ipoff + 2)[0]
        end = len(p) if iptotal == 0 else ipoff + iptotal   # LSO/GRO: IP total len may be 0
        pl = p[toff + doff:end]
        if pl: flows.setdefault((src, sport, dst, dport), {})[seq] = pl
    # client -> server is the flow with dport 80
    for (src, sport, dst, dport), segs in flows.items():
        if dport == 80:
            return b"".join(segs[s] for s in sorted(segs))
    raise RuntimeError("client stream not found")

def parse_telemetry(stream):
    tels = []
    for m in re.finditer(rb"POST /api/v1/telemetry.*?\r\n\r\n", stream, re.S):
        he = m.end(); hs = m.start()
        cl = re.search(rb"Content-Length:\s*(\d+)", stream[hs:he]); n = int(cl.group(1))
        j = json.loads(stream[he:he + n])
        raw = base64.b64decode(j["feedback_b64"]) if j.get("feedback_b64") else b""
        # meaningful bytes = leading nonzero region
        nz = (max((i for i, c in enumerate(raw) if c), default=-1)) + 1
        tels.append({"json": j, "content": raw[:nz]})
    return tels

def seed_from_tableB(tb):
    lo = int.from_bytes(tb[0:8], "little"); hi = int.from_bytes(tb[8:16], "little")
    t = ((lo >> 2) + 0x9e3779b97f4a7c15 + ((lo << 6) & M) + hi) & M
    t ^= lo
    t = ((t ^ (t >> 33)) * 0xff51afd7ed558ccd) & M
    t = ((t ^ (t >> 29)) * 0xc4ceb9fe1a85ec53) & M
    return (t ^ (t >> 32)) & M

def keystream(seed, n):
    st = seed; out = bytearray()
    for _ in range(n):
        st = (st * 0x5851f42d4c957f2d + 0x14057b7ef767814f) & M   # PCG/MMIX LCG
        out.append((st >> 56) & 0xff)                              # output = top byte
    return bytes(out)

def main():
    stream = reassemble_client_stream("challenge.pcapng")
    tels = parse_telemetry(stream)
    # TEL indices: [0]=empty [1]=user text [2]=16B header(TEL#3) [3]=530B [4]=46B
    session_id = tels[2]["json"]["session_id"]
    tableA = uuid.UUID(session_id).bytes_le                        # = session_id bytes
    tel3 = tels[2]["content"]                                      # reverse(tableA) ^ tableB
    tableB = bytes(tel3[i] ^ tableA[15 - i] for i in range(16))    # = author's MachineGuid bytes
    print("[*] session_id           :", session_id)
    print("[*] recovered MachineGuid :", uuid.UUID(bytes_le=tableB))
    K = keystream(seed_from_tableB(tableB), 8192)
    t4 = tels[3]["content"]; t5 = tels[4]["content"]
    dir_listing = bytes(t4[i] ^ K[18 + i] for i in range(len(t4)))
    print("\n[*] TEL#4 (updater `dir` output):\n" + dir_listing.decode("latin1"))
    # TEL#5 = flag.txt contents; find the keystream offset that yields printable ascii
    for off in range(0, len(K) - len(t5)):
        p = bytes(t5[i] ^ K[off + i] for i in range(len(t5)))
        if p.endswith(b"@flare-on.com"):
            print("[+] FLAG:", p.decode())
            return
    print("[!] flag not found")

if __name__ == "__main__":
    main()
