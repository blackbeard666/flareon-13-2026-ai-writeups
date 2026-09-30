require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; let cap=null,csp=0;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{ if(tracing&&inst&&idx===3054&&!cap){csp=inst.exports.g0();cap=Buffer.from(Buffer.from(inst.exports.mem.buffer));} };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  tracing=true; globalThis.check(Buffer.from(process.argv[2],'hex').toString('base64')); tracing=false;
  const m=cap; fs.writeFileSync('f3054_mem.bin',m);
  console.log('sp',csp.toString(16));
  const P2='0a1b8253d5e0e16ab89f93f271f24659';
  // dump stack and find pointer to P2
  for(let off=-16; off<260; off+=8){
    const v=Number(m.readBigUInt64LE(csp+off));
    let note='';
    if(v>0x1000&&v<m.length-16){ const t=m.slice(v,v+16).toString('hex'); if(t===P2)note=' -> P2(src)'; else if(v>=0x200000&&v<0x400000)note=' -> '+t; }
    console.log(`[sp+${off}]=${v.toString(16)}${note}`);
  }
  process.exit(0);
})();
