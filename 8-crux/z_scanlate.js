require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
(async()=>{
 let inst=null,on=false,U=null,D=null,aesN=0,c2992=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function scanASCII(minlen){ const res=[]; let start=-1;
   for(let i=0x1000;i<U.length;i++){ const b=U[i];
     if(b>=0x20&&b<0x7f){ if(start<0)start=i; }
     else { if(start>=0 && i-start>=minlen){ const s=Buffer.from(U.subarray(start,i)).toString('latin1');
              if(/flare|on\.com|@|FLARE|crux/.test(s)) res.push([start.toString(16),s]); }
            start=-1; } }
   return res; }
 function findBytes(hex){ const pat=Buffer.from(hex,'hex'); const hits=[]; let idx=0;
   while(true){ idx=Buffer.from(U).indexOf(pat,idx); if(idx<0)break; hits.push(idx.toString(16)); idx++; if(hits.length>10)break; } return hits; }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3190){aesN++;}
   if(idx===2992 && aesN===2){ c2992++; if(c2992===1){
       // template buffer: find bytes 6c60694064
       console.log("template 6c60694064 at:", findBytes("6c60694064"));
       console.log("template 34 5c 0f at:", findBytes("345c0f"));
       const ascii=scanASCII(5);
       console.log("ASCII hits with flag markers:", JSON.stringify(ascii.slice(0,40)));
   } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false; reb();
 console.log("result:",JSON.stringify(r));
 // final full scan
 console.log("FINAL template 6c60694064 at:", findBytes("6c60694064"));
 const ascii=scanASCII(5);
 console.log("FINAL ASCII flag markers:", JSON.stringify(ascii.slice(0,40)));
 process.exit(0);
})();
