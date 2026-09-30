require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null,aesN=0,cap={};
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3184){ const p=q(Number(sp)+8); if(p>0x1000) cap['key'+(cap.kn=(cap.kn||0)+1)]=hx(p,32); }
   if(idx===3190){ aesN++; if(aesN===2){ cap.ct=hx(q(Number(sp)+40),48); cap.pt=hx(q(Number(sp)+8),48);} }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 on=true; const r=check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {r,cap};
}
(async()=>{
 for(const f of ['certP.b64','certP_v0.b64']){
   const {r,cap}=await run(f);
   console.log(f,"->",JSON.stringify(r));
   console.log("  key2:",cap.key2, "\n  ct:",cap.ct,"\n  pt:",cap.pt);
 }
 process.exit(0);
})();
