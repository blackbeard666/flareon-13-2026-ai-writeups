require('./wasm_exec.js');
const fs = require('fs');
(async () => {
  const go = new Go();
  const { instance } = await WebAssembly.instantiate(fs.readFileSync('main.wasm'), go.importObject);
  go.run(instance);
  await new Promise(r => setImmediate(r));
  const check = globalThis.check;
  // warm + heavy loop
  let s=0;
  const inp = "A".repeat(32);
  for (let i=0;i<300000;i++){ const r=check(inp); s+=r.length; }
  console.log("done", s);
  process.exit(0);
})();
