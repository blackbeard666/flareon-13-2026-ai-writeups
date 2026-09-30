require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null;let on=false;let caps=[];
 function q(o){return DV.getBigUint64(Number(o),true);}
 function hx(o,n){o=Number(o);if(o<=0||o+n>U8.length)return "OOB";return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3270){
     const w=[];for(let i=0;i<10;i++)w.push(q(sp+i*8).toString(16));
     let d='';
     for(let i=1;i<10;i++){const p=Number(q(sp+i*8));if(p>0x10000&&p<U8.length-32)d+=` a${i}@${p.toString(16)}:${hx(p,24)}`;}
     caps.push({w:w.join(','),d});
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2]||"0100000000000000001300000001010101010101010101010101010101010101","hex");
 on=true;caps=[];check(mk(msg));on=false;
 console.log("func3270 called",caps.length,"times");
 caps.forEach((c,i)=>{console.log("call"+i+" w=["+c.w+"]"+c.d);});
 process.exit(0);
})();
