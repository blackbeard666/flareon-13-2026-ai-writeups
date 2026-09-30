require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,log=[],pend=[],evs=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function bb(o){o=Number(o);if(o<0||o>=U8.length)return -1;return U8[o];}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U8.length)return'?';const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>256||ptr+len>U8.length)return(neg?'-':'')+'0';let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return(neg?'-':'')+v.toString();}
 function flush(sp){while(pend.length&&Number(sp)>=pend[pend.length-1].sp){const p=pend.pop();
   if(p.kind==='eval'){evs.pop();}
   else{const es=evs[evs.length-1];const ok=es!==undefined?bb(es-168):-1;log.push('PRED K='+p.K+' N='+p.N+' ok='+ok);}}}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; flush(sp);
   if(idx===3269){pend.push({sp:Number(sp),kind:'eval'});evs.push(Number(sp));}
   else if(idx===3268){pend.push({sp:Number(sp),kind:'pred',N:rI(q(sp+8)),K:rI(q(sp+16))});}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r));
 // show PREDs with ok=0
 const bad=log.filter(l=>/ok=0$/.test(l));
 console.log("total PRED:",log.length,"failed:",bad.length);
 bad.slice(0,10).forEach(l=>console.log("FAIL:",l));
 log.slice(0,6).forEach(l=>console.log(l));
 process.exit(0);
})();
