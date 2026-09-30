require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; const seq=[]; let count=0;
  go.importObject.env = go.importObject.env || {};
  go.importObject.env.trace = (idx)=>{ count++; if(tracing && seq.length<5000000) seq.push(idx); };
  let instance;
  try {
    const r=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'), go.importObject);
    instance=r.instance;
  } catch(e){ console.error("INSTANTIATE FAIL:", e.message); process.exit(1); }
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  console.log("check type:", typeof check, "init trace calls:", count);
  tracing=true; seq.length=0;
  const res=check("A".repeat(16));
  tracing=false;
  console.log("result:", JSON.stringify(res), "trace len:", seq.length);
  // unique funcs in order of first appearance
  const seen=new Set(); const order=[];
  for(const f of seq){ if(!seen.has(f)){seen.add(f);order.push(f);} }
  console.log("unique funcs during check:", order.length);
  console.log("first 60 unique:", order.slice(0,60).join(","));
  fs.writeFileSync('trace_seq.json', JSON.stringify({order, len:seq.length, seq:seq.slice(0,200000)}));
  process.exit(0);
})();
