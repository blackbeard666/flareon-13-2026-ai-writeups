require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function node(children){const parts=[b(1),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}return Buffer.concat(parts);}
function mkFromMsg(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null;let on=false;
 let n3267=0, childSp=-1, topSp=-1, cap=null;
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){ n3267++; if(n3267===1)topSp=sp; if(n3267===2){childSp=sp;} return; }
   if(childSp>=0 && cap===null && sp>childSp){
     // child returned; results near childSp. dump childSp-16..childSp+80
     const w=[];for(let i=-2;i<12;i++)w.push([(i*8),q(childSp+i*8).toString(16)]);
     cap=w;
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function test(name,msg){
   on=true;n3267=0;childSp=-1;topSp=-1;cap=null;try{check(mkFromMsg(msg));}catch(e){}on=false;
   console.log(name,"n3267="+n3267);
   if(cap)for(const[o,v]of cap)console.log("   childSp"+(o>=0?"+"+o:o)+" = "+v);
 }
 test("node(leaf00)", node([b(0)]));  // child = [00] len1
 process.exit(0);
})();
