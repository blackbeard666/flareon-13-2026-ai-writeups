require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,caps=[],pend=null;
 function reb(){U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);}
 function q(o){o=Number(o);return DV.getBigUint64(o,true);}
 function str(ptr,len){ptr=Number(ptr);len=Number(len);if(ptr<=0x1000||len<=0||len>200||ptr+len>U8.length)return null;return Buffer.from(U8.slice(ptr,ptr+len)).toString('latin1');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; reb();
   if(pend!==null){ // after 3272 returns, result string ptr/len at sp+? try +8/+16
     for(const o of [8,16,24,32,40,48]){const p=q(pend+o),l=q(pend+o+8);const s=str(p,l);if(s&&/^[0-9]+$/.test(s.slice(0,10)))caps.push('3272 out@+'+o+': '+s.slice(0,90));}
     pend=null; }
   if(idx===3272){pend=Number(sp);caps.push('3272 called');}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r));caps.forEach(c=>console.log(c));
 process.exit(0);
})();
