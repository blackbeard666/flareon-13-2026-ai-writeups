require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,aesN=0,caps=[];
 function mem(){return new Uint8Array(inst.exports.mem.buffer);}
 function dv(){return new DataView(inst.exports.mem.buffer);}
 function q(D,o){o=Number(o);if(o<0||o+8>D.byteLength)return 0n;return D.getBigUint64(o,true);}
 function readIntAt(U,D,p){p=Number(p);if(p<=0||p+24>U.length)return null;const neg=U[p];const ptr=Number(q(D,p+8)),len=Number(q(D,p+16));if(ptr<=0||len<0||len>1024||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return (neg?-v:v);}
 function hx(U,o,n){o=Number(o);if(o<=0||o+n>U.length)return'<oob>';return Buffer.from(U.slice(o,o+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; const U=mem(),D=dv();
   if(idx===3272){ // decimal convert: arg bigint at sp+8 (try a few offsets)
     const cands=[];
     for(const off of [8,16,24]){ const iv=readIntAt(U,D,q(D,Number(sp)+off)); if(iv!==null) cands.push(off+':'+iv.toString()); }
     caps.push('DEC args: '+cands.join(' | '));
   }
   else if(idx===3190){ aesN++; if(aesN===2){ caps.push('AES#2 pt(out)@sp+8='+hx(U,q(D,Number(sp)+8),48)+'\n  ct(in)@sp+40='+hx(U,q(D,Number(sp)+40),48)); } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const inp=fs.readFileSync('certP.b64','utf8').trim();
 on=true; let r; try{r=check(inp);}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r));
 for(const c of caps) console.log(c);
 console.log("TARGET P =","95681613235744740119807961018865688051340183696570761153419351987106658443873");
 process.exit(0);
})();
