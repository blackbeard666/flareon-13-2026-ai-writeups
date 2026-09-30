require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,aesN=0,cap=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; idx=Number(idx);sp=Number(sp);
   if(idx===3190)aesN++;
   if(idx===900003 && !cap){ if(U.buffer!==inst.exports.mem.buffer)reb();
     cap={sp:sp.toString(16), frame:hx(sp+40,64), off56:q(sp+56).toString(16),
          m48:hx(sp+40,8)}; } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_off56sp.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r),"aesN:",aesN);
 console.log("at off56 check: sp=0x"+cap.sp);
 console.log("  off56=0x"+cap.off56);
 console.log("  frame sp+40..104:",cap.frame);
 process.exit(0);
})();
