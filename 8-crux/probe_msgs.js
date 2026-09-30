require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const b64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  const seen={};
  function rnd(){ let s=''; for(let i=0;i<64;i++) s+=b64[Math.floor(Math.random()*64)]; return s; }
  for(let i=0;i<20000;i++){ const inp=rnd(); const r=check(inp); if(!(r in seen)) seen[r]=inp; }
  // structured tries
  for(const s of ["QUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFBQUFB",
                  "flare".padEnd(64,'A'), "A".repeat(64), "/".repeat(64), "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"]){
    const r=check(s); if(!(r in seen)) seen[r]=s;
  }
  console.log("distinct results:", Object.keys(seen).length);
  for(const [r,inp] of Object.entries(seen)) console.log(JSON.stringify(r), "<=", inp.slice(0,20)+"...");
  process.exit(0);
})();
