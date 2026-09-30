require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let seq=[];
  go.importObject.env={trace:(i)=>{ if(tracing) seq.push(i); }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function traceOf(inp){ tracing=true; seq=[]; const r=check(inp); tracing=false; return {r, seq:seq.slice()}; }
  // compare two lengths and two contents
  const t16=traceOf("A".repeat(16));
  const t17=traceOf("A".repeat(17));
  // functions called N times for len16 vs len17 (per-char scaling)
  function counts(seq){ const m={}; for(const f of seq) m[f]=(m[f]||0)+1; return m; }
  const c16=counts(t16.seq), c17=counts(t17.seq);
  const funcs=new Set([...Object.keys(c16),...Object.keys(c17)]);
  console.log("func  c16  c17  (delta)");
  const rows=[];
  for(const f of funcs){ const a=c16[f]||0,b=c17[f]||0; if(a!==b) rows.push([f,a,b,b-a]); }
  rows.sort((x,y)=>Math.abs(y[3])-Math.abs(x[3]));
  for(const [f,a,b,d] of rows) console.log(f,a,b,"("+(d>0?"+":"")+d+")");
  process.exit(0);
})();
