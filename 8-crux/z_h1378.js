require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,cap=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'oob';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return;idx=Number(idx);sp=Number(sp);
   if(idx===900005&&!cap){if(U.buffer!==inst.exports.mem.buffer)reb();
     cap={sp56:q(sp+56).toString(16),win:hx(sp+40,48)};}}};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_h1378.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true;const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim());on=false;
 console.log("result:",JSON.stringify(r));
 if(cap)console.log("at 3272 call: sp+56=0x"+cap.sp56,"win sp+40..88:",cap.win);
 process.exit(0);
})();
