require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,evs=[];
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb(); sp=Number(sp);
   if(idx===3184){ evs.push({t:'keyexp',key:hx(q(sp+8),32)}); }
   if(idx===3190){ evs.push({t:'aes',out:q(sp+8),ct:q(sp+40),sp8len:q(sp+16),sp:sp}); }
   if(idx===3217){ evs.push({t:'sha',sp:sp}); }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 reb();
 console.log("result:",JSON.stringify(r));
 console.log("total events:",evs.length);
 let i=0;
 for(const e of evs){
   if(e.t==='aes') console.log("["+i+"] AES out=0x"+e.out.toString(16)+" -> "+hx(e.out,48)+"  ct=0x"+e.ct.toString(16)+" -> "+hx(e.ct,48));
   else if(e.t==='keyexp') console.log("["+i+"] KEYEXP key="+e.key);
   else console.log("["+i+"] SHA");
   i++;
 }
 process.exit(0);
})();
