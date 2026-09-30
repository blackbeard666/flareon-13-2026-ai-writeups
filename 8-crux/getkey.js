require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,keys=[];
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3184){ const ptr=q(Number(sp)+8); if(ptr>0x1000&&ptr+32<=U.length){ keys.push(Buffer.from(U.subarray(ptr,ptr+32)).toString('hex')); } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 on=true; check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("3184 keys captured:",keys.length);
 keys.forEach((k,i)=>console.log("  #"+(i+1)+": "+k));
 process.exit(0);
})();
