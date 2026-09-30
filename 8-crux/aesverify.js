const crypto=require('crypto');
require('./wasm_exec.js');
const fs=require('fs');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
// Construct an input: pick a 32-byte message, pad, AES-256-CBC ENCRYPT -> 48 bytes -> b64 -> check()
function makeInput(msg32){
  const c=crypto.createCipheriv('aes-256-cbc',key,iv); c.setAutoPadding(true);
  const ct=Buffer.concat([c.update(msg32),c.final()]); // 32 -> 48 with pkcs7
  return {ct, b64:ct.toString('base64')};
}
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
  go.run(instance);await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const msg=Buffer.from("A".repeat(32));
  const {ct,b64}=makeInput(msg);
  console.log("b64 len", b64.length, "ct len", ct.length);
  console.log("check(crafted) =>", JSON.stringify(check(b64)));  // should get PAST aes+padding, fail at sha gate
  console.log("check(random64) =>", JSON.stringify(check("A".repeat(64))));
  process.exit(0);
})();
