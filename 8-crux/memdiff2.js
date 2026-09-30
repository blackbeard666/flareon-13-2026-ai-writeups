require('./wasm_exec.js');
const fs=require('fs');
const bytes=fs.readFileSync('main.wasm');
async function runDump(inp){
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(bytes,go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  globalThis.check(inp);
  return Buffer.from(instance.exports.mem.buffer);
}
(async()=>{
  const i1="ABCDEFGHIJKLMNOPabcdefghijklmnop0123456789+/ABCDEFGHIJKLMNOPQRST";
  const i2="ZYXWVUTSRQPONMLKzyxwvutsrqponmlk9876543210/+ZYXWVUTSRQPONMLKJIHG";
  const m1=await runDump(i1), m2=await runDump(i2);
  // find differing ranges in heap region 0x340000..0x3a0000
  const lo=0x340000, hi=0x3a0000;
  let ranges=[]; let start=-1;
  for(let a=lo;a<hi;a++){
    if(m1[a]!==m2[a]){ if(start<0)start=a; }
    else { if(start>=0){ ranges.push([start,a]); start=-1; } }
  }
  if(start>=0) ranges.push([start,hi]);
  console.log("differing ranges (heap):");
  for(const [s,e] of ranges) if(e-s>=4) console.log("  "+s.toString(16)+".."+e.toString(16)+" ("+(e-s)+"B) m1:"+m1.slice(s,Math.min(e,s+32)).toString('hex'));
  process.exit(0);
})();
