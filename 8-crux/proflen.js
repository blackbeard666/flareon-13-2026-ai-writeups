require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const L=parseInt(process.argv[2]||"4"); const N=parseInt(process.argv[3]||"200000");
  const inp="A".repeat(L); let s=0;
  for(let i=0;i<N;i++) s+=check(inp).length;
  console.log("done",s); process.exit(0);
})();
