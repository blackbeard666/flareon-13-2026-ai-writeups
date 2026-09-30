require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const U8=new Uint8Array(instance.exports.mem.buffer),DV=new DataView(instance.exports.mem.buffer);
 function q(o){return Number(DV.getBigUint64(o,true));}
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}
 console.log("result="+JSON.stringify(r));
 const U8b=new Uint8Array(instance.exports.mem.buffer),DVb=new DataView(instance.exports.mem.buffer);
 function q2(o){return Number(DVb.getBigUint64(o,true));}
 console.log("0x20aba0=0x"+q2(0x20aba0).toString(16));
 console.log("0x20aba8=0x"+q2(0x20aba8).toString(16));
 const p=q2(0x20abb0); console.log("0x20abb0 ptr=0x"+p.toString(16));
 if(p>0x1000){const v=q2(p+112);console.log("[ptr+112]=0x"+v.toString(16));
   if(v>0x1000){let bytes=[];for(let i=0;i<48;i++)bytes.push(U8b[v+i]);console.log("value bytes:",bytes.map(x=>x.toString(16).padStart(2,'0')).join(' '));console.log("byte39=0x"+U8b[v+39].toString(16));}}
 process.exit(0);
})();
