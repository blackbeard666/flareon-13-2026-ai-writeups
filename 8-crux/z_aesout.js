require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
(async()=>{
 let inst=null,on=false,U=null,D=null,aesN=0,outPtr=0,ctPtr=0,keyPtr=0,ivPtr=0,captured=false,kn=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb(); sp=Number(sp);
   if(idx===3184){ kn++; if(kn===2){ keyPtr=q(sp+8); } }
   if(idx===3190){ aesN++; if(aesN===2){ outPtr=q(sp+8); ctPtr=q(sp+40);
       // dump the 4 args at entry
       console.log("AES#2 args: sp+0="+q(sp+0).toString(16)+" sp+8="+outPtr.toString(16)+" sp+16="+q(sp+16).toString(16)+" sp+24="+q(sp+24).toString(16)+" sp+32="+q(sp+32).toString(16)+" sp+40="+ctPtr.toString(16)+" sp+48="+q(sp+48).toString(16));
       console.log("  out@entry="+hx(outPtr,48));
       console.log("  ct @entry="+hx(ctPtr,48));
     } return; }
   if(aesN===2 && !captured){ captured=true;
     console.log("--- after AES#2 (next func idx="+idx+") ---");
     console.log("  out(0x"+outPtr.toString(16)+")="+hx(outPtr,48));
     console.log("  ct (0x"+ctPtr.toString(16)+")="+hx(ctPtr,48));
     if(keyPtr) console.log("  key2(0x"+keyPtr.toString(16)+")="+hx(keyPtr,32));
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r));
 // offline check: AES-256-CBC decrypt ct with key2, iv=0? and cross-check
 process.exit(0);
})();
