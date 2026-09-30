require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
(async()=>{
 let on=false; const cnt={};
 const go=new Go();
 go.importObject.env={trace:(idx)=>{ if(on) cnt[idx]=(cnt[idx]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_gb_instr.wasm'),go.importObject);
 go.run(instance); await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const msg=Buffer.from("0100000000000000001300000001010101010101010101010101010101010101","hex");
 on=true; const r=check(mk(msg)); on=false;
 console.log("result:",JSON.stringify(r));
 // key funcs of interest
 for(const f of [3217,3267,3269,3190,3251,3268,3272,2992,3252,3166,3184,674]) console.log("  call",f,"x",cnt[f]||0);
})();
