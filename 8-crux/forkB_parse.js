require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let ev=[];
 function q(o){return Number(DV.getBigUint64(o,true));}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){ const p=q(sp+8),l=q(sp+16); let bytes=''; if(p>0x1000&&p+Math.min(l,16)<U8.length) bytes=Buffer.from(U8.slice(p,p+Math.min(l,16))).toString('hex'); ev.push(['P',p.toString(16),l,bytes]); }
   else if([3269,3251,3252,3254,3272,2992].includes(idx)) ev.push([idx]);
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function M32(a){const b=Buffer.alloc(32,0);for(let i=0;i<a.length&&i<32;i++)b[i]=a[i];return b;}
 const tests={
   'list N=1 empty child': M32([1, 1,0,0,0]),
   'list N=1 child=[len4,tag0..]': M32([1,1,0,0,0, 5,0,0,0, 0,0,0,0,0]),
   'list N=1 child=[0]': M32([1,1,0,0,0, 0]),
   'list N=2': M32([1,2,0,0,0, 0, 0]),
   'tag2': M32([2, 0,0,0,0, 0,0,0,0,0]),
   'tag3': M32([3, 0,0,0,0]),
   'tag2 more': M32([2, 1,0,0,0, 1,0,0,0, 0]),
 };
 for(const [name,M] of Object.entries(tests)){
   on=true;ev=[];const r=check(mkMsg(M));on=false;
   const parseCalls=ev.filter(e=>e[0]==='P');
   const others=ev.filter(e=>e[0]!=='P').map(e=>e[0]);
   console.log("--- "+name+" => "+JSON.stringify(r));
   parseCalls.forEach((e,i)=>console.log("   parse#"+i+" ptr="+e[1]+" len="+e[2]+" bytes="+e[3]));
   if(others.length) console.log("   others:",others.join(','));
 }
 process.exit(0);
})();
