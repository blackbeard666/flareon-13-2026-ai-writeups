require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,cap=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'oob';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>512||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return (neg?'-':'')+v.toString();}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return;idx=Number(idx);sp=Number(sp);
   if(idx===900007&&!cap){if(U.buffer!==inst.exports.mem.buffer)reb();
     cap={pair:hx(sp+672,40), carItab:q(sp+672).toString(16), carData:q(sp+680).toString(16),
          carVal:rI(q(sp+680)), cdrItab:q(sp+688).toString(16)};}}};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_evalres2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true;const r=globalThis.check(fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim());on=false;
 console.log("result:",JSON.stringify(r));
 if(cap){console.log("eval result pair(sp+672):",cap.pair);
   console.log("car itab:0x"+cap.carItab,"car data:0x"+cap.carData,"car VALUE:",cap.carVal,"cdr itab:0x"+cap.cdrItab);}
 process.exit(0);
})();
