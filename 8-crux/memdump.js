require('./wasm_exec.js');
const fs = require('fs');
(async () => {
  const go = new Go();
  const { instance } = await WebAssembly.instantiate(fs.readFileSync('main.wasm'), go.importObject);
  go.run(instance);
  await new Promise(r => setImmediate(r));
  const check = globalThis.check;
  check("TESTMARKER1234");   // run once to trigger string decryption
  const mem = Buffer.from(instance.exports.mem.buffer);
  fs.writeFileSync('mem_after.bin', mem);
  console.log("mem size", mem.length);
  const cribs = ["Bad input","Correct","correct","flare","FLARE","Nice","Well","Success","Valid input","Good","TESTMARKER","@flare-on","Wrong","Invalid","try again","crux"];
  for (const c of cribs){
    let idx = mem.indexOf(Buffer.from(c));
    while (idx>=0){
      console.log(JSON.stringify(c),"@",idx.toString(16), JSON.stringify(mem.slice(Math.max(0,idx-16), idx+48).toString('latin1')));
      idx = mem.indexOf(Buffer.from(c), idx+1);
      if (idx> mem.indexOf(Buffer.from(c))+200000) break;
    }
  }
  process.exit(0);
})();
