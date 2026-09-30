globalThis.require = require;
require('./wasm_exec.js');
const fs = require('fs');
(async () => {
  const go = new Go();
  const bytes = fs.readFileSync('main.wasm');
  const { instance } = await WebAssembly.instantiate(bytes, go.importObject);
  go.run(instance);              // registers globalThis.check, then blocks internally
  await new Promise(r => setImmediate(r));
  const check = globalThis.check;
  console.log("check is:", typeof check);
  const inputs = process.argv.slice(2);
  if (inputs.length === 0) inputs.push("test", "", "AAAAAAAA", "flare");
  for (const inp of inputs) {
    try { console.log(JSON.stringify(inp), "=>", JSON.stringify(check(inp))); }
    catch(e){ console.log(JSON.stringify(inp), "ERR", e.message); }
  }
  process.exit(0);
})();
