require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,cn=0,ivs=[];
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3166){ sp=Number(sp); cn++;
     // NewCBCDecrypter(block iface @sp+8/+16, iv slice ptr@sp+24 len@sp+32)
     const ivptr=q(sp+24), ivlen=q(sp+32);
     ivs.push({call:cn, ivlen, iv:hx(ivptr,Math.min(ivlen||16,32)),
               s8:hx(q(sp+8),16), alt_iv16:hx(q(sp+16),16)});
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r));
 for(const v of ivs) console.log(JSON.stringify(v));
 process.exit(0);
})();
