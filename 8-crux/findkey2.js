require('./wasm_exec.js');
const fs=require('fs');
const S1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
(async()=>{
 let inst=null,on=false,U=null,D=null,found={};
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   sp=Number(sp);
   for(const off of [8,16,24]){
     const ptr=q(sp+off);
     if(ptr>0x1000 && ptr+4<U.length){
       // cheap 4-byte prefix check
       if(U[ptr]===0xca&&U[ptr+1]===0xbe&&U[ptr+2]===0xba&&U[ptr+3]===0x7a){
         if(ptr+32<=U.length){ const b=Buffer.from(U.subarray(ptr,ptr+32)); if(b.equals(S1)){ const k=idx+'/'+off; found[k]=(found[k]||0)+1; } }
       }
     }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 on=true; check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("funcs receiving stage1 key:",JSON.stringify(found));
 process.exit(0);
})();
