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
 const lines=fs.readFileSync('z_variants.txt','utf8').trim().split('\n');
 for(const line of lines){
   const sp=line.indexOf(' ');
   const lv=line.slice(0,sp); const hex=line.slice(sp+1).trim();
   const m=Buffer.from(hex,'hex');
   let r; try{ r=check(mk(m)); }catch(e){ r='ERR:'+e.message; }
   if(r!=='Bad input'){ console.log("lv="+lv+" => "+JSON.stringify(r)); }
 }
 console.log("scan complete");
 process.exit(0);
})();
