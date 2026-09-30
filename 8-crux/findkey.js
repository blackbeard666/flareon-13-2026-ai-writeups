require('./wasm_exec.js');
const fs=require('fs');
const STAGE1KEY="cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723";
(async()=>{
 let inst=null,on=false,hits=[];
 function mem(){return new Uint8Array(inst.exports.mem.buffer);}
 function dv(){return new DataView(inst.exports.mem.buffer);}
 function q(D,o){o=Number(o);if(o<0||o+8>D.byteLength)return 0n;return D.getBigUint64(o,true);}
 function slice32(U,D,base){ // interpret *(base) as ptr, read 32 bytes
   const ptr=Number(q(D,base)); if(ptr<=0x1000||ptr+32>U.length) return null;
   return Buffer.from(U.slice(ptr,ptr+32)).toString('hex');
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; const U=mem(),D=dv();
   for(const off of [8,16,24]){ const h=slice32(U,D,Number(sp)+off); if(h===STAGE1KEY){ hits.push({idx,off,which:'STAGE1KEY'}); } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const inp=fs.readFileSync('certP.b64','utf8').trim();
 on=true; check(inp); on=false;
 // dedupe
 const seen=new Set();
 for(const h of hits){ const k=h.idx+'/'+h.off; if(!seen.has(k)){seen.add(k); console.log("func",h.idx,"receives stage1 key at sp+"+h.off);} }
 console.log("total hits:",hits.length);
 process.exit(0);
})();
