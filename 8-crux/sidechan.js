require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let cnt=0;
  go.importObject.env={trace:(i)=>{ if(tracing) cnt++; }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function mincalls(inp){ let m=1e9; for(let r=0;r<8;r++){ tracing=true;cnt=0; check(inp); tracing=false; if(cnt<m)m=cnt;} return m; }
  for(const L of [16,24,32,40,48,56,64]){
    // brute first char (printable ascii), rest 'A'
    let best=[-1,-1];
    const base="A".repeat(L-1);
    let vals=[];
    for(let c=32;c<127;c++){ const s=String.fromCharCode(c)+base; const m=mincalls(s); vals.push([c,m]); if(m>best[1]) best=[c,m]; }
    vals.sort((a,b)=>b[1]-a[1]);
    console.log("L="+L, "baseAll="+mincalls("A".repeat(L)), "topchars:", vals.slice(0,5).map(v=>JSON.stringify(String.fromCharCode(v[0]))+":"+v[1]).join(" "));
  }
  process.exit(0);
})();
