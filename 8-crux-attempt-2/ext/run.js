const fs=require('fs');globalThis.window=globalThis;
require('./x/wasm_exec.js');
(async()=>{const go=new Go();const {instance}=await WebAssembly.instantiate(fs.readFileSync(__dirname+'/x/main.wasm'),go.importObject);go.run(instance);
setTimeout(()=>{for(const a of process.argv.slice(2)){const t=Date.now();console.log(JSON.stringify(a),'=>',globalThis.check(a),Date.now()-t,'ms');}process.exit(0)},100);})();
