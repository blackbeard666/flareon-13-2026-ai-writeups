require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let ev=[];
 function q(o){return Number(DV.getBigUint64(o,true));}
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3267){ const l=q(sp+16); ev.push(['P',l]); }
   else if([3269,3251,3252,3254,3272,2992].includes(idx)) ev.push([idx]);
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function T(name,M){ on=true;ev=[];const r=check(mkMsg(M));on=false;
   const nP=ev.filter(e=>e[0]==='P').length; const o=ev.filter(e=>e[0]!=='P').map(e=>e[0]);
   console.log(name.padEnd(28),"parses="+nP, "others=["+o.join(',')+"]", JSON.stringify(r)); }
 // child node candidates of various tag/length
 for(let tag=0;tag<=6;tag++){
   for(const plen of [1,5,9]){
     const child=Buffer.concat([Buffer.from([tag]), Buffer.alloc(plen-1,0)]);
     const M=Buffer.concat([Buffer.from([1]),i32(2),i32(child.length),child,i32(child.length),child]);
     T(`list2[tag${tag},len${plen}]`, M);
   }
 }
 process.exit(0);
})();
