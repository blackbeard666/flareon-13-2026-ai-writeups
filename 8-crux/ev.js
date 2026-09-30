require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function nd(c,k,v){k=(k===undefined?2:k);v=(v===undefined?0:v);const kb=bLE(k),vb=bLE(v);const p=[Buffer.from([1]),u32(c.length)];for(const x of c){p.push(u32(x.length));p.push(x);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
global.nd=nd;
(async()=>{
 let inst=null,DV=null,U8=null,on=false,log=[],pend=[],depth=0;
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function b(o){o=Number(o);if(o<0||o>=U8.length)return -1;return U8[o];}
 function flush(sp){ while(pend.length && Number(sp)>=pend[pend.length-1].sp){const p=pend.pop();depth--;log.push('  '.repeat(depth)+'eval@'+p.sp.toString(16)+' RET ok='+b(p.sp+24));}}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; flush(sp);
   if(idx===3269){log.push('  '.repeat(depth)+'eval@'+Number(sp).toString(16)+' CALL');pend.push({sp:Number(sp)});depth++;}
   else if(idx===3268){log.push('  '.repeat(depth)+'PRED');pend.push({sp:Number(sp),pred:1});}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=eval(process.argv[2]);
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r));log.forEach(l=>console.log(l));
 process.exit(0);
})();
