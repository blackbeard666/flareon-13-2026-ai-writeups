require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; const caps=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{ if(tracing&&inst&&idx===3187){caps.push([inst.exports.g0(),Buffer.from(Buffer.from(inst.exports.mem.buffer))]);} };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const inb=Buffer.from(process.argv[2],'hex');
  tracing=true; globalThis.check(inb.toString('base64')); tracing=false;
  const [sp,m]=caps[0];
  console.log('sp',sp.toString(16));
  for(let off=-16; off<220; off+=8){
    const v=Number(m.readBigUInt64LE(sp+off));
    console.log(`[sp+${off}] = ${v.toString(16)}`);
  }
  process.exit(0);
})();
