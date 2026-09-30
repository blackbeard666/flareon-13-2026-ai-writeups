require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null;let caps=[];let on=false;
 go.importObject.env={trace:(idx)=>{
   if(on&&idx===3190&&inst){
     const b=Buffer.from(inst.exports.mem.buffer);
     const g1=b.readBigUInt64LE(0x2098f0);
     const ptr=b.readUInt32LE(0x2098f8);
     let off48='n/a';
     if(ptr&&ptr+52<b.length) off48=b.readUInt32LE(ptr+48).toString(16);
     caps.push({g1:g1.toString(16),ptr:ptr.toString(16),off48});
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 for(const M of [Buffer.from("A".repeat(32)),Buffer.from("B".repeat(32)),Buffer.from("A".repeat(32))]){
   on=true;caps=[];check(mk(M));on=false;
   console.log("M="+String.fromCharCode(M[0])+"*32:",JSON.stringify(caps));
 }
 process.exit(0);
})();
