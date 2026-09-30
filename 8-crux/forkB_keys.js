require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let keys=[];let reached=false;
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3269) reached=true;
   if(idx===3251){ const w=[];for(let i=1;i<=4;i++)w.push(q(sp+i*8).toString(16)); keys.push(w.join(',')); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function T(M){ on=true;keys=[];reached=false;let r;try{r=check(mkMsg(M));}catch(e){r='ERR';} on=false; return {r,reached,keys:keys.slice()}; }
 // enumerate leaf node encodings: tag,len,payload patterns
 const cands=[];
 for(let tag=0;tag<6;tag++) for(let len=1;len<=9;len++){
   const b=Buffer.alloc(len); b[0]=tag;
   // payload = 1 in first payload byte
   if(len>1) b[1]=1;
   cands.push([`tag${tag}.len${len}.p1`,Buffer.from(b)]);
   if(len>=5){ const c=Buffer.alloc(len);c[0]=tag;c[1]=0x2a; cands.push([`tag${tag}.len${len}.42`,c]); }
 }
 // list wrapping a leaf child of each tag/len
 for(let ctag=0;ctag<6;ctag++) for(const clen of [1,5,9]){
   const child=Buffer.alloc(clen); child[0]=ctag; if(clen>1)child[1]=0x2a;
   const M=Buffer.concat([Buffer.from([1]),i32(1),i32(child.length),child]);
   cands.push([`list[tag${ctag}.len${clen}]`,M]);
 }
 for(const [name,M] of cands){
   const o=T(M);
   if(o.reached) console.log(name.padEnd(24),"REACHED keys=["+o.keys.join(' | ')+"]", JSON.stringify(o.r));
 }
 process.exit(0);
})();
