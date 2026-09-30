require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(idx)=>{ if(on)cnt[idx]=(cnt[idx]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 function run(M){for(const k in cnt)delete cnt[k];on=true;const r=check(mkMsg(M));on=false;return {r,v:cnt[3269]||0,k:cnt[3251]||0,big:cnt[3272]||0};}
 for(const first of [0,1]){
   for(let L=1;L<=24;L++){
     const M=Buffer.alloc(L,0);M[0]=first;
     const o=run(M);
     if(o.v>0) console.log(`first=${first} len=${L}: 3269=${o.v} 3251=${o.k} 3272=${o.big} ${JSON.stringify(o.r)}`);
   }
 }
 process.exit(0);
})();
