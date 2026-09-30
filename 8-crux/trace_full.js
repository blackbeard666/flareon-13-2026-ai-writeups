require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; const seq=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(i)=>{ if(tracing && seq.length<6000000) seq.push(i); };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const b64=fs.readFileSync('inp.bin').toString('base64');
  console.log("input:",b64,"len",b64.length);
  tracing=true; seq.length=0;
  const res=check(b64);
  tracing=false;
  console.log("result:",JSON.stringify(res),"total calls:",seq.length);
  const cnt={}; for(const f of seq) cnt[f]=(cnt[f]||0)+1;
  const top=Object.entries(cnt).sort((a,b)=>b[1]-a[1]);
  console.log("TOP called funcs:"); for(const [f,c] of top.slice(0,25)) console.log("  f"+f, c);
  // last unique funcs (tail)
  const tail=seq.slice(-400);
  const seen=new Set(); const order=[];
  for(let i=seq.length-1;i>=0 && order.length<40;i--){ if(!seen.has(seq[i])){seen.add(seq[i]);order.push(seq[i]);} }
  console.log("LAST 40 distinct funcs (reverse):", order.join(","));
  console.log("LAST 60 calls:", seq.slice(-60).join(","));
  fs.writeFileSync('seq_full.json', JSON.stringify(seq));
  process.exit(0);
})();
