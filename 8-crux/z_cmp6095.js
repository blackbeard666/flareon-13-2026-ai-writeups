require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,evs=[];
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>512||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return (neg?'-':'')+v.toString();}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb(); sp=Number(sp);
   if(idx===3254){ evs.push({a0:rI(q(sp+0)),a8:rI(q(sp+8)),a16:rI(q(sp+16))}); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r),"total 3254:",evs.length);
 console.log("LAST 3254 call (=0x6095 integrity):");
 const e=evs[evs.length-1];
 console.log("  sp+0 =",e.a0);
 console.log("  sp+8 =",e.a8);
 console.log("  sp+16=",e.a16);
 process.exit(0);
})();
