require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
// raw 48-byte P (no pkcs7 auto pad) - we control full 48 bytes
function mkRaw(P48){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(P48),c.final()]).toString('base64');}
// pkcs7 message
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};let total=0;
 go.importObject.env={trace:(idx)=>{ if(on){ total++; cnt[idx]=(cnt[idx]||0)+1; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const watch=[3270,3267,3050,3217,3190,3242,3264,3266];
 for(let L=1;L<=47;L++){
   const M=Buffer.alloc(L,0x41);
   on=true;total=0;for(const k in cnt)delete cnt[k];const r=check(mkMsg(M));on=false;
   console.log("len="+L,"r="+JSON.stringify(r),"total="+total, watch.map(w=>w+":"+(cnt[w]||0)).join(" "));
 }
 process.exit(0);
})();
