require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false;let cnt=0;
  go.importObject.env={trace:(i)=>{if(tracing)cnt++;}};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance);await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function mc(inp){let m=1e9;for(let r=0;r<8;r++){tracing=true;cnt=0;check(inp);tracing=false;if(cnt<m)m=cnt;}return m;}
  // exact length test around 64
  for(const L of [62,63,64,65,66]) console.log("L="+L, mc("A".repeat(L)));
  // base64 vs non-base64 at 64
  console.log("64 valid b64 (A):", mc("A".repeat(64)));
  console.log("64 spaces:", mc(" ".repeat(64)));
  console.log("64 '@':", mc("@".repeat(64)));
  console.log("64 with '=' pad:", mc("A".repeat(62)+"=="));
  console.log("64 mixed b64:", mc("ABCDEFGHabcdefgh01234567+/ABCDEFGHabcdefgh01234567+/ABCDEFGHabcd"));
  // does one non-b64 char in middle drop it?
  console.log("64 one bad char @32:", mc("A".repeat(32)+" "+"A".repeat(31)));
  process.exit(0);
})();
