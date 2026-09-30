require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const r=check(mk(Buffer.from("A".repeat(32))));
 console.log("result:",JSON.stringify(r));
 const m=Buffer.from(instance.exports.mem.buffer);
 fs.writeFileSync('mem_valid.bin',m);
 // scan for printable ascii runs length>=6
 const found=new Set();
 let i=0;
 while(i<m.length){
   let j=i; while(j<m.length && m[j]>=32 && m[j]<127) j++;
   if(j-i>=6){ const s=m.slice(i,j).toString('latin1'); if(/[a-zA-Z]{4}/.test(s)) found.add(s); i=j; } else i++;
 }
 const arr=[...found];
 // filter for interesting
 const interesting=arr.filter(s=>/pad|valid|correct|wrong|flare|input|nice|congrat|success|fail|crux|error|@|format|length|byte|hash|sha|equal|match|key|flag/i.test(s));
 fs.writeFileSync('strings_interesting.txt',interesting.join('\n'));
 fs.writeFileSync('strings_all.txt',arr.join('\n'));
 console.log("total strings:",arr.length,"interesting:",interesting.length);
 console.log(interesting.slice(0,120).join('\n'));
 process.exit(0);
})();
