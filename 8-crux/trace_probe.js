require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let cnt=0;
  go.importObject.env={trace:(i)=>{ if(tracing) cnt++; }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function mincalls(inp){ let m=1e9; for(let r=0;r<6;r++){ tracing=true;cnt=0; const res=check(inp); tracing=false; if(cnt<m)m=cnt; } return m; }
  const tests=[
    "", "A", "AAAA", "A".repeat(16),
    "flare", "test@flare-on.com", "x@flare-on.com",
    "0123456789abcdef", "deadbeef", "DEADBEEF",
    "aGVsbG8=", "SGVsbG8gV29ybGQ=", "QUFBQQ==",
    "the quick brown fox", "1234567890",
    "crux", "Crux", "CRUX",
    "{}", "{\"a\":1}", "[]",
    "flare-on", "FLARE-ON", "F".repeat(32),
    "!@#$%^&*", "\u00e9\u00e8",  // non-ascii
    "-----", "......", "::::::",
    "0x1234", "%20", "\x41",
  ];
  const rows=tests.map(t=>[JSON.stringify(t), mincalls(t)]);
  rows.sort((a,b)=>b[1]-a[1]);
  for(const [t,c] of rows) console.log(c, t);
  process.exit(0);
})();
