require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let ev=[];
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if([3269,3251,3254,3250,3256,3257,3258,3268].includes(idx)){
     const w=[];for(let i=1;i<=6;i++)w.push(q(sp+i*8).toString(16));
     ev.push([idx,w]);
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function T(name,M){ on=true;ev=[];const r=check(mkMsg(M));on=false;
   console.log("=== "+name+" => "+JSON.stringify(r));
   ev.forEach(([i,w])=>console.log("  f"+i+": "+w.join(' '))); }
 T('leaf[0]', Buffer.from([0]));
 T('emptylist', Buffer.concat([Buffer.from([1]),i32(0)]));
 process.exit(0);
})();
