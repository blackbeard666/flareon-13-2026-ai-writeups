require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(idx)=>{ if(on) cnt[idx]=(cnt[idx]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 function T(name,M){ for(const k in cnt)delete cnt[k]; on=true;const r=check(mkMsg(M));on=false;
   const val = (cnt[3269]||0)>0;
   if(val || name.startsWith('*')) console.log(name.padEnd(20),"3270="+(cnt[3270]||0),"3267="+(cnt[3267]||0),"3269="+(cnt[3269]||0),"3251="+(cnt[3251]||0),"3252="+(cnt[3252]||0),"3254="+(cnt[3254]||0),"3272="+(cnt[3272]||0),"2992="+(cnt[2992]||0),JSON.stringify(r)); return val;}
 let reached=[];
 for(let tag=0;tag<=40;tag++){
   for(const plen of [1,2,3,5,9,13]){
     const M=Buffer.concat([Buffer.from([tag]),Buffer.alloc(plen-1,0)]);
     if(T(`tag${tag} len${plen}`,M)) reached.push(`tag${tag}/len${plen}`);
   }
 }
 console.log("REACHED VALIDATOR:",reached.join(', ')||'(none)');
 process.exit(0);
})();
