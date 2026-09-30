require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 const go=new Go();
 go.importObject.env=go.importObject.env||{};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_gatebypass.wasm'),go.importObject);
 go.run(instance); await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 for(const inp of [ "A".repeat(64), "QUJDRA==".padEnd(64,'A'), "AAAA".repeat(16) ]){
   try{ const r=check(inp); console.log(JSON.stringify(inp.slice(0,12)+"..."), "->", JSON.stringify(r)); }
   catch(e){ console.log("ERR:",e.message); }
 }
 process.exit(0);
})();
