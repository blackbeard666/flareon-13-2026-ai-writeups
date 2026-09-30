require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
(async()=>{
 const go=new Go();let on=false;let seq=[];
 go.importObject.env={trace:(idx)=>{ if(on && idx>=3040) { if(seq.length===0||seq[seq.length-1][0]!==idx) seq.push([idx,1]); else seq[seq.length-1][1]++; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 function T(name,M){ on=true;seq=[];const r=check(mkMsg(M));on=false;
   console.log("--- "+name+" => "+JSON.stringify(r));
   console.log("  "+seq.map(([i,c])=>c>1?i+"x"+c:i).join(' ')); }
 T('leaf[0]', Buffer.from([0]));
 T('list1[[0]]', Buffer.concat([Buffer.from([1]),i32(1),i32(1),Buffer.from([0])]));
 T('list2[[0],[0]]', Buffer.concat([Buffer.from([1]),i32(2),i32(1),Buffer.from([0]),i32(1),Buffer.from([0])]));
 T('badAAAA', Buffer.from('AAAA'));
 process.exit(0);
})();
