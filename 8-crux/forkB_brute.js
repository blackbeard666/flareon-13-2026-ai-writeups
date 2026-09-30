require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const seen={};let nonbad=[];
 // all 1-byte
 for(let a=0;a<256;a++){const r=check(mkMsg(Buffer.from([a])));seen[r]=(seen[r]||0)+1;if(r!=="Bad input")nonbad.push([[a],r]);}
 // all 2-byte
 for(let a=0;a<256;a++)for(let b=0;b<256;b++){const r=check(mkMsg(Buffer.from([a,b])));seen[r]=(seen[r]||0)+1;if(r!=="Bad input")nonbad.push([[a,b],r]);}
 console.log("distinct results:",JSON.stringify(seen));
 console.log("non-bad:",JSON.stringify(nonbad.slice(0,50)));
 process.exit(0);
})();
