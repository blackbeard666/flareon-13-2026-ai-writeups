require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let on=false,states=new Set(),seq=[];
 const go=new Go();
 go.importObject.env={trace:(a,b)=>{ if(!on)return; a=Number(a); if(a>=800000&&a<801000){const s=a-800000; states.add(s); seq.push(s);} }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_allstates.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 on=true; let r; try{r=globalThis.check(fs.readFileSync(file,'utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 return {r,states,seq};
}
(async()=>{
 const a=await run('certP.b64');
 const b=await run('cert_valid4.b64');
 console.log("certP: result",JSON.stringify(a.r),"| distinct states:",a.states.size,"| transitions:",a.seq.length);
 console.log("  certP states:",[...a.states].sort((x,y)=>x-y).join(','));
 console.log("cert_valid4: result(len)",(''+a.r).length,"| distinct states:",b.states.size,"| transitions:",b.seq.length);
 console.log("  valid4 states:",[...b.states].sort((x,y)=>x-y).join(','));
 const taken=new Set([...a.states,...b.states]);
 const onlyValid=[...b.states].filter(x=>!a.states.has(x)).sort((x,y)=>x-y);
 const onlyBad=[...a.states].filter(x=>!b.states.has(x)).sort((x,y)=>x-y);
 console.log("states ONLY in valid-padding path:",onlyValid.join(','));
 console.log("states ONLY in Bad-input path:",onlyBad.join(','));
 fs.writeFileSync('states_taken.json',JSON.stringify([...taken].sort((x,y)=>x-y)));
 process.exit(0);
})();
