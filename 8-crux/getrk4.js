require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; let cap=null;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{ if(tracing&&inst&&idx===3187&&!cap){cap=Buffer.from(Buffer.from(inst.exports.mem.buffer));} };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const inb=Buffer.from(process.argv[2],'hex');
  tracing=true; globalThis.check(inb.toString('base64')); tracing=false;
  const m=cap;
  for(const a of [0x374000,0x376000,0x3740f0,0x3760f0]){
    console.log(a.toString(16),'first48:',m.slice(a,a+48).toString('hex'));
  }
  fs.writeFileSync('rk376000.bin', m.slice(0x376000,0x376000+512));
  process.exit(0);
})();
