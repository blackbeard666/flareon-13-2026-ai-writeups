require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,cap=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 function asc(p,n){p=p>>>0;let s='';for(let i=0;i<n;i++){const b=U[p+i];s+=(b>=32&&b<127)?String.fromCharCode(b):'.';}return s;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; idx=Number(idx);sp=Number(sp);
   if(idx===900004 && !cap){ if(U.buffer!==inst.exports.mem.buffer)reb();
     cap={dec240:hx(sp+240,32),dec240a:asc(sp+240,32),ctrl672:hx(sp+672,40),ctrl672a:asc(sp+672,40)}; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_dec.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r));
 if(cap){console.log("decoded sp+240 hex:",cap.dec240);console.log("decoded sp+240 asc:",cap.dec240a);
   console.log("control sp+672 hex:",cap.ctrl672);console.log("control sp+672 asc:",cap.ctrl672a);}
 process.exit(0);
})();
