const crypto=require('crypto');
require('./wasm_exec.js');
const fs=require('fs');
const sched=Buffer.from("7ababeca1d8056d11c38821cc4a3b87c3c2cae066ca968d1843637d82387bfcd","hex");
const key=Buffer.alloc(32); for(let i=0;i<32;i+=4) for(let j=0;j<4;j++) key[i+j]=sched[i+3-j];
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function enc(pt){ const c=crypto.createCipheriv('aes-256-cbc',key,iv); c.setAutoPadding(false); return Buffer.concat([c.update(pt),c.final()]); }
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_patched.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const p1=Buffer.concat([Buffer.alloc(32,0x41),Buffer.alloc(16,0x10)]);
  console.log("valid-pad 32A:", JSON.stringify(check(enc(p1).toString('base64'))));
  const p2=Buffer.concat([Buffer.from("test@flare-on.com"),Buffer.alloc(31,31)]);
  console.log("email msg:", JSON.stringify(check(enc(p2).toString('base64'))));
  process.exit(0);
})();
