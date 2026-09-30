require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,evs=[],aesN=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>512||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return (neg?'-':'')+v.toString();}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb(); sp=Number(sp);
   if(idx===3190){aesN++;return;}
   if(idx===3254){ evs.push({f:'Cmp3254',a:rI(q(sp+8)),b:rI(q(sp+16)),aesN}); }
   if(idx===3252){ evs.push({f:'3252',a:rI(q(sp+8)),b:rI(q(sp+16)),aesN}); }
   if(idx===3272){ evs.push({f:'3272dec',a:rI(q(sp+8)),aesN}); }
   if(idx===2992){ evs.push({f:'2992',a:rI(q(sp+8)),b:rI(q(sp+16)),aesN}); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r),"total evs:",evs.length);
 // only show events with aesN>=1 (after stage1, in decode)
 for(const e of evs){ if(e.aesN>=1){ console.log(JSON.stringify(e)); } }
 process.exit(0);
})();
