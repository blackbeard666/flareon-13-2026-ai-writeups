var base = Module.findBaseAddress("ThreatInvaders.exe");
function hexrd(rva, n) {
  var b = new Uint8Array(base.add(rva).readByteArray(n));
  return Array.from(b).map(function (x) { return ('0' + x.toString(16)).slice(-2); }).join('');
}
function hexp(p, n) {
  var b = new Uint8Array(p.readByteArray(n));
  return Array.from(b).map(function (x) { return ('0' + x.toString(16)).slice(-2); }).join('');
}
send({ t: "tableB", hex: hexrd(0x7FFA30, 16) });
var cipher = base.add(0xc65e0);
var callno = 0;
Interceptor.attach(cipher, {
  onEnter: function (a) {
    this.buf = a[0];
    this.len = a[1].toInt32();
    this.ok = (this.len > 0 && this.len < 0x4000);
    this.pt = this.ok ? hexp(a[0], this.len) : "";
    this.seedIn = hexrd(0x7FFA20, 8);
  },
  onLeave: function (r) {
    if (!this.ok) return;
    var ct = hexp(this.buf, this.len);
    send({ t: "cipher", call: callno++, len: this.len, pt: this.pt, ct: ct, seedIn: this.seedIn, tableB: hexrd(0x7FFA30, 16) });
  }
});
send({ t: "READY" });
