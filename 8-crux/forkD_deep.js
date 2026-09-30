require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const seen=new Set();
 go.importObject.env={trace:(i)=>{ if(on&&i>=3240) seen.add(i); }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 for(const h of ["0100000000000000001300000001010101010101010101010101010101010101","01020000000d0000000100000000000000000d000000010000000000000000000000000000"]){
   on=true;seen.clear();check(mk(Buffer.from(h,"hex")));on=false;
   console.log("msg",h.slice(0,20),"funcs>=3240:",[...seen].sort((a,b)=>a-b).join(","));
 }
 process.exit(0);
})();
