require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null,aesN=0,key2=null,kn=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3184){kn++; if(kn===2) key2=hx(q(Number(sp)+8),32);}
   if(idx===3190){aesN++;}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; let r; try{r=globalThis.check(fs.readFileSync(file,'utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 return {r,aesN,key2};
}
(async()=>{
 for(const f of process.argv.slice(2)){
   if(!fs.existsSync(f)){console.log(f,"(missing)");continue;}
   const {r,aesN,key2}=await run(f);
   console.log(f,"=> result:",JSON.stringify(r),"| AEScount:",aesN,"| reachedAES2:",aesN>=2,"| key2:",key2);
 }
 process.exit(0);
})();
