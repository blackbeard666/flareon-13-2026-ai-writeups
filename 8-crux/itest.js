require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null,aesN=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(idx===3190)aesN++; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {r,aesN};
}
(async()=>{ for(const f of ['certP_i1777smallest.b64','certP_i1777alt.b64']){ const x=await run(f); console.log(f,"result:",JSON.stringify(x.r),"AES#:",x.aesN); } process.exit(0); })();
