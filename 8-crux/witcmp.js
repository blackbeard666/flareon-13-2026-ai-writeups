require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,seen=new Map();
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function rI(p){p=p>>>0;if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=q(p+8),len=q(p+16);if(ptr<=0x1000||len<0||len>2048||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return neg?-v:v;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3262){ // modexp(base,exp,mod): base@+8, mod@+24
     const b=rI(q(Number(sp)+8)), m=rI(q(Number(sp)+24));
     if(b!==null&&m!==null){ const key=m.toString(); if(!seen.has(key)) seen.set(key, b.toString()); }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 // output: for each mod (prime), the base (witness) the eval used
 const out={};
 for(const [m,b] of seen) out[m]=b;
 fs.writeFileSync('eval_witnesses.json', JSON.stringify(out));
 console.log("captured witnesses for",seen.size,"distinct primes");
 process.exit(0);
})();
