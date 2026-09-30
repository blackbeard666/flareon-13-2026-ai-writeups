require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let on=false,states=new Set();
 const go=new Go();
 go.importObject.env={trace:(a,b)=>{ if(!on)return; a=Number(a); if(a>=800000&&a<801000)states.add(a-800000); }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_allstates.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; let r; try{r=globalThis.check(fs.readFileSync(file,'utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 return {r,states:[...states].sort((x,y)=>x-y)};
}
(async()=>{
 for(const f of ['certP.b64','cert_1777only.b64','cert_drop2.b64']){
   if(!fs.existsSync(f)){console.log(f,'(missing)');continue;}
   const {r,states}=await run(f);
   console.log(f,'=> result:',JSON.stringify(r),'| states('+states.length+'):',states.join(','));
 }
 process.exit(0);
})();
