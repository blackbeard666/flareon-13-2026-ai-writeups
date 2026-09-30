require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,vals=[];
 const go=new Go();
 go.importObject.env={trace:(idx,val)=>{ if(!on)return; if(idx===900002){ vals.push((Number(val)>>>0).toString(16)); } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_off56.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {r,vals};
}
(async()=>{ for(const f of ['certP.b64','cand_180.b64','certP_lv1.b64']){ const x=await run(f); console.log(f,JSON.stringify(x.r),"off56 logged:",x.vals); } process.exit(0); })();
