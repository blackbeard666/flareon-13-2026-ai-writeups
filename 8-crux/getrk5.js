require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; let cap=null,capsp=0;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{ if(tracing&&inst&&idx===3187&&!cap){capsp=inst.exports.g0();cap=Buffer.from(Buffer.from(inst.exports.mem.buffer));} };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  tracing=true; globalThis.check(Buffer.from(process.argv[2],'hex').toString('base64')); tracing=false;
  // gather candidate pointers: all 8-byte values in stack window, and one indirection
  const m=cap; const cands=new Set();
  for(let off=-64; off<400; off+=8){ const a=capsp+off; if(a<0||a+8>m.length)continue; const v=Number(m.readBigUInt64LE(a)); if(v>0x1000&&v<m.length-256) cands.add(v); }
  // one level indirection
  for(const v of [...cands]){ try{const w=Number(m.readBigUInt64LE(v)); if(w>0x1000&&w<m.length-256)cands.add(w);}catch(e){} }
  fs.writeFileSync('rk_cands.json', JSON.stringify([...cands]));
  fs.writeFileSync('rk_mem.bin', m);
  console.log('candidates',cands.size,'sp',capsp.toString(16));
  process.exit(0);
})();
