require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let seq=[];let on=false;
 go.importObject.env={trace:(idx)=>{ if(on){ if(seq.length===0||seq[seq.length-1][0]!==idx) seq.push([idx,1]); else seq[seq.length-1][1]++; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const M=Buffer.from("A".repeat(32));
 on=true;check(mk(M));on=false;
 // print compressed sequence, only funcs >=3000 to reduce noise, but keep all with counts
 const s=seq.map(([i,c])=>c>1?`${i}x${c}`:`${i}`).join(' ');
 fs.writeFileSync('seq_valid.txt',s);
 console.log("len events(compressed):",seq.length);
 console.log(s.slice(0,4000));
 process.exit(0);
})();
