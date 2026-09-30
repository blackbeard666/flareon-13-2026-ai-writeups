require('./wasm_exec.js');
const fs=require('fs'); const bytes=fs.readFileSync('main.wasm');
async function runDump(inp){
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(bytes,go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  globalThis.check(inp);
  return Buffer.from(instance.exports.mem.buffer);
}
function dif(a,b,lo,hi){let n=0;for(let x=lo;x<hi;x++)if(a[x]!==b[x])n++;return n;}
(async()=>{
  const base="ABCDEFGHIJKLMNOPabcdefghijklmnop0123456789+/ABCDEFGHIJKLMNOPQRST";
  const A=await runDump(base);
  const A2=await runDump(base);           // SAME input, fresh instance
  const arr=base.split('');arr[0]='Z';
  const B=await runDump(arr.join(''));     // 1-char diff
  console.log("same-input diff:", dif(A,A2,0x340000,0x3a0000));
  console.log("1char   diff:", dif(A,B,0x340000,0x3a0000));
  process.exit(0);
})();
