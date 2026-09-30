require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkFromMsg(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("a729030050ad50044041f006","hex");
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');
 const idx=base.indexOf(pat);
 console.log("gate pattern idx in instr2:",idx>=0?("0x"+idx.toString(16)):"NOT FOUND");
 const buf=Buffer.from(base);
 if(idx>=0){buf[idx+4]=0x1a;buf[idx+5]=0x41;buf[idx+6]=0x00;} // force fall-through to 3269
 let inst=null,DV=null,U8=null;let on=false;let caps=[];
 function q(o){return DV.getBigUint64(Number(o),true);}
 function hx(o,n){o=Number(o);if(o<=0||o+n>U8.length)return "OOB";return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx2,sp)=>{
   if(!on||!inst)return;
   if(idx2===3269){
     const rec={sp:sp.toString(16),words:[],derefs:[]};
     for(let i=0;i<12;i++){const v=q(sp+i*8);rec.words.push(v.toString(16));}
     for(let i=0;i<12;i++){const p=Number(q(sp+i*8));if(p>0x10000&&p<U8.length-48)rec.derefs.push([i,p.toString(16),hx(p,48)]);}
     caps.push(rec);
   }
 }};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 // feed a tag-0x01 tree message (32 bytes)
 const msg=Buffer.from("0101000000010000000200000003000000040000000500000000000000000000","hex");
 on=true;caps=[];const r=check(mkFromMsg(msg));on=false;
 console.log("result:",JSON.stringify(r),"num3269:",caps.length);
 for(const c of caps){console.log("sp="+c.sp,"words=",c.words.join(","));for(const d of c.derefs)console.log("  arg"+d[0]+"@"+d[1]+" ->",d[2]);}
 process.exit(0);
})();
