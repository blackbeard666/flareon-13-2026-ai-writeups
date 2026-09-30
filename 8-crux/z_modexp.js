require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,DV=null,U8=null,on=false;
 const out=fs.createWriteStream('modexp_log.txt');
 function reb(){U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);}
 function q(o){o=Number(o); if(o<0||o+8>U8.length) return 0n; return DV.getBigUint64(o,true);}
 function readInt(p){p=Number(p);if(p<=0||p+24>U8.length)return'<bad>';const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0||len<0||len>256||ptr+len>U8.length)return(neg?'-':'')+'0';let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return(neg?'-':'')+v.toString();}
 let nModexp=0;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(U8.buffer!==inst.exports.mem.buffer)reb();
   sp=Number(sp);
   if(idx===3262){ nModexp++;
     out.write(`MODEXP base=${readInt(q(sp+8))} exp=${readInt(q(sp+16))} mod=${readInt(q(sp+24))}\n`);
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; let r; try{r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim());}catch(e){r='ERR:'+e.message;} on=false;
 out.end(()=>{ console.log("result:",JSON.stringify(r),"| modexp calls:",nModexp); process.exit(0); });
})();
