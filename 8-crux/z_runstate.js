require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,states=[],aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return;
   idx=Number(idx);
   if(idx===3190)aesN++;
   if(idx>=900000){ states.push([idx-900000,aesN]); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_state.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const inp=fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim();
 on=true; let r; try{r=check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r),"total states:",states.length,"aesN:",aesN);
 // print states with aesN>=2 (post AES#2) - the last ~60
 const post=states.filter(s=>s[1]>=2);
 console.log("post-AES#2 state count:",post.length);
 console.log("LAST 60 states (state,aesN):", post.slice(-60).map(s=>s[0]).join(' '));
 console.log("FIRST 40 post-AES#2 states:", post.slice(0,40).map(s=>s[0]).join(' '));
 process.exit(0);
})();
