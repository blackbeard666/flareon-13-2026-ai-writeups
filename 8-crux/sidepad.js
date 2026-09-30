const crypto=require('crypto');
require('./wasm_exec.js');
const fs=require('fs');
const sched=Buffer.from("7ababeca1d8056d11c38821cc4a3b87c3c2cae066ca968d1843637d82387bfcd","hex");
const key=Buffer.alloc(32); for(let i=0;i<32;i+=4) for(let j=0;j<4;j++) key[i+j]=sched[i+3-j];
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function enc(pt){ const c=crypto.createCipheriv('aes-256-cbc',key,iv); c.setAutoPadding(false); return Buffer.concat([c.update(pt),c.final()]); }
(async()=>{
  const go=new Go();
  let tracing=false; let cnt=0;
  go.importObject.env={trace:(i)=>{ if(tracing)cnt++; }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function measure(pt){ const b64=enc(pt).toString('base64'); let m=1e9; for(let r=0;r<6;r++){ tracing=true;cnt=0; check(b64); tracing=false; if(cnt<m)m=cnt;} return m; }
  // baseline invalid padding: plaintext random no pad
  const inv=Buffer.alloc(48,0x41);
  console.log("invalid-pad (48 A):", measure(inv));
  // valid padding variants (full block pad 0x10)
  const v16=Buffer.concat([Buffer.alloc(32,0x41),Buffer.alloc(16,0x10)]);
  console.log("valid-pad 32A+pad16:", measure(v16));
  // valid pad 0x01 (47 data +1)
  const v1=Buffer.concat([Buffer.alloc(47,0x41),Buffer.from([1])]);
  console.log("valid-pad 47A+01:", measure(v1));
  // different data content, same padding
  for(const c of [0x00,0x41,0x66,0xff]){
    const p=Buffer.concat([Buffer.alloc(32,c),Buffer.alloc(16,0x10)]);
    console.log("32*"+c.toString(16)+"+pad16:",measure(p));
  }
  // vary byte0 of plaintext with pad16, see if any value stands out
  let dist={};
  for(let v=0;v<256;v++){ const p=Buffer.concat([Buffer.from([v]),Buffer.alloc(31,0x41),Buffer.alloc(16,0x10)]); const m=measure(p); (dist[m]=dist[m]||[]).push(v); }
  console.log("byte0 vary counts:");
  for(const [c,vs] of Object.entries(dist).sort((a,b)=>b[0]-a[0])) console.log("  ",c,"->",vs.length,"vals; eg",vs.slice(0,6));
  process.exit(0);
})();
