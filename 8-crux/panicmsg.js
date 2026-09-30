require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bigLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function leaf(k,v){k=k||0;v=v||0;const kb=bigLE(k),vb=bigLE(v); return Buffer.concat([Buffer.from([1]),u32(0),u32(kb.length),kb,u32(vb.length),vb]);}
function node(children,k,v){k=k||0;v=v||0;const kb=bigLE(k),vb=bigLE(v);const parts=[Buffer.from([1]),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}parts.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(parts);}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const m=process.argv[2];
 let msg;
 if(m==='leaf2'){msg=node([leaf(2,1)]);}
 else if(m==='op2args'){msg=node([leaf(2,1),leaf(0,5),leaf(0,7)]);}  // (op2 5 7)?
 else {msg=node([leaf(parseInt(m||'2'),1)]);}
 console.log("msg:",msg.toString('hex'),"len",msg.length);
 try{ const r=check(mk(msg)); console.log("result:",JSON.stringify(r)); }
 catch(e){ console.log("JS-ERR:",e.message); }
 process.exit(0);
})();
