require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);}
 const go=new Go();
 go.importObject.env={trace:()=>{}};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2_flag.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));reb();
 let r; try{r=globalThis.check(fs.readFileSync('certP.b64','utf8').trim());}catch(e){r='ERR:'+e.message;}
 reb();
 console.log("result:",JSON.stringify(r));
 // scan for ascii strings containing flag markers
 let start=-1,hits=[];
 for(let i=0x1000;i<U.length;i++){const b=U[i];
   if(b>=0x20&&b<0x7f){if(start<0)start=i;}
   else{if(start>=0&&i-start>=6){const s=Buffer.from(U.subarray(start,i)).toString('latin1');
     if(/flare|on\.com|@flare|_|crux|FLARE/.test(s)&&s.length<80)hits.push([start.toString(16),s]);}start=-1;}}
 console.log("candidate strings:",JSON.stringify(hits.slice(0,50)));
 process.exit(0);
})();
