require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const cnt={};let phase="init";const byPhase={};
 const go=new Go();
 go.importObject.env={trace:(i)=>{ if(i===3272||i===2992){ cnt[i]=(cnt[i]||0)+1; (byPhase[phase]=byPhase[phase]||{})[i]=((byPhase[phase]||{})[i]||0)+1; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 phase="gorun"; go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 phase="valid_tree"; check(mk(Buffer.from("0100000000000000001300000001010101010101010101010101010101010101","hex")));
 phase="A32"; check(mk(Buffer.from("41".repeat(32),"hex")));
 phase="list2"; check(mk(Buffer.from("01020000000d0000000100000000000000000d0000000100000000000000000000000000","hex")));
 console.log("total 3272:",cnt[3272]||0,"2992:",cnt[2992]||0);
 console.log("byPhase:",JSON.stringify(byPhase));
 process.exit(0);
})();
