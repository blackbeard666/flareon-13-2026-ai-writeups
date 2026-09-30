require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,aesN=0,after=0,done=false;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   sp=Number(sp);
   if(idx===3190){aesN++; if(aesN===2){ after=1;
     console.log("AES#2 entry: out(sp+8)="+hx(q(sp+8),48));
     console.log("           ct(sp+40)="+hx(q(sp+40),48));
   } return; }
   if(after===1 && aesN===2 && !done){
     // first func entry after AES#2
     done=true;
     console.log("first func after AES#2: idx="+idx+" sp=0x"+sp.toString(16));
     // dump globals
     const g1=q(0x20abb0);
     console.log("*(0x20abb0)=0x"+g1.toString(16));
     if(g1>0x1000){ console.log("  [g1+40](u32)=0x"+D.getUint32((g1+40)>>>0,true).toString(16));
       console.log("  [g1+60](u8)=0x"+U[(g1+60)>>>0].toString(16));
       console.log("  [g1+112](u64)=0x"+q(g1+112).toString(16));
       console.log("  g1 struct[0..128]="+hx(g1,128)); }
     const g2addr=0x20ab98;
     console.log("*(0x20ab98)(u16)=0x"+D.getUint16(g2addr,true).toString(16));
     console.log("  mem[0x20ab98..+16]="+hx(g2addr,16));
     // stack frame values referenced by transform
     console.log("sp+56(u64)=0x"+q(sp+56).toString(16));
     console.log("sp+150(u8)=0x"+U[(sp+150)>>>0].toString(16));
     console.log("sp+498(u16)=0x"+D.getUint16((sp+498)>>>0,true).toString(16));
     console.log("sp+510(u16)=0x"+D.getUint16((sp+510)>>>0,true).toString(16));
     console.log("sp+512(u32)=0x"+D.getUint32((sp+512)>>>0,true).toString(16));
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 on=true; const r=check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("result:",JSON.stringify(r));
 process.exit(0);
})();
