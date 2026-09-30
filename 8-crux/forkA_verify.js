require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)throw new Error("len "+msg.length);const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 for(const h of process.argv.slice(2)){
   const msg=Buffer.from(h,'hex');
   on=true;for(const k in cnt)delete cnt[k];const r=check(mkFromMsg(msg));on=false;
   console.log("L="+msg.length,"3267:"+(cnt[3267]||0),"3269:"+(cnt[3269]||0),(cnt[3269]?"PARSED_OK":"FAIL"),h);
 }
 process.exit(0);
})();
