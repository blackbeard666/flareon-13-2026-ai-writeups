require('./wasm_exec.js');
const fs = require('fs');
(async () => {
  const go = new Go();
  const { instance } = await WebAssembly.instantiate(fs.readFileSync('main.wasm'), go.importObject);
  go.run(instance);
  await new Promise(r => setImmediate(r));
  const check = globalThis.check;
  const seen = {};
  // lengths of 'A'
  for (let n=0;n<=64;n++){ const r=check('A'.repeat(n)); if(!(r in seen)){seen[r]=[]; } seen[r].push('A*'+n); }
  // formats
  const fmts=['flare','@flare-on.com','x@flare-on.com','a@flare-on.com','test@flare-on.com',
    '0123456789','abcdef','ABCDEF','!@#$%^&*()','FLARE2026','crux','the_crux','0','1','-1',
    'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@flare-on.com'];
  for (const f of fmts){ const r=check(f); (seen[r]=seen[r]||[]).push(JSON.stringify(f)); }
  for (const [msg, ins] of Object.entries(seen)) console.log(JSON.stringify(msg), "<=", ins.slice(0,8).join(", "), ins.length>8?("(+"+(ins.length-8)+")"):"");
  process.exit(0);
})();
