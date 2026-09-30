require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(on&&idx===3190)aesN++; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; const r=globalThis.check(fs.readFileSync('certP_distinct.b64','utf8').trim()); on=false;
 console.log("distinct cert result:",JSON.stringify(r),"AES#:",aesN);
 process.exit(0);
})();
