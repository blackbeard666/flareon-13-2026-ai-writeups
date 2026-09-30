require('./wasm_exec.js');
const fs=require('fs');
const bytes=fs.readFileSync('main.wasm');
async function runDump(inp){
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(bytes,go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  globalThis.check(inp);
  return Buffer.from(instance.exports.mem.buffer);
}
(async()=>{
  const i1="ABCDEFGHIJKLMNOPabcdefghijklmnop0123456789+/ABCDEFGHIJKLMNOPQRST"; // 64
  const i2="ZYXWVUTSRQPONMLKzyxwvutsrqponmlk9876543210/+ZYXWVUTSRQPONMLKJIHG"; // 64
  console.log("len i1",i1.length,"i2",i2.length);
  const m1=await runDump(i1);
  const m2=await runDump(i2);
  // decode i1 to 48 bytes for reference
  const d1=Buffer.from(i1,'base64'); const d2=Buffer.from(i2,'base64');
  console.log("decoded i1[0..16]:", d1.slice(0,16).toString('hex'));
  // find i1 raw string and decoded bytes in m1
  console.log("i1 string in m1 @", m1.indexOf(Buffer.from(i1)).toString(16));
  console.log("decoded i1 in m1 @", m1.indexOf(d1).toString(16));
  console.log("decoded i2 in m2 @", m2.indexOf(d2).toString(16));
  process.exit(0);
})();
