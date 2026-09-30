require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,states=new Set();
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; idx=Number(idx); if(idx>=900000&&idx<901000) states.add(idx-900000); }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_state2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; let r; try{r=globalThis.check(fs.readFileSync(file,'utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 return {r,states};
}
(async()=>{
 const a=await run('certP.b64');
 const b=await run('cert_valid4.b64');
 const taken=new Set([...a.states,...b.states]);
 console.log("certP states:",a.states.size,"| cert_valid4 states:",b.states.size,"| union:",taken.size);
 const never=[]; for(let s=0;s<=675;s++) if(!taken.has(s)) never.push(s);
 console.log("NEVER-taken states (of 0..675):",never.length);
 console.log(never.join(','));
 process.exit(0);
})();
