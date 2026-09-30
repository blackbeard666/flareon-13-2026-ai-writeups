// Map the leaf-KEY (suspected opcode) dimension.
const O=require('./oracle_map.js');
const fs=require('fs');require('./wasm_exec.js');const crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const WASM=fs.readFileSync('main_instr2.wasm');
function mk(msg){const p=Buffer.concat([msg,Buffer.alloc(48-msg.length,48-msg.length)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const watch=[3269,3190,3268,3256,3254,3251,3257,3258,3252,3272,2992,3270];
let C={},on=false;
async function fresh(){const go=new Go();go.importObject.env={trace:(i)=>{if(on)C[i]=(C[i]||0)+1;}};const {instance}=await WebAssembly.instantiate(WASM,go.importObject);go.run(instance);await new Promise(r=>setImmediate(r));return globalThis.check;}
(async()=>{
 let check=await fresh();
 async function T(label,msg){
   if(msg.length<32||msg.length>47){console.log(label.padEnd(22)+" SKIP len="+msg.length);return;}
   C={};on=true;let r,crash=false;try{r=check(mk(msg));}catch(e){r="ERR:"+e.message;crash=true;}on=false;
   const g=w=>C[w]||0;const accept=g(3190)>=2||g(3272)>0||g(2992)>0;
   const rs=(r===undefined)?"undefined":JSON.stringify(r);
   const note=(rs!=='"Bad input"')?"  <== "+(accept?"ACCEPT":"NONSTD"):"";
   console.log(label.padEnd(22)+" 3190="+g(3190)+" ["+watch.map(w=>g(w)).join(',')+"] "+rs+note);
   if(crash)check=await fresh();
   return {g,accept,r};
 }
 console.log("watch order: ["+watch.join(',')+"]");
 console.log("=== KEY sweep, val=1 ===");
 for(let K=0;K<=48;K++){await T(`k=${K},v=1`,O.node([O.leaf(K===0?null:O.bigLE(K),1)],0,null));}
 console.log("=== KEY sweep, val=2 ===");
 for(let K=0;K<=12;K++){await T(`k=${K},v=2`,O.node([O.leaf(K===0?null:O.bigLE(K),2)],0,null));}
 console.log("=== VAL sweep at key=2 ===");
 for(let V=1;V<=20;V++){await T(`k=2,v=${V}`,O.node([O.leaf(2,O.bigLE(V))],0,null));}
 process.exit(0);
})();
