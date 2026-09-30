require('./wasm_exec.js');
const fs=require('fs');
async function cov(file){
 let inst=null,on=false,seen=new Set();
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(on) seen.add(Number(idx)); }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; let r; try{r=globalThis.check(fs.readFileSync(file,'utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 return {r,seen};
}
(async()=>{
 const a=await cov('certP.b64');           // reaches AES#2, "Bad input"
 const b=await cov('cert_valid4.b64');     // reaches valid-padding return path
 console.log("certP result:",JSON.stringify(a.r),"funcs executed:",a.seen.size);
 console.log("cert_valid4 result:",JSON.stringify(b.r),"funcs executed:",b.seen.size);
 const union=new Set([...a.seen,...b.seen]);
 console.log("union funcs executed:",union.size);
 // funcs executed by valid4 but NOT by certP (flag-path-only)
 const only=[...b.seen].filter(x=>!a.seen.has(x)).sort((x,y)=>x-y);
 console.log("funcs ONLY in valid-padding path (not in Bad-input path):",only.join(','));
 // save union for gap analysis
 fs.writeFileSync('cov_union.json',JSON.stringify([...union].sort((x,y)=>x-y)));
 process.exit(0);
})();
