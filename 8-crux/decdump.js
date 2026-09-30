require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,DV=null,U8=null,on=false;
 let aesN=0, log=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function hx(o,n){o=Number(o);if(o<=0||o+n>U8.length)return'<oob>';return Buffer.from(U8.slice(o,o+n)).toString('hex');}
 function asc(o,n){o=Number(o);if(o<=0||o+n>U8.length)return'';return Array.from(U8.slice(o,o+n)).map(c=>c>=32&&c<127?String.fromCharCode(c):'.').join('');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3269) log.push('EVAL');
   else if(idx===3272) log.push('DEC(bigint->decimal)');
   else if(idx===3190){ aesN++;
     // dump candidate arg pointers and their 48-byte memory
     const dump=[];
     for(const off of [8,16,24,32,40,48,56]){ const p=Number(q(sp+off)); if(p>0x1000&&p<U8.length){ dump.push('sp+'+off+'->'+p.toString(16)+':'+hx(p,48)); } }
     log.push('=== AES#'+aesN+' @sp='+Number(sp).toString(16)+' ===\n  '+dump.join('\n  '));
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const inp=fs.readFileSync('certP.b64','utf8').trim();
 on=true; let r; try{r=check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 // rebind memory in case it grew
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 console.log("result:",JSON.stringify(r));
 console.log("AES calls:",aesN, "| EVAL/DEC markers present:", log.filter(l=>l==='EVAL').length, log.filter(l=>l.startsWith('DEC')).length);
 for(const l of log) if(!['EVAL'].includes(l)) console.log(l);
 process.exit(0);
})();
