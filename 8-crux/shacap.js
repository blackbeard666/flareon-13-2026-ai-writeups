require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
(async()=>{
 let inst=null,on=false,U=null,D=null,hits=[];
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 // For each func entry, check if sp+8=ptr, sp+16=len describe a buffer whose sha256 == a1c0cf...
 const target="a1c0cf649ab8c16f8ade1d226bd804884463fc7afc0f134d652202a04606e3b9";
 go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   // try (ptr@sp+8,len@sp+16) and (ptr@sp+16,len@sp+24)
   for(const [po,lo] of [[8,16],[16,24],[8,24]]){
     const ptr=q(Number(sp)+po), len=q(Number(sp)+lo);
     if(ptr>0x1000 && len>1000 && len<20000 && ptr+len<=U.length){
       const h=crypto.createHash('sha256').update(Buffer.from(U.subarray(ptr,ptr+len))).digest('hex');
       if(h===target){ hits.push({idx,po,lo,ptr:ptr.toString(16),len, first:Buffer.from(U.subarray(ptr,ptr+16)).toString('hex'), last:Buffer.from(U.subarray(ptr+len-8,ptr+len)).toString('hex')}); }
     }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 const seen=new Set(); for(const h of hits){const k=h.idx+h.len; if(!seen.has(k)){seen.add(k); console.log(JSON.stringify(h));}}
 console.log("certP.hex length:", fs.readFileSync('certP.hex','utf8').trim().length/2);
 process.exit(0);
})();
