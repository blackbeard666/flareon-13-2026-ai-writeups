require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,DV=null,U8=null,on=false,aesN=0,cap2=null;
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function hx(o,n){o=Number(o);if(o<=0||o+n>U8.length)return'<oob>';return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3190){ aesN++; if(aesN===2){ const w=[];for(let i=0;i<16;i++){const v=Number(q(sp+i*8));w.push([i*8,v]);} cap2={sp:Number(sp),words:w}; } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const inp=fs.readFileSync('certP.b64','utf8').trim();
 on=true; let r; try{r=check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 console.log("result:",JSON.stringify(r));
 console.log("AES#2 sp=0x"+cap2.sp.toString(16));
 for(const [off,v] of cap2.words){
   let extra='';
   if(v>0x1000&&v<U8.length){ extra=' -> '+hx(v,48); }
   console.log("  sp+"+off+" = 0x"+v.toString(16)+extra);
 }
 process.exit(0);
})();
