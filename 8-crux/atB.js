require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){const pl=48-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function nd(children,k,v){const kb=bLE(k),vb=bLE(v);const p=[Buffer.from([1]),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
global.nd=nd;
(async()=>{
 let inst=null,DV=null,U8=null,on=false,log=[],pend=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U8.length)return'-';const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>256||ptr+len>U8.length)return(neg?'-':'')+'0';let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return(neg?'-':'')+v.toString();}
 function flush(sp){ while(pend.length && Number(sp)>=pend[pend.length-1].sp){ const p=pend.pop();
   // read result slots at p.sp+8..+40
   p.done('res[+8='+rI(q(p.sp+8))+',+16='+rI(q(p.sp+16))+',+24='+rI(q(p.sp+24))+',+32='+rI(q(p.sp+32))+']'); } }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; flush(sp);
   if(idx===3254){const e={t:'Cmp('+rI(q(sp+8))+','+rI(q(sp+16))+')'};log.push(e);pend.push({sp:Number(sp),done:(r)=>{e.t+='='+rI0(Number(sp)+24)}});}
   else if(idx===3262){const e={t:'DivMod(x='+rI(q(sp+16))+',y='+rI(q(sp+24))+')'};log.push(e);pend.push({sp:Number(sp),done:(r)=>{e.t+=' -> '+r}});}
   else if(idx===3268){log.push({t:'PRED(N='+rI(q(sp+8))+',a1='+rI(q(sp+16))+',n='+Number(BigInt.asIntN(64,q(sp+32)))+')'});}
   else if(idx===3251){log.push({t:'NewInt('+BigInt.asIntN(64,q(sp+8))+')'});}
 }};
 function rI0(o){return rI(q(o));}
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=eval(process.argv[2]);
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r));
 log.forEach(l=>console.log(l.t));
 process.exit(0);
})();
