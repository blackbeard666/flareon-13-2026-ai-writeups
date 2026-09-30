require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(on&&idx===3190)aesN++; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {r,aesN};
}
(async()=>{ for(const p of [3,5,7,97]){ const x=await run('cert_'+p+'.b64'); console.log('cert('+p+'):',JSON.stringify(x.r),'AES#:',x.aesN);} process.exit(0);})();
