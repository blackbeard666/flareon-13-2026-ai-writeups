require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const needle=Buffer.from("6239eee47f337eaf","hex"); // 0xaf7e337fe4ee3962 LE
(async()=>{
 let inst=null,U8=null;let on=false;let best=null;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3251||idx===3254||idx===3256||idx===3257){
     const m=Buffer.from(inst.exports.mem.buffer);
     let i=m.indexOf(needle);
     if(i>=0){ best={ev:idx, at:i, ctx:m.slice(i-8,i+56).toString('hex')}; }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2]||"0100000000000000001300000001010101010101010101010101010101010101","hex");
 on=true;check(mk(msg));on=false;
 // also scan final memory
 const m=Buffer.from(instance.exports.mem.buffer);
 let all=[]; let i=m.indexOf(needle); while(i>=0){all.push(i.toString(16));i=m.indexOf(needle,i+1);}
 console.log("msg="+msg.toString('hex'));
 console.log("post-eval-const during check:", best?JSON.stringify(best):"NOT SEEN");
 console.log("post-eval-const in final mem:", all.length, all.slice(0,4).join(","));
 if(all.length){const p=parseInt(all[0],16);console.log("  region:",m.slice(p-40,p+72).toString('hex'));}
 process.exit(0);
})();
