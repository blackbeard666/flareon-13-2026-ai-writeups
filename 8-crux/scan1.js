require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){const pl=48-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function nd(children,k,v){const kb=bLE(k),vb=bLE(v);const p=[Buffer.from([1]),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const args=process.argv.slice(2);
 const Vmax=args[0]?parseInt(args[0]):64;
 const Xmax=args[1]?parseInt(args[1]):8;
 let found=[];
 for(let V=0;V<=Vmax;V++){
  for(let X=0;X<=Xmax;X++){
   const msg=nd([nd([],2,X)],2,V);
   if(msg.length<32||msg.length>47)continue;
   let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}
   if(r!=='Bad input'){found.push(`V=${V} X=${X} -> ${JSON.stringify(r)}`);}
  }
 }
 console.log('non-BadInput results:',found.length);
 for(const f of found)console.log(f);
 process.exit(0);
})();