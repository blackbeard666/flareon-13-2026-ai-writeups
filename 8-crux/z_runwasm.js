require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync(process.argv[2]),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const inp=fs.readFileSync(process.argv[3]||'certP.b64','utf8').trim();
 let r; try{r=globalThis.check(inp);}catch(e){r='ERR:'+e.message;}
 console.log(JSON.stringify(r));
 process.exit(0);
})();
