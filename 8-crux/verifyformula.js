require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,aesN=0,cap=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3190){aesN++; if(aesN===2){ sp=Number(sp);
     // scan sp+0..96 for pointers to 64-byte buffers
     cap={};
     for(const off of [8,16,24,32,40,48]){ const p=q(sp+off); if(p>0x1000&&p+64<=U.length) cap['sp+'+off]=hx(p,64); }
   }}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("AES#2 64-byte buffers:"); for(const k in cap) console.log("  "+k+": "+cap[k]);
 process.exit(0);
})();
