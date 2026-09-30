require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const LIST=0x83c733bn, NIL=0xb49d0978n;
(async()=>{
 let inst=null,DV=null,U8=null;let on=false;
 let first3269sp=0, last3269sp=0, n3269=0;
 let snapshots=[];
 function q(o){return DV.getBigUint64(Number(o),true);}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3269){ if(n3269===0) first3269sp=sp; last3269sp=sp; n3269++; }
   // after 3269 activity, capture at treap/getWithKey calls
   if((idx===3251||idx===3274||idx===3266) && first3269sp){
     snapshots.push([idx, sp]);
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2]||"01010000000d0000000100000000000000000000000000000000020000000101","hex");
 on=true;check(mk(msg));on=false;
 console.log("msg="+msg.toString('hex'),"n3269="+n3269,"first3269sp=0x"+first3269sp.toString(16));
 // scan a window around the outermost 3269 frame for the type-hashes
 function scanHashes(base,lo,hi){
   const hits=[];
   for(let o=base-lo;o<base+hi;o+=4){ if(o<0||o+8>U8.length)continue; const v=DV.getBigUint64(o,true)&0xffffffffn; if(v===LIST)hits.push([o-base,'LIST']); if(v===NIL)hits.push([o-base,'NIL']); }
   return hits;
 }
 console.log("hashes near first3269 frame [off:type]:", JSON.stringify(scanHashes(Number(first3269sp),64,256)));
 process.exit(0);
})();
