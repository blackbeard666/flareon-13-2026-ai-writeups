require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const names={0x4ef80:'VALUE',0x4ef60:'PAIR',0x4ef40:'NIL'};
(async()=>{
 let inst=null,DV=null,U8=null;let on=false;let firstArg=null,n=0;
 function q(o){return DV.getBigUint64(Number(o),true);}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3269){ n++; if(n===1){
     // arg is interface at sp+8.. ; capture several words + deref for itab
     const w=[];for(let i=1;i<8;i++)w.push(q(sp+i*8));
     // the interface {itab, data}: itab at some word; scan words for a known itab
     let itab=null;
     for(let i=0;i<w.length;i++){const v=Number(w[i]);if(v===0x4ef80||v===0x4ef60||v===0x4ef40){itab=v;}
       // also deref pointers and read first word
       if(v>0x10000&&v<U8.length-8){const fw=Number(q(v));if(fw===0x4ef80||fw===0x4ef60||fw===0x4ef40)itab=fw;}
     }
     firstArg={words:w.map(x=>x.toString(16)),itab:itab?names[itab]:'?'};
   }}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2],"hex");
 on=true;firstArg=null;n=0;check(mk(msg));on=false;
 console.log(process.argv[3]||msg.toString('hex'),"n3269="+n,"arg0:",JSON.stringify(firstArg));
 process.exit(0);
})();
