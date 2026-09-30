require('./wasm_exec.js');
const fs=require('fs'); const crypto=require('crypto');
(async()=>{
  const go=new Go(); let inst=null; let snaps=[]; let sp190=0; let inf=false;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!inst) return;
    if(idx===3190){ sp190=inst.exports.g0(); inf=true; }
    if(inf && idx!==3190){ // snapshot on first callee inside f3190
      const m=Buffer.from(inst.exports.mem.buffer);
      snaps.push([idx, sp190, Buffer.from(m.slice(sp190, sp190+256))]);
      if(snaps.length>6) inf=false;
    }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);
  const inp=Buffer.concat([c.update(Buffer.alloc(48)),c.final()]).toString('base64');
  globalThis.check(inp);
  snaps.forEach(([idx,sp,buf],i)=>{
    console.log(`snap${i} after-call-f${idx} sp=${sp.toString(16)}`);
    console.log('  ',buf.slice(0,128).toString('hex'));
  });
  process.exit(0);
})();
