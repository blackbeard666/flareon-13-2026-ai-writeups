require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null,aesN=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb(); if(idx===3190)aesN++; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {r,aesN};
}
(async()=>{ for(const f of ['certP_w3.b64','certP_w5.b64']){ const x=await run(f); console.log(f,"result:",JSON.stringify(x.r),"AEScount:",x.aesN,"(2=reached final decode)"); } process.exit(0); })();
