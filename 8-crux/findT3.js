require('./wasm_exec.js');
const fs=require('fs'); const crypto=require('crypto');
(async()=>{
  const go=new Go(); let tracing=false; let inst=null; let cryptodone=false; const out=new Map();
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3190) cryptodone=true;
    if(!cryptodone) return;
    const sp=inst.exports.g0(); const m=Buffer.from(inst.exports.mem.buffer);
    let hasPT=false, hasLen=false;
    for(let o=-16;o<340;o+=8){const a=sp+o;if(a<0||a+8>m.length)continue;const v=Number(m.readBigUInt64LE(a));if(v===0x3688a0)hasPT=true;if(v===48)hasLen=true;}
    if(!(hasPT&&hasLen)) return;
    for(let o=-16;o<340;o+=8){const a=sp+o;if(a<0||a+8>m.length)continue;const v=Number(m.readBigUInt64LE(a));if(v>0x1000&&v<m.length-48&&v!==0x3688a0){const t=m.slice(v,v+48).toString('hex');out.set(idx+':'+v,t);}}
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);
  const inp=Buffer.concat([c.update(Buffer.alloc(48)),c.final()]).toString('base64');
  tracing=true; globalThis.check(inp); tracing=false;
  console.log("candidates (frames with ptr 0x3688a0 + len48):",out.size);
  for(const [k,t] of out) console.log(k,t);
  process.exit(0);
})();
