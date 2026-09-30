require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,found=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const NM={0x4ef80:'VALUE',0x4ef60:'PAIR',0x4ef40:'NIL',0:'nil'};
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||found)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3251){ sp=Number(sp); const base=sp+8+0x2a0;
     if(base+40>U.length)return;
     const cdrItab=q(base+16)>>>0;
     if(cdrItab===0x4ef40){ // found the accept's [car, nil, extra]
       found={
         carItab:'0x'+(q(base)>>>0).toString(16), carData:'0x'+q(base+8).toString(16),
         cdrItab:'0x'+cdrItab.toString(16), cdrData:'0x'+q(base+24).toString(16),
         extra:'0x'+q(base+32).toString(16),
         raw:Buffer.from(U.slice(base,base+40)).toString('hex')
       };
     }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("eval result (40B at frame+0x2a0):", JSON.stringify(found,null,1));
 // interpret car/extra as bigints if pointers
 if(found){
   function rInt(p){p=Number(p)>>>0;if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=q(p+8),len=q(p+16);if(ptr<=0x1000||len<0||len>2048||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return neg?-v:v;}
   const cv=rInt(parseInt(found.carData,16)); const ev=rInt(parseInt(found.extra,16));
   console.log("carData as *BigInt:", cv?cv.toString():'n/a');
   console.log("extra as *BigInt:", ev?ev.toString():'n/a');
 }
 process.exit(0);
})();
