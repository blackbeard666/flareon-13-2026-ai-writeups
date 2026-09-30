require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let ev=[];
 function q(o){return Number(DV.getBigUint64(o,true));}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){ const p=q(sp+8),l=q(sp+16); let bytes=''; if(p>0x1000&&p+Math.min(l,20)<U8.length) bytes=Buffer.from(U8.slice(p,p+Math.min(l,20))).toString('hex'); ev.push(['P',l,bytes]); }
   else if([3269,3251,3252,3254,3272,2992].includes(idx)) ev.push([idx]);
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function T(name,M){
   on=true;ev=[];const r=check(mkMsg(M));on=false;
   const p=ev.filter(e=>e[0]==='P'); const o=ev.filter(e=>e[0]!=='P').map(e=>e[0]);
   console.log("--- "+name+" ("+M.length+"B) => "+JSON.stringify(r));
   p.forEach((e,i)=>console.log("   parse#"+i+" len="+e[1]+" bytes="+e[2]));
   if(o.length) console.log("   others:",o.join(','));
 }
 const leaf0=Buffer.from([0,0]);
 T('leaf0', leaf0);
 T('leaf0 3B', Buffer.from([0,0,0]));
 // list N=1 child=leaf0(2B): [1][N=1][childlen=2][00 00]
 T('list1[leaf0]', Buffer.concat([Buffer.from([1]),i32(1),i32(2),leaf0]));
 // list N=2 children leaf0,leaf0
 T('list2[leaf0,leaf0]', Buffer.concat([Buffer.from([1]),i32(2),i32(2),leaf0,i32(2),leaf0]));
 // tag2 exact small
 T('tag2 5B', Buffer.from([2,0,0,0,0]));
 T('tag2 9B', Buffer.from([2,1,0,0,0,0,0,0,0]));
 T('tag3 5B', Buffer.from([3,1,0,0,0]));
 // nested list
 T('list1[list1[leaf0]]', (()=>{const inner=Buffer.concat([Buffer.from([1]),i32(1),i32(2),leaf0]);return Buffer.concat([Buffer.from([1]),i32(1),i32(inner.length),inner]);})());
 process.exit(0);
})();
