require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let ev=[];
 function q(o){return Number(DV.getBigUint64(o,true));}
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3267){const p=q(sp+8),l=q(sp+16);let b='';if(p>0x1000&&p+Math.min(l,48)<U8.length)b=Buffer.from(U8.slice(p,p+Math.min(l,48))).toString('hex');ev.push([l,b]);}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 for(const [n,M] of [['[0]',Buffer.from([0])],['[1]+12z',Buffer.concat([Buffer.from([1]),Buffer.alloc(12,0)])]]){
   on=true;ev=[];const r=check(mkMsg(M));on=false;
   console.log("=== "+n+" => "+JSON.stringify(r)+" | parse calls: "+ev.length);
   ev.forEach((e,i)=>console.log("  #"+i+" len="+e[0]+" bytes="+e[1]));
 }
 process.exit(0);
})();
