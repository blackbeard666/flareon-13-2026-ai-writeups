require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function node(children){const parts=[b(1),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}return Buffer.concat(parts);}
const leaf=()=>b(0);
function mkFromMsg(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;
 let topSp=-1,captured=null;
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){ if(topSp<0){topSp=sp;} return; }
   // after top-level parse: first event with sp>topSp
   if(topSp>=0 && captured===null && sp>topSp){
     const words=[];for(let i=0;i<16;i++)words.push(q(topSp+56+i*8).toString(16));
     captured=words;
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function test(name,msg){
   on=true;topSp=-1;captured=null;let r;try{r=check(mkFromMsg(msg));}catch(e){r="ERR";}on=false;
   console.log(name.padEnd(30),"L="+msg.length,"ret[topSp+56..]=",captured?captured.slice(0,10).join(","):"none");
 }
 test("bare leaf00", Buffer.concat([leaf(),Buffer.alloc(31,0)]));
 test("node 6 leaves L35", node(Array(6).fill(leaf())));
 test("A*32", Buffer.alloc(32,0x41));
 test("node()pad", Buffer.concat([node([]),Buffer.alloc(27,0)]));
 process.exit(0);
})();
