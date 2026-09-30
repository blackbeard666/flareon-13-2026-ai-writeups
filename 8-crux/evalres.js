require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,cap=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function rInt(p){p=p>>>0;if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=q(p+8),len=q(p+16);if(ptr<=0x1000||len<0||len>2048||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return neg?-v:v;}
 const NM={0x4ef80:'VALUE',0x4ef60:'PAIR',0x4ef40:'NIL'};
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3251){ sp=Number(sp);
     const lo=D.getUint32(sp>>>0,true);
     if(lo===0x1cb2034a){
       const base=sp+8+0x2a0;
       const ci=q(base)>>>0, cd=q(base+8), di=q(base+16)>>>0, dd=q(base+24);
       let carv=null; if(ci===0x4ef80) carv=rInt(cd);
       cap={carItab:'0x'+ci.toString(16),carName:NM[ci]||'?',carVal:carv?carv.toString():null,cdrItab:'0x'+di.toString(16),cdrName:NM[di]||'?'};
     }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("eval result [car, cdr] =", JSON.stringify(cap));
 console.log("P =","95681613235744740119807961018865688051340183696570761153419351987106658443873");
 process.exit(0);
})();
