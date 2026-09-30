require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let seq=[];
  go.importObject.env={trace:(i)=>{ if(tracing) seq.push(i); }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function runseq(inp){ tracing=true; seq=[]; check(inp); tracing=false; return seq.slice(); }
  // intersection of function SETS over 12 runs = deterministic path
  let inter=null; let sample=null;
  for(let r=0;r<12;r++){ const s=runseq("A".repeat(16)); const set=new Set(s); if(!inter) {inter=set; sample=s;} else { for(const f of [...inter]) if(!set.has(f)) inter.delete(f); } }
  // ordered dedup of the sample, filtered to stable funcs
  const seen=new Set(); const order=[];
  for(const f of sample){ if(inter.has(f) && !seen.has(f)){seen.add(f);order.push(f);} }
  console.log("stable funcs:", order.length);
  console.log(order.join(","));
  // also counts in one run (stable only)
  const m={}; for(const f of sample) if(inter.has(f)) m[f]=(m[f]||0)+1;
  console.log("counts:", JSON.stringify(m));
  process.exit(0);
})();
