require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const b64=fs.readFileSync('inp.bin').toString('base64');
  const res=check(b64);
  console.log("input",b64,"result",JSON.stringify(res));
  const mem=Buffer.from(instance.exports.mem.buffer);
  fs.writeFileSync('memk.bin',mem);
  // search standard AES sbox
  const sbox=Buffer.from([0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76]);
  let i=mem.indexOf(sbox);
  while(i>=0){ console.log("AES sbox @",i.toString(16)); i=mem.indexOf(sbox,i+1); }
  // inv sbox start 52 09 6a d5
  const isb=Buffer.from([0x52,0x09,0x6a,0xd5,0x30,0x36,0xa5,0x38]);
  i=mem.indexOf(isb); while(i>=0){ console.log("AES INV sbox @",i.toString(16)); i=mem.indexOf(isb,i+1); }
  // input bytes (1..48)
  const inb=fs.readFileSync('inp.bin');
  i=mem.indexOf(inb); while(i>=0){ console.log("input48 @",i.toString(16)); i=mem.indexOf(inb,i+1); }
  process.exit(0);
})();
