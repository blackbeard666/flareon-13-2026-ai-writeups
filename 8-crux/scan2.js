require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){const pl=48-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function raw(kb,vb,children){const p=[Buffer.from([1]),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 let found=[];
 // top-level leaf: key=2, val = arbitrary bytes length L (last byte nonzero). vary key too.
 for(const K of [1,2,3]){
  const kb=Buffer.from([K]);
  for(let L=18;L<=33;L++){ // val length so total 14+L in 32..47
   const vb=Buffer.alloc(L, 0); vb[0]=1; vb[L-1]=1; // nonzero last byte
   const msg=raw(kb,vb,[]);
   if(msg.length<32||msg.length>47)continue;
   let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}
   if(r!=='Bad input')found.push(`K=${K} L=${L} -> ${JSON.stringify(r)}`);
  }
 }
 console.log('top-leaf non-BadInput:',found.length); found.forEach(f=>console.log(f));
 process.exit(0);
})();