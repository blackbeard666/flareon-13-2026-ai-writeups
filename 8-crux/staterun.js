require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,seq=[];
 const go=new Go();
 go.importObject.env={trace:(idx,val)=>{ if(!on)return; if(idx>=900000&&idx<910000){ seq.push([idx-900000,(Number(val)>>>0)]); } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_state2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r),"states:",seq.length);
 console.log("last 45 (state, local2hex):");
 for(const [s,v] of seq.slice(-45)) console.log("  state",s,"local2=0x"+v.toString(16));
 process.exit(0);
})();
