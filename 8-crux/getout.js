require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let out=null; let inst=null;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3181){ // post-crypto: output ready at 0x3688b0
      const m=Buffer.from(inst.exports.mem.buffer);
      out=Buffer.from(m.slice(0x3688b0,0x3688b0+48));
    }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const hexin=process.argv[2];
  const inb=Buffer.from(hexin,'hex');
  const b64=inb.toString('base64');
  tracing=true; out=null; const res=check(b64); tracing=false;
  console.log("in ",inb.toString('hex'));
  console.log("out",out?out.toString('hex'):'null');
  const ks=Buffer.alloc(48); for(let i=0;i<48;i++) ks[i]=inb[i]^(out?out[i]:0);
  console.log("ks ",ks.toString('hex'));
  process.exit(0);
})();
