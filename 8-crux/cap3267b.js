require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
function mkRaw(P){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(P),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let caps=[];
 function q(o){return DV.getBigUint64(o,true);}
 function hx(o,n){o=Number(o);if(o<=0||o+n>U8.length)return "OOB";return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){
     const p1=Number(q(sp+8)), l=Number(q(sp+16));
     const inlineHex = Buffer.from(U8.slice(sp+32,sp+64)).toString('hex');
     caps.push({argP:hx(p1,l),len:l,inline:inlineHex});
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const tests=[Buffer.from("A".repeat(32)),Buffer.from("B".repeat(32)),Buffer.alloc(32,0)];
 for(const M of tests){
   on=true;caps=[];check(mkMsg(M));on=false;
   const sha=crypto.createHash('sha256').update(M).digest('hex');
   console.log("M="+M.slice(0,4).toString('hex')+"...","sha256(P[:32])="+sha);
   for(const c of caps) console.log("   argP="+c.argP,"| inline="+c.inline);
 }
 process.exit(0);
})();
