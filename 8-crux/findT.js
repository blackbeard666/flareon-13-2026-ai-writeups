require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; let cryptodone=false; const hits=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3190) cryptodone=true;
    if(!cryptodone) return;
    const sp=inst.exports.g0();
    const m=Buffer.from(inst.exports.mem.buffer);
    // scan stack for pointer == 0x3688a0
    for(let off=-16; off<300; off+=8){
      const a=sp+off; if(a<0||a+8>m.length) continue;
      const v=Number(m.readBigUInt64LE(a));
      if(v===0x3688a0){
        // found; look at neighbor slots for other pointers (T)
        const neigh=[];
        for(let o2=-16;o2<300;o2+=8){ const w=Number(m.readBigUInt64LE(sp+o2)); if(w>0x1000&&w<m.length-48 && w!==0x3688a0){ const t=m.slice(w,w+48).toString('hex'); neigh.push([o2,w,t]); } }
        hits.push([idx, off, neigh.slice()]);
      }
    }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  tracing=true; globalThis.check(Buffer.from(process.argv[2],'hex').toString('base64')); tracing=false;
  console.log("hits (func with arg->0x3688a0):", hits.length);
  const seen=new Set();
  for(const [idx,off,neigh] of hits.slice(0,5)){
    console.log(`func f${idx} arg[sp+${off}]=0x3688a0`);
    for(const [o2,w,t] of neigh){ const key=w+t; if(seen.has(key))continue; seen.add(key); console.log(`   [sp+${o2}]=${w.toString(16)} : ${t}`); }
  }
  process.exit(0);
})();
