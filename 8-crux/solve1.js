const crypto=require('crypto');
require('./wasm_exec.js');
const fs=require('fs');
const sched=Buffer.from("7ababeca1d8056d11c38821cc4a3b87c3c2cae066ca968d1843637d82387bfcd","hex");
const key=Buffer.alloc(32); for(let i=0;i<32;i+=4) for(let j=0;j<4;j++) key[i+j]=sched[i+3-j];
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
console.log("KEY:",key.toString('hex'));
console.log("IV :",iv.toString('hex'));
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function enc(pt){ const c=crypto.createCipheriv('aes-256-cbc',key,iv); c.setAutoPadding(false); return Buffer.concat([c.update(pt),c.final()]); }
  // candidate plaintext: 32 bytes 'A' + 16 bytes of 0x10 (valid PKCS7 pad of 16)
  const p1=Buffer.concat([Buffer.alloc(32,0x41), Buffer.alloc(16,0x10)]);
  const ct1=enc(p1);
  console.log("test1 (32*A + pad16):", JSON.stringify(check(ct1.toString('base64'))));
  // candidate: 47 bytes 'A' + 0x01
  const p2=Buffer.concat([Buffer.alloc(47,0x41), Buffer.from([0x01])]);
  console.log("test2 (47*A + 0x01):", JSON.stringify(check(enc(p2).toString('base64'))));
  // full flag-like: "test@flare-on.com" padded
  const msg=Buffer.from("test@flare-on.com");
  const padlen=48-msg.length; const p3=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);
  console.log("test3 (email padded):", JSON.stringify(check(enc(p3).toString('base64'))));
  process.exit(0);
})();
