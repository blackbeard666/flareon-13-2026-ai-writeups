require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; let cryptodone=false; const found=new Map();
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3190) cryptodone=true;
    if(!cryptodone) return;
    const sp=inst.exports.g0();
    const m=Buffer.from(inst.exports.mem.buffer);
    let hasPT=false;
    for(let off=-16; off<320; off+=8){ const a=sp+off; if(a<0||a+8>m.length)continue; if(Number(m.readBigUInt64LE(a))===0x3688a0){hasPT=true;break;} }
    if(!hasPT) return;
    for(let off=-16; off<320; off+=8){
      const a=sp+off; if(a<0||a+8>m.length)continue;
      const v=Number(m.readBigUInt64LE(a));
      if(v>0x1000 && v<m.length-48 && v!==0x3688a0){
        const t=m.slice(v,v+48); const uniq=new Set(t).size;
        if(uniq>=20 && t.slice(0,48).indexOf(0)<0){ // high entropy, no null in 48
          found.set(v, [idx, t.toString('hex')]);
        }
      }
    }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  tracing=true; globalThis.check(Buffer.from(process.argv[2],'hex').toString('base64')); tracing=false;
  console.log("high-entropy 48B neighbors of 0x3688a0-frames:", found.size);
  for(const [v,[idx,t]] of found) console.log(`f${idx} ptr=${v.toString(16)}: ${t}`);
  process.exit(0);
})();
