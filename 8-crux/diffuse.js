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
function difBytes(a,b,lo,hi){ let n=0; for(let x=lo;x<hi;x++) if(a[x]!==b[x])n++; return n; }
(async()=>{
  const base="ABCDEFGHIJKLMNOPabcdefghijklmnop0123456789+/ABCDEFGHIJKLMNOPQRST";
  const m0=await runDump(base);
  // change char at pos 0, 1, 32, 63
  for(const pos of [0,1,2,32,63]){
    const arr=base.split(''); arr[pos]= (arr[pos]==='Z'?'a':'Z'); const inp=arr.join('');
    const m=await runDump(inp);
    console.log("pos "+pos+" changed: heap-diff bytes ="+difBytes(m0,m,0x340000,0x3a0000));
  }
  process.exit(0);
})();
