require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null;let on=false;
 let depth=0, outerSp=0, armed=false, grabbed=null, postSeq=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function hx(o,n){o=Number(o);if(o<=0||o+n>U8.length)return "OOB";return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3269){ if(depth===0){outerSp=Number(sp);} depth++; return; }
   // detect return of outermost: any func call while depth was decremented... we can't see returns.
   // Instead: after outerSp set, the FIRST non-3269 call with sp>outerSp means 3269 returned (stack unwound).
   if(outerSp && !armed && depth>0){
     // heuristic: capture stack region at outerSp for result
   }
   if(armed && postSeq.length<12){ postSeq.push(idx); }
 }};
 // Simpler: patch approach won't work; use snapshot after check via reading nothing.
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2],"hex");
 on=true;const r=check(mk(msg));on=false;
 console.log("r=",JSON.stringify(r),"outerSp=0x"+outerSp.toString(16));
 // dump the arg/result region of the outermost 3269 frame after completion
 console.log("frame@outerSp:", hx(outerSp, 96));
 process.exit(0);
})();
