require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,on=false,aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(idx===3190)aesN++; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const msg=Buffer.from(fs.readFileSync(process.argv[2],'utf8').trim(),'hex');
 on=true;let r;try{r=globalThis.check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("file="+process.argv[2]+" result="+JSON.stringify(r)+" aesN="+aesN);
 process.exit(0);
})();
