require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let on=false,off56=[],aesN=0;
 const go=new Go();
 go.importObject.env={trace:(idx,v)=>{ if(!on)return; idx=Number(idx);
   if(idx===3190)aesN++;
   if(idx===900002){ off56.push(Number(v)>>>0); } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_off56.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const inp=fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim();
 on=true; let r; try{r=globalThis.check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 console.log("input:",process.argv[2]||'certP.b64',"result:",JSON.stringify(r),"aesN:",aesN);
 console.log("off56 values:", off56.map(x=>'0x'+x.toString(16)));
 process.exit(0);
})();
