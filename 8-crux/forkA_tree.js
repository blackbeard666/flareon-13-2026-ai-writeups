require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
// serializers
function node(children){ // tag 1
  const parts=[b(1),u32(children.length)];
  for(const c of children){ parts.push(u32(c.length)); parts.push(c); }
  return Buffer.concat(parts);
}
function leaf0(){ return b(0); }              // msg[0]=0,len=1
function leaf0n(...vals){ return Buffer.concat([b(0),...vals.map(u32)]); }
(async()=>{
 const go=new Go();let inst=null,DV=null;let on=false;
 let rec=0,c3252=0,reach3269=0,lens=[];
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){ lens.push(Number(q(sp+16))); rec++; }
   if(idx===3252) c3252++;
   if(idx===3269) reach3269++;
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function test(name,msgBuf){
   if(msgBuf.length>32){console.log(name,"TOO LONG",msgBuf.length);return;}
   const P=Buffer.alloc(32); msgBuf.copy(P);
   const full=Buffer.concat([P, Buffer.alloc(16,0x10)]);
   const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);
   const inp=Buffer.concat([c.update(full),c.final()]).toString('base64');
   on=true; rec=0;c3252=0;reach3269=0;lens=[]; const r=check(inp); on=false;
   console.log(name.padEnd(34), "msglen="+msgBuf.length, "rec="+rec, "lens=["+lens.join(",")+"]", "c3252="+c3252, "3269="+reach3269, "=> "+JSON.stringify(r));
 }
 test("leaf0 [00]", leaf0());
 test("node()", node([]));
 test("node(leaf0)", node([leaf0()]));
 test("node(leaf0,leaf0)", node([leaf0(),leaf0()]));
 test("node(node())", node([node([])]));
 test("node(node(leaf0))", node([node([leaf0()])]));
 test("node(node(),node())", node([node([]),node([])]));
 test("leaf0 with 4 bytes", leaf0n(0));
 test("leaf0 with val 7", leaf0n(7));
 test("node(leaf0n(7))", node([leaf0n(7)]));
 test("deep node^3", node([node([node([])])]));
 process.exit(0);
})();
