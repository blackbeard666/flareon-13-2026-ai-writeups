require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_gatebypass.wasm'),go.importObject);
 go.run(instance); await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const msgs={};
 // leaf node: 01 | childCount0 | keyLen0 | valLen19 | 19 bytes (last nonzero) = 32 bytes
 msgs['leaf_val19']=Buffer.concat([Buffer.from([1]),u32(0),u32(0),u32(19),Buffer.from([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19])]);
 // pair/list: node with 1 child (child = leaf). outer: 01|cc1|[childLen|child]|keyLen0|valLen0
 const child=Buffer.concat([Buffer.from([1]),u32(0),u32(0),u32(2),Buffer.from([1,1])]); // 13-ish
 const outer=Buffer.concat([Buffer.from([1]),u32(1),u32(child.length),child,u32(0),u32(0)]);
 msgs['list1']=outer;
 // known msg from summary (32 bytes)
 msgs['summary32']=Buffer.from("0100000000000000001300000001010101010101010101010101010101010101","hex");
 for(const [name,msg] of Object.entries(msgs)){
   if(msg.length<32||msg.length>47){ console.log(name,"len",msg.length,"OUT OF RANGE"); continue; }
   try{ const r=check(mk(msg)); console.log(name,"len",msg.length,"->",JSON.stringify(r)); }
   catch(e){ console.log(name,"ERR:",e.message); }
 }
 process.exit(0);
})();
