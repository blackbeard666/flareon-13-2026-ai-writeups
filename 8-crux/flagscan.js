require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,hits=new Set();
 function scan(){ const U=new Uint8Array(inst.exports.mem.buffer);
   const pats=['flare','@flare','on.com','_'.charCodeAt(0)];
   const s=Buffer.from(U).toString('latin1');
   for(const p of ['flare','on.com','@flare']){ let i=s.indexOf(p); while(i>=0){ hits.add(i+':'+Buffer.from(U.slice(i-4,i+40)).toString('latin1').replace(/[^\x20-\x7e]/g,'.')); i=s.indexOf(p,i+1);} }
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; if(idx===3190||idx===3272||idx===3166||idx===3184) scan(); }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 on=true; const r=check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 scan();
 console.log("result:",JSON.stringify(r));
 console.log("flag-ish hits:",hits.size);
 for(const h of hits) console.log("  "+h);
 process.exit(0);
})();
