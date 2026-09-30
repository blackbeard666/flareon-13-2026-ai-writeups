require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null,aesN=0,ct=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb(); if(idx===3190){aesN++; if(aesN===2) ct=hx(q(Number(sp)+40),64);} }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return ct;
}
(async()=>{ const a=await run('certP.b64'); const b=await run('certP_lv1.b64'); console.log("certP  CT:",a); console.log("lv1    CT:",b); console.log("SAME:",a===b); process.exit(0);})();
