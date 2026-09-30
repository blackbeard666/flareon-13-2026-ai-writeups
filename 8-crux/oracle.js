require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let cnt=0;
  go.importObject.env={trace:(i)=>{ if(tracing) cnt++; }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function measure(buf48){ // buf48: Buffer of 48 bytes
    const b64=buf48.toString('base64'); // 64 chars
    let m=1e9; for(let r=0;r<3;r++){ tracing=true;cnt=0; check(b64); tracing=false; if(cnt<m)m=cnt; }
    return m;
  }
  // determinism check
  const base=Buffer.from("00108310518720928b30d38f69b71d79f8218a39259a7a29d35db7e39ebbf3dfbf00108310518720928b30d38f411493","hex");
  console.log("base(ABCDEFGH decoded) len:", measure(base), "b64:", base.toString('base64'));
  console.log("allzero:", measure(Buffer.alloc(48)));
  console.log("allFF:", measure(Buffer.alloc(48,0xff)));
  // vary byte 0 across all values, see count
  let counts={};
  for(let v=0; v<256; v++){ const b=Buffer.alloc(48); b[0]=v; const c=measure(b); (counts[c]=counts[c]||[]).push(v); }
  console.log("byte0 vary (from allzero base): count -> #values");
  for(const [c,vs] of Object.entries(counts)) console.log("  count",c,"->",vs.length,"values; e.g.",vs.slice(0,5));
  process.exit(0);
})();
