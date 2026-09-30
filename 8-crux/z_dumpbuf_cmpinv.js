require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,aesN=0,U=null,D=null,snaps=[];
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 function asc(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'';let s='';for(let i=0;i<n;i++){const b=U[p+i];s+=(b>=32&&b<127)?String.fromCharCode(b):'.';}return s;}
 const go=new Go();
 go.importObject.env={trace:(idx,ptr)=>{ if(!on)return; idx=Number(idx);ptr=Number(ptr);
   if(idx===3190)aesN++;
   if(idx>=900000){ const st=idx-900000; if(aesN>=2){ if(U.buffer!==inst.exports.mem.buffer)reb();
      snaps.push({st, ptr:ptr.toString(16), hex:hx(ptr,64), asc:asc(ptr,64)}); } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_state2_cmpinv.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; let r; try{r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r));
 for(const s of snaps){ console.log("state",s.st,"local2=0x"+s.ptr); console.log("   hex:",s.hex); console.log("   asc:",s.asc); }
 process.exit(0);
})();
