require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("a729030050ad50044041f006","hex");
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');const idx=base.indexOf(pat);const buf=Buffer.from(base);
 if(idx>=0){buf[idx+4]=0x1a;buf[idx+5]=0x41;buf[idx+6]=0x00;}
 let inst=null,DV=null,U8=null;let on=false;let snap=null;
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 const go=new Go();
 go.importObject.env={trace:(id,sp)=>{if(!on||!inst)return;
   if(id===3268 && !snap){ // snapshot args + arg2 memory
     const a0=Number(q(sp+8)),a1=Number(q(sp+16)),a2=Number(q(sp+24)),a3=Number(q(sp+32));
     snap={a0,a1,a2,a3,words:[]};
     for(let i=0;i<8;i++)snap.words.push('['+(a2+i*8).toString(16)+']='+q(a2+i*8).toString(16));
   }
 }};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2],"hex");
 on=true;try{check(mk(msg));}catch(e){}on=false;
 if(snap){console.log("arg2(list base)=0x"+snap.a2.toString(16),"arg3(count)="+snap.a3);
   console.log("arg2 memory (stride16=iface itab/data):");snap.words.forEach(w=>console.log("  "+w));
   // interpret entries
   for(let i=0;i<snap.a3+2;i++){const itab=Number(q(snap.a2+i*16));const data=Number(q(snap.a2+i*16+8));
     console.log("  entry["+i+"] itab=0x"+itab.toString(16)+" data=0x"+data.toString(16));}
 } else console.log("no 3268 hit");
 process.exit(0);
})();
