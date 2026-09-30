require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,cap=[];
 function reb(){U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);}
 function q(o){return Number(DV.getBigUint64(o,true));}
 let after2=false,pending=false;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; reb();
   if(pending){ // capture output of AES#2 now
     cap.push(Buffer.from(U8.slice(0x6e4000,0x6e4040)));
     cap.push(Buffer.from(U8.slice(0x36c000,0x36c040)));
     pending=false; }
   if(idx===3190){ after2=!after2?true:'both'; if(after2==='both')pending=true; }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;reb();
 console.log("result="+JSON.stringify(r));
 // dump final buffers regardless
 console.log("0x6e4000:",Buffer.from(U8.slice(0x6e4000,0x6e4040)).toString('latin1').replace(/[^\x20-\x7e]/g,'.'));
 console.log("0x36c000:",Buffer.from(U8.slice(0x36c000,0x36c040)).toString('latin1').replace(/[^\x20-\x7e]/g,'.'));
 console.log("hex 6e4000:",Buffer.from(U8.slice(0x6e4000,0x6e4040)).toString('hex'));
 cap.forEach((b,i)=>console.log("cap"+i,b.toString('latin1').replace(/[^\x20-\x7e]/g,'.'),"|",b.toString('hex')));
 process.exit(0);
})();
