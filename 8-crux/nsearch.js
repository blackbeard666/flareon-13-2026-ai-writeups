require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let cnt=0;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.log32=()=>{cnt++;};
  go.importObject.env.log64=()=>{cnt++;};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_cmp.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  function toB64(v){ // v BigInt -> 48 bytes big-endian -> base64
    const b=Buffer.alloc(48);
    let x=v;
    for(let i=47;i>=0;i--){ b[i]=Number(x & 0xffn); x>>=8n; }
    return b.toString('base64');
  }
  function count(v){ cnt=0; let r; try{r=check(toB64(v));}catch(e){return -1;} return cnt; }
  const THRESH=1000;
  function passes(v){ return count(v) > THRESH; } // v < n  => passes precondition
  // sanity
  console.log("count(0)=",count(0n));
  console.log("count(2^384-1)=",count((1n<<384n)-1n));
  console.log("count(2^383)=",count(1n<<383n));
  // binary search: largest value that passes is n-1
  let lo=0n, hi=(1n<<384n)-1n;
  // ensure lo passes and hi fails
  if(!passes(lo)){ console.log("lo doesn't pass!"); }
  if(passes(hi)){ console.log("hi passes -> n may be 2^384"); }
  while(lo+1n<hi){
    const mid=(lo+hi)>>1n;
    if(passes(mid)) lo=mid; else hi=mid;
  }
  // lo passes, hi fails => n = hi
  console.log("n (hi) =", hi.toString());
  console.log("n hex  = 0x"+hi.toString(16));
  console.log("lo     =", lo.toString());
  console.log("verify count(n-1)=",count(lo),"count(n)=",count(hi));
  process.exit(0);
})();
