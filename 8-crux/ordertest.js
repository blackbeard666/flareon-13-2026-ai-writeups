require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(idx===3190)aesN++; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {r,aesN};
}
(async()=>{ for(const f of ['certP.b64','certP_desc.b64']){ const x=await run(f); console.log(f,JSON.stringify(x.r),"AES#:",x.aesN);} process.exit(0); })();
