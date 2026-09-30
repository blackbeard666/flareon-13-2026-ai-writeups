require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,D=null,U=null,reached=false,aes=0,key=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   sp=Number(sp)>>>0; const ret=q(sp)>>>0; const f=sp+8;
   if(idx===3190) aes++;
   if(idx===3190 && ret===0x1cb20577){ reached=true; }
   if(idx===3184 && ret===0x1cb2056a){ const p=q(f+0)>>>0,l=q(f+8); if(p>0x1000&&p+l<=U.length) key=Buffer.from(U.slice(p,p+l)).toString('hex'); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; let r; try{ r=globalThis.check(fs.readFileSync(file,'utf8').trim()); }catch(e){ r='EXC:'+e.message; } on=false;
 return {file,r:JSON.stringify(r),reachedAES2:reached,aesCount:aes,key};
}
(async()=>{
 const files=process.argv.slice(2);
 for(const f of files){ try{ console.log(JSON.stringify(await run(f))); }catch(e){ console.log(f,'ERR',e.message); } }
 process.exit(0);
})();
