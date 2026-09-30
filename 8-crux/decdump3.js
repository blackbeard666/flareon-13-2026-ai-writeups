require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,aesN=0,snaps=[];
 function mem(){return new Uint8Array(inst.exports.mem.buffer);}
 function dv(){return new DataView(inst.exports.mem.buffer);}
 function q(D,o){o=Number(o);if(o<0||o+8>D.byteLength)return 0n;return D.getBigUint64(o,true);}
 function hx(U,o,n){o=Number(o);if(o<=0||o+n>U.length)return'<oob>';return Buffer.from(U.slice(o,o+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3190){ aesN++; const U=mem(),D=dv(); const s=[];
     for(let i=0;i<14;i++){ const v=Number(q(D,Number(sp)+i*8)); let e=''; if(v>0x1000&&v<U.length) e=hx(U,v,48); s.push({off:i*8,v:v.toString(16),m:e}); }
     snaps.push({n:aesN,sp:Number(sp).toString(16),words:s});
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const inp=fs.readFileSync('certP.b64','utf8').trim();
 on=true; let r; try{r=check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r));
 for(const snap of snaps){ console.log("=== AES#"+snap.n+" sp=0x"+snap.sp+" ===");
   for(const w of snap.words) if(w.m) console.log("  sp+"+w.off+"=0x"+w.v+" -> "+w.m);
 }
 process.exit(0);
})();
