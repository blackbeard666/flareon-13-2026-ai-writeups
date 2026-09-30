require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let seq=[];let on=false;
 go.importObject.env={trace:(i)=>{ if(on&&i>=3150){ if(seq.length===0||seq[seq.length-1][0]!==i)seq.push([i,1]);else seq[seq.length-1][1]++; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2]||"01010000000f000000010000000001000000020100000001010000000100000000","hex");
 on=true;check(mk(msg));on=false;
 console.log(seq.map(([i,c])=>c>1?i+"x"+c:""+i).join(" "));
 process.exit(0);
})();
