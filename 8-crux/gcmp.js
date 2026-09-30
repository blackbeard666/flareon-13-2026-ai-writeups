require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 function dump(tag){const DV=new DataView(instance.exports.mem.buffer);console.log(tag,"0x20aba0=0x"+DV.getBigUint64(0x20aba0,true).toString(16),"0x20aba8=0x"+DV.getBigUint64(0x20aba8,true).toString(16),"0x20abb0=0x"+DV.getBigUint64(0x20abb0,true).toString(16),"byte@0x20ab72=0x"+new Uint8Array(instance.exports.mem.buffer)[0x20ab72].toString(16));}
 dump("initial:");
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 let r;try{r=check(mk(msg));}catch(e){r='ERR'};
 dump("after cert(P): result="+JSON.stringify(r)+" |");
 process.exit(0);
})();
