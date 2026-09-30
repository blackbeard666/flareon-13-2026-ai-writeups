// Broader opcode search: keys up to 300 + specific constants; look for any non-"Bad input" / deep profile.
const O=require('./oracle_map.js');
const fs=require('fs');require('./wasm_exec.js');const crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const WASM=fs.readFileSync('main_instr2.wasm');
function mk(msg){const p=Buffer.concat([msg,Buffer.alloc(48-msg.length,48-msg.length)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const base=[3269,3190,3268,3256,3254,3251,3257,3258,3252];
let C={},on=false;
async function fresh(){const go=new Go();go.importObject.env={trace:(i)=>{if(on)C[i]=(C[i]||0)+1;}};const {instance}=await WebAssembly.instantiate(WASM,go.importObject);go.run(instance);await new Promise(r=>setImmediate(r));return globalThis.check;}
(async()=>{
 let check=await fresh();
 const baseProf="2,1,0,1,1,5,1,0,4"; // the shallow-reject profile
 async function T(label,msg){
   if(msg.length<32||msg.length>47){return;}
   C={};on=true;let r,crash=false;try{r=check(mk(msg));}catch(e){r="ERR";crash=true;}on=false;
   const g=w=>C[w]||0;const prof=base.map(w=>g(w)).join(',');
   const interesting=(prof!==baseProf)||(r!=="Bad input");
   if(interesting) console.log(label.padEnd(20)+" ["+prof+"] "+(r===undefined?"undefined":JSON.stringify(r))+(g(3190)>=2?"  <<<3190==2>>>":""));
   if(crash)check=await fresh();
 }
 console.log("baseline shallow-reject profile ["+base.join(',')+"] = ["+baseProf+"]; only deviations printed:");
 for(let K=49;K<=300;K++){await T(`k=${K},v=1`,O.node([O.leaf(O.bigLE(K),1)],0,null));}
 // specific constants of interest
 for(const K of [0x45,0x11d,0x11e,0x11f,0x120,255,256,1000,0x3bdf,69,0x20,0x7f,0x80,128,127]){
   await T(`k=0x${K.toString(16)},v=1`,O.node([O.leaf(O.bigLE(K),1)],0,null));
 }
 // also sweep val as operator location: leaf(1, V) for V up to 300
 console.log("--- leaf(key=1, val=V) V=3..300 deviations ---");
 for(let V=3;V<=300;V++){await T(`k=1,v=${V}`,O.node([O.leaf(1,O.bigLE(V))],0,null));}
 console.log("done");
 process.exit(0);
})();
