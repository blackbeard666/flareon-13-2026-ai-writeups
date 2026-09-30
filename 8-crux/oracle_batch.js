// Fast batch oracle: reuse one wasm instance across many messages; reinstantiate only on crash.
// Reads newline-separated hex messages from a file (argv[2]); prints per-message func counts.
require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const WASM=fs.readFileSync('main_instr.wasm');
function mk(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)throw new Error("len");const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const watch=[3267,3269,3251,3252,3254,3272,2992,3242,3249,3250];
let cnt={},on=false;
async function fresh(){
 const go=new Go();
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(WASM,go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 return globalThis.check;
}
(async()=>{
 let check=await fresh();
 const file=process.argv[2];
 let lines;
 if(file&&fs.existsSync(file)) lines=fs.readFileSync(file,'utf8').split(/\r?\n/).filter(x=>x.trim());
 else lines=process.argv.slice(2);
 for(const raw of lines){
   const parts=raw.split(/\s+/); const hex=parts[parts.length-1]; const label=parts.length>1?parts.slice(0,-1).join(' '):'';
   let msg; try{msg=Buffer.from(hex,'hex');}catch(e){continue;}
   if(msg.length<32||msg.length>47){console.log((label||hex)+" SKIP len"+msg.length);continue;}
   cnt={};on=true;let r,crashed=false;
   try{r=check(mk(msg));}catch(e){r="ERR:"+e.message;crashed=true;}
   on=false;
   if(crashed){ check=await fresh(); } // recover for next
   const hit=cnt[3272]?" *** 3272 ***":(cnt[2992]?" ** 2992 **":(cnt[3269]?" [parsed]":""));
   console.log((label||hex)+" | "+watch.map(w=>w+":"+(cnt[w]||0)).join(" ")+" r="+JSON.stringify(r)+hit);
 }
 process.exit(0);
})();
