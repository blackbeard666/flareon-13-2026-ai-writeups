require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
let check, cnt={};
function run(M){
  for(const k in cnt) delete cnt[k];
  const r=check(mkMsg(M));
  return {r, c3267:cnt[3267]||0, c3269:cnt[3269]||0, c3252:cnt[3252]||0, c3254:cnt[3254]||0, c3272:cnt[3272]||0, c2992:cnt[2992]||0, c3251:cnt[3251]||0};
}
(async()=>{
 const go=new Go();let on=true;
 go.importObject.env={trace:(idx)=>{ if(on) cnt[idx]=(cnt[idx]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 check=globalThis.check;
 // helper to pad a message to 32 bytes
 function M32(arr){const b=Buffer.alloc(32,0); for(let i=0;i<arr.length&&i<32;i++)b[i]=arr[i]; return b;}
 const tests={
   'allA': Buffer.alloc(32,0x41),
   'all0': Buffer.alloc(32,0),
   'b0=0': M32([0]),
   'b0=0,rest0 (already)': M32([0,0,0,0,0]),
   '0 then int': M32([0,1,0,0,0]),
   '0,1,...': M32([0,1,2,3,4,5,6,7]),
   'b0=1': M32([1,0,0,0,0]),
   'b0=2': M32([2,0,0,0,0]),
   'b0=3': M32([3,0,0,0,0]),
   'b0=4': M32([4,0,0,0,0]),
   'b0=0 b1..4=1': M32([0,1,0,0,0, 9,9,9]),
 };
 for(const [name,M] of Object.entries(tests)){
   const o=run(M);
   console.log(name.padEnd(22), JSON.stringify(o.r).padEnd(13), "3267="+o.c3267,"3269="+o.c3269,"3251="+o.c3251,"3252="+o.c3252,"3254="+o.c3254,"3272="+o.c3272,"2992="+o.c2992);
 }
 process.exit(0);
})();
