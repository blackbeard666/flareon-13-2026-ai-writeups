// deterministic randomness so map seeds are fixed across instances
const _crypto=require('crypto');
globalThis.crypto={ getRandomValues:(a)=>{ a.fill(0); return a; } };
require('./wasm_exec.js');
const fs=require('fs'); const bytes=fs.readFileSync('main.wasm');
async function runDump(inp){
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(bytes,go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  globalThis.check(inp);
  return Buffer.from(instance.exports.mem.buffer);
}
function difRanges(a,b,lo,hi){let R=[],s=-1;for(let x=lo;x<hi;x++){if(a[x]!==b[x]){if(s<0)s=x;}else{if(s>=0){R.push([s,x]);s=-1;}}}if(s>=0)R.push([s,hi]);return R;}
function difc(a,b,lo,hi){let n=0;for(let x=lo;x<hi;x++)if(a[x]!==b[x])n++;return n;}
(async()=>{
  const base="ABCDEFGHIJKLMNOPabcdefghijklmnop0123456789+/ABCDEFGHIJKLMNOPQRST";
  const A=await runDump(base), A2=await runDump(base);
  console.log("same-input diff (should be ~0):", difc(A,A2,0x300000,0x3a0000));
  for(const pos of [0,1,10,32,63]){
    const arr=base.split('');arr[pos]=(arr[pos]==='Z'?'a':'Z');
    const B=await runDump(arr.join(''));
    const R=difRanges(A,B,0x300000,0x3a0000).filter(r=>r[1]-r[0]>=1);
    console.log("pos "+pos+": diffbytes="+difc(A,B,0x300000,0x3a0000)+" ranges="+R.length+" first="+R.slice(0,6).map(r=>r[0].toString(16)+":"+(r[1]-r[0])).join(","));
  }
  process.exit(0);
})();
