require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
// raw plaintext P (48 bytes) - no pkcs7 auto pad; we set it fully
function mkRaw(P){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);const buf=Buffer.alloc(48);P.copy(buf);
  // pkcs7 pad to 48 requires last bytes; but to make len==32 we pad with 0x10 x16 after 32 msg bytes
  return Buffer.concat([c.update(buf),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;
 let rec=0, c3252=0, reach3269=0, firstLen=-1;
 function q(o){return DV.getBigUint64(o,true);}
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3267){ if(firstLen<0) firstLen=Number(q(sp+16)); rec++; }
   if(idx===3252) c3252++;
   if(idx===3269) reach3269++;
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 function test(name,msg32){ // msg32 is Buffer of up to 32 bytes (rest zero-padded to 32 then pkcs7 to 48)
   const P=Buffer.alloc(32); msg32.copy(P);
   // build 48-byte plaintext: 32 msg + 16 bytes of 0x10 (pkcs7 for 32-byte message)
   const full=Buffer.concat([P, Buffer.alloc(16,0x10)]);
   const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);
   const inp=Buffer.concat([c.update(full),c.final()]).toString('base64');
   on=true; rec=0;c3252=0;reach3269=0;firstLen=-1; const r=check(inp); on=false;
   console.log(name.padEnd(28), "len="+firstLen, "rec3267="+rec, "c3252="+c3252, "reach3269="+reach3269, "=> "+JSON.stringify(r));
 }
 const b=(...a)=>Buffer.from(a);
 const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
 test("all 0x41", Buffer.alloc(32,0x41));
 test("tag0 len? [00]", b(0));
 test("tag0 [00,05,06,07]", b(0,5,6,7));
 test("tag1 count0 [01,0,0,0,0]", Buffer.concat([b(1),u32(0)]));
 test("tag1 count1 +1 val", Buffer.concat([b(1),u32(1),u32(0)]));
 test("tag1 count2 +2 vals", Buffer.concat([b(1),u32(2),u32(0),u32(0)]));
 test("tag2 [02,...]", Buffer.concat([b(2),u32(1),u32(0)]));
 test("tag1 count1 val=big", Buffer.concat([b(1),u32(1),u32(0x41414141)]));
 process.exit(0);
})();
