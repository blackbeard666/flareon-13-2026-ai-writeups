require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let snap=null; let inst=null;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3244 && !snap){ snap=Buffer.from(Buffer.from(inst.exports.mem.buffer)); }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const inb=Buffer.from(process.argv[2],'hex');
  tracing=true; snap=null; const res=check(inb.toString('base64')); tracing=false;
  fs.writeFileSync(process.argv[3]||'cmpsnap.bin', snap);
  console.log("in",inb.toString('hex'),"out@3688b0",snap.slice(0x3688b0,0x3688b0+48).toString('hex'));
  process.exit(0);
})();
