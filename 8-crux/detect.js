require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const needle=Buffer.from("6239eee47f337eaf","hex"); // 0xaf7e337fe4ee3962 LE
(async()=>{
 for(const [name,hex] of [
   ["single_atom","0100000000000000001300000001010101010101010101010101010101010101"],
   ["list[nil]", process.argv[2]||"01010000000d0000000100000000000000000000000000000000020000000101"],
   ["list[list[nil]]","01010000001e00000001010000000d0000000100000000000000000000000000000000000000000000000000000000"],
 ]){
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
  go.run(instance);await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const r=check(mk(Buffer.from(hex,"hex")));
  const m=Buffer.from(instance.exports.mem.buffer);
  let cnt=0,idx=m.indexOf(needle);const spots=[];
  while(idx>=0&&spots.length<3){spots.push(idx.toString(16));idx=m.indexOf(needle,idx+1);cnt++;}
  console.log(name,"r="+JSON.stringify(r),"postEvalConst found:"+cnt, spots.join(","));
 }
 process.exit(0);
})();
