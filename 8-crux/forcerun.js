require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_force1414.wasm'),go.importObject);
 go.run(instance); await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 for(const f of ['certP.b64','certP_lv1.b64','cand_180.b64']){
   try{ const r=check(fs.readFileSync(f,'utf8').trim()); console.log(f,"->",JSON.stringify(r).slice(0,200)); }
   catch(e){ console.log(f,"ERR",e.message); }
 }
 process.exit(0);
})();
