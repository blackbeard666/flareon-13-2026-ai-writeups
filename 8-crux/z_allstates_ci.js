require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let on=false,states=[],aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; idx=Number(idx);
   if(idx===3190)aesN++;
   if(idx>=900000){ states.push(idx-900000+(aesN>=2?'*':aesN===1?"'":"")); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_cmpinv_state.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const inp=fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim();
 on=true; let r; try{r=globalThis.check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r));
 console.log("ALL states ("+states.length+"):", states.join(' '));
 process.exit(0);
})();
