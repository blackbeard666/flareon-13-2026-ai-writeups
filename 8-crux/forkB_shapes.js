require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
// node builders
const V=(x)=>Buffer.from([0,x&255]);            // 0x4ef80 value node (2 bytes, byte0=0,len>=2)
const LST=(...ch)=>Buffer.concat([Buffer.from([1]),i32(ch.length),...ch.map(c=>Buffer.concat([i32(c.length),c]))]);
const EMPTY=Buffer.from([0]);                     // empty list 0x4ef40
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let reached=false;let keys=[];
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3269)reached=true;
   if(idx===3251){const w=[];for(let i=1;i<=4;i++)w.push(q(sp+i*8).toString(16));keys.push(w.join(','));}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function T(name,M){on=true;reached=false;keys=[];let r;try{r=check(mkMsg(M));}catch(e){r='ERR '+e.message;}on=false;
   console.log(name.padEnd(30),"len="+M.length,"3269="+reached,"keys=["+keys.join(' | ')+"]",JSON.stringify(r));}
 T('EMPTY', EMPTY);
 T('V(5)', V(5));
 T('LST(V5)', LST(V(5)));
 T('LST(V5,V6)', LST(V(5),V(6)));
 T('LST(EMPTY)', LST(EMPTY));
 T('LST(LST(V5))', LST(LST(V(5))));
 T('LST(LST(V5,V6))', LST(LST(V(5),V(6))));
 T('LST(LST(V5,V6),LST(V7,V8))', LST(LST(V(5),V(6)),LST(V(7),V(8))));
 T('LST(V5,V6,V7)', LST(V(5),V(6),V(7)));
 process.exit(0);
})();
