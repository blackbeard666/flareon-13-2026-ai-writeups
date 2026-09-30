require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; const snaps=[]; let inst=null;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3187 || idx===3181 || idx===3244){
      const m=Buffer.from(inst.exports.mem.buffer);
      snaps.push([idx, Buffer.from(m)]);
    }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const b64=fs.readFileSync('inp.bin').toString('base64');
  tracing=true; const res=check(b64); tracing=false;
  console.log("result",JSON.stringify(res),"snaps",snaps.length, snaps.map(s=>s[0]).join(","));
  snaps.forEach((s,i)=>fs.writeFileSync(`snap_${i}_f${s[0]}.bin`, s[1]));
  process.exit(0);
})();
