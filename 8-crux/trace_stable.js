require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let seq=[];
  go.importObject.env={trace:(i)=>{ if(tracing) seq.push(i); }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function tc(inp){ tracing=true; seq=[]; check(inp); tracing=false; const m={}; for(const f of seq)m[f]=(m[f]||0)+1; return m; }
  for(const L of [8,12,16,20,24,32,48]){
    let a=[];
    for(let r=0;r<3;r++){ const m=tc("A".repeat(L)); a.push((m[1315]||0)+"/"+(m[973]||0)+"/"+(m[967]||0)+" tot="+Object.values(m).reduce((x,y)=>x+y,0)); }
    console.log("L="+L, a.join("  |  "));
  }
  process.exit(0);
})();
