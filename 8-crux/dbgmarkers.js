require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,marks={};
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3251){ const lo=D.getUint32(Number(sp)>>>0,true); marks[lo]=(marks[lo]||0)+1; }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 const entries=Object.entries(marks).map(([k,v])=>[parseInt(k),v]).sort((a,b)=>a[1]-b[1]);
 console.log("total distinct 3251 resume markers:",entries.length);
 console.log("markers near 0x1cb203xx (accept region):");
 for(const [k,v] of entries){ if(k>=0x1cb20300 && k<=0x1cb20400) console.log("  0x"+k.toString(16),"count",v); }
 console.log("rarest markers (count<=3):");
 for(const [k,v] of entries){ if(v<=3) console.log("  0x"+k.toString(16),"count",v); }
 process.exit(0);
})();
