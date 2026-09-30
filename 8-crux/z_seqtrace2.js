require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,aesN=0,seq=[],started=false;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return;
   if(idx===3190){aesN++; if(aesN===2){started=true; seq.push('---AES#2---');} }
   if(started){ seq.push(idx); if(seq.length>800) {on=false;} }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const inp=fs.readFileSync('certP.b64','utf8').trim();
 on=true; let r; try{r=check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r));
 console.log("len after AES#2:",seq.length);
 console.log(seq.slice(0,160).join(' '));
 process.exit(0);
})();
