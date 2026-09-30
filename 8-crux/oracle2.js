// Fast oracle: feed raw messages (hex on argv, comma-separated) and report call counts of key funcs + result.
// 3269>0 means the parser (func3267) succeeded on that message.
require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkFromMsg(msg){ // pkcs7 pad to 48
  const padlen=48-msg.length; if(padlen<1||padlen>16) throw new Error("msg len must be 32..47, got "+msg.length);
  const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);
  const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);
  return Buffer.concat([c.update(p),c.final()]).toString('base64');
}
const WASM=fs.readFileSync('main_instr.wasm');
const watch=[3267,3269,3251,3252,3254,3272,2992,3242,3190];
async function runOne(msg){
 const cnt={};let on=false;
 const go=new Go();
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(WASM,go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 on=true;let r;try{r=check(mkFromMsg(msg));}catch(e){r="ERR:"+e.message;}on=false;
 return {r,cnt};
}
(async()=>{
 let msgs=process.argv.slice(2);
 if(msgs.length===0) msgs=["00"+"00".repeat(31)];
 for(const h of msgs){
   let msg=Buffer.from(h,'hex');
   if(msg.length<32) msg=Buffer.concat([msg,Buffer.alloc(32-msg.length,0)]);
   const {r,cnt}=await runOne(msg);
   console.log("msg["+msg.length+"]="+msg.toString('hex'));
   console.log("   r="+JSON.stringify(r)+" | "+watch.map(w=>w+":"+(cnt[w]||0)).join(" ")+(cnt[3269]?"  <== PARSED OK":""));
 }
 process.exit(0);
})();
