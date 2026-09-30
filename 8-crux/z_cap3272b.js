require('./wasm_exec.js');
const fs=require('fs');
const CT_PREFIX = Buffer.from('78b95d284fb5a232','hex');
async function run(file){
 let inst=null,on=false,U=null,D=null;
 let seen3272=false, scanned=false;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function hx(p,n){p=p>>>0;return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 function scanCT(){
   const buf=Buffer.from(U.buffer);
   let idx=buf.indexOf(CT_PREFIX,0);
   const hits=[];
   while(idx!==-1 && hits.length<8){ hits.push(idx); idx=buf.indexOf(CT_PREFIX,idx+1); }
   return hits;
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3272){ seen3272=true; if(scanCT().length){/*already present?*/} }
   else if(seen3272 && !scanned && idx===3184){
     scanned=true;
     const hits=scanCT();
     console.log('### '+file+' : after func3272, CT-prefix hits:', hits.map(h=>'0x'+h.toString(16)));
     for(const h of hits){ console.log('   @0x'+h.toString(16)+' = '+hx(h,64)); }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 // also scan BEFORE running check (is CT already static in image?)
 on=false;
 { const hits=scanCT(); console.log('### '+file+' : PRE-check CT-prefix hits:', hits.map(h=>'0x'+h.toString(16))); }
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 console.log(' result:',JSON.stringify(r));
}
(async()=>{ await run(process.argv[2]||'certP.b64'); process.exit(0); })();
