require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,U=null;
 const go=new Go();
 go.importObject.env={trace:()=>{}};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const r=globalThis.check(fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim());
 console.log('result=',JSON.stringify(r));
 U=new Uint8Array(inst.exports.mem.buffer);
 const pats=['flare','@flare','on.com','FLARE'];
 for(const pat of pats){
   const pb=Buffer.from(pat);
   for(let i=0;i<U.length-pb.length;i++){
     let ok=true; for(let j=0;j<pb.length;j++) if(U[i+j]!==pb[j]){ok=false;break;}
     if(ok){ const s=Buffer.from(U.slice(i,i+80)).toString('latin1').replace(/[^ -~]/g,'.'); console.log('0x'+i.toString(16),pat,'->',s); }
   }
 }
 console.log('scan done');
 process.exit(0);
})();
