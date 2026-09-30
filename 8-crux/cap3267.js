require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let caps=[];
 function q(o){return Number(DV.getBigUint64(o,true));}
 function hx(o,n){if(o<=0||o+n>U8.length)return "OOB@"+o.toString(16);return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267 && caps.length<3){
     const rec={sp:sp.toString(16)};
     // dump sp+0..sp+64 as u64
     const words=[];for(let i=0;i<9;i++){const v=q(sp+i*8);words.push(v.toString(16));}
     rec.words=words;
     // follow each word as pointer, dump 48 bytes
     rec.derefs=[];
     for(let i=0;i<9;i++){const p=q(sp+i*8); if(p>0x10000 && p<U8.length-48) rec.derefs.push([i,p.toString(16),hx(p,48)]);}
     caps.push(rec);
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 on=true;caps=[];const r=check(mkMsg(Buffer.from("A".repeat(32))));on=false;
 console.log("result:",JSON.stringify(r),"num3267:",caps.length);
 for(const c of caps){console.log("sp="+c.sp,"words=",c.words.join(","));for(const d of c.derefs)console.log("   arg"+d[0]+"@"+d[1]+" ->",d[2]);}
 process.exit(0);
})();
