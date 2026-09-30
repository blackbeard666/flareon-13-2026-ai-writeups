require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; const caps=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3187){ const sp=inst.exports.g0(); const m=Buffer.from(inst.exports.mem.buffer); caps.push([sp,Buffer.from(m)]); }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const inb=Buffer.from(process.argv[2],'hex');
  tracing=true; check(inb.toString('base64')); tracing=false;
  const Ps=['0a1b8253d5e0e16ab89f93f271f24659','cc1b31f807f4a7303be95948f9e28fad','92f8515c36978a35f308c9c25cf11950'];
  caps.forEach(([sp,m],i)=>{
    console.log(`--- cap${i} sp=${sp.toString(16)} ---`);
    // scan stack window for pointers; a pointer whose target matches a P block
    for(let off=-32; off<320; off+=8){
      const a=sp+off; if(a<0||a+8>m.length) continue;
      const val=Number(m.readBigUInt64LE(a));
      if(val>0x10000 && val<m.length-16){
        const tgt=m.slice(val,val+16).toString('hex');
        for(const P of Ps) if(tgt===P) console.log(`  [sp+${off}] -> ${val.toString(16)} = P(${P.slice(0,8)})`);
      }
    }
  });
  // From first cap, find src ptr, then guess receiver holds round keys near it
  process.exit(0);
})();
