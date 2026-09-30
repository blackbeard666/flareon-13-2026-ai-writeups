require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let cnt=0;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.log32=()=>{cnt++;};
  go.importObject.env.log64=()=>{cnt++;};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_cmp.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  // inputs passed as base64 strings on argv
  for(const inp of process.argv.slice(2)){
    cnt=0; let res;
    try{res=check(inp);}catch(e){res='ERR '+e.message;}
    console.log(cnt, JSON.stringify(res), inp.slice(0,20)+"...");
  }
  process.exit(0);
})();
