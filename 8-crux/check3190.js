const crypto=require('crypto');
require('./wasm_exec.js');
const fs=require('fs');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkInput(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
  const go=new Go(); let tracing=false; const cnt={};
  go.importObject.env={trace:(i)=>{ if(tracing) cnt[i]=(cnt[i]||0)+1; }};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
  go.run(instance);await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  // crafted valid-AES P (32-byte message), reaches gate
  for(const M of [Buffer.from("A".repeat(32)), Buffer.from("A".repeat(40)), Buffer.alloc(32,0)]){
    tracing=true; for(const k in cnt) delete cnt[k]; const r=check(mkInput(M)); tracing=false;
    console.log("M="+M.length+"B result="+JSON.stringify(r)+" | func3190 called: "+(cnt[3190]||0)+"x, func3050(SHA):"+(cnt[3050]||0)+"x, func3217:"+(cnt[3217]||0)+"x, func3267:"+(cnt[3267]||0)+"x");
  }
  // random64
  tracing=true; for(const k in cnt) delete cnt[k]; check("A".repeat(64)); tracing=false;
  console.log("badlen-ish A*64: func3190="+(cnt[3190]||0)+" func3050="+(cnt[3050]||0));
  process.exit(0);
})();
