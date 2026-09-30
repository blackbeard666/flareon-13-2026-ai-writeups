require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function nd(c,k,v){k=(k===undefined?2:k);v=(v===undefined?0:v);const kb=bLE(k),vb=bLE(v);const p=[Buffer.from([1]),u32(c.length)];for(const x of c){p.push(u32(x.length));p.push(x);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
global.nd=nd; const L=(c,k,v)=>nd(c||[],k,v); global.L=L;
(async()=>{const go=new Go();const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);go.run(instance);await new Promise(r=>setImmediate(r));const check=globalThis.check;
 const m=eval(process.argv[2]);
 let r;try{r=check(mk(m));}catch(e){r='ERR:'+e.message;}
 console.log(process.argv[2],'len'+m.length,'=>',JSON.stringify(r));
 process.exit(0);})();
