require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let cnt=0;
  go.importObject.env={trace:(i)=>{ if(tracing) cnt++; }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  for(let L=0;L<=80;L++){
    tracing=true; cnt=0;
    const r=check("A".repeat(L));
    tracing=false;
    console.log(L, cnt, JSON.stringify(r));
  }
  process.exit(0);
})();
