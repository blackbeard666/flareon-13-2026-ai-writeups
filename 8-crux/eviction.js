require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; const hist=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    const m=Buffer.from(inst.exports.mem.buffer);
    const v=m.slice(0x368870,0x368870+160).toString('hex');
    if(hist.length===0 || hist[hist.length-1][1]!==v) hist.push([idx,v]);
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const inb=Buffer.from(process.argv[2],'hex');
  tracing=true; const res=check(inb.toString('base64')); tracing=false;
  console.log("result",JSON.stringify(res),"distinct states:",hist.length);
  // print last 8 distinct states
  for(const [idx,v] of hist.slice(-8)) console.log("f"+idx, v);
  process.exit(0);
})();
