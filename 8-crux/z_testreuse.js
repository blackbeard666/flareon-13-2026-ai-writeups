require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance); await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const certP=fs.readFileSync('certP.b64','utf8').trim();
 for(let i=0;i<5;i++){
   let r; try{ r=check(certP); }catch(e){ r='ERR:'+e.message; }
   console.log("call#"+i,"certP =>",JSON.stringify(r));
 }
 // also test a short bogus
 console.log("bogus =>", JSON.stringify(check("AAAA")));
 process.exit(0);
})();
