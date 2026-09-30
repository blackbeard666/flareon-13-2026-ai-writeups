require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,log=[],pend=null;
 function reb(){U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);}
 function q(o){o=Number(o);return DV.getBigUint64(o,true);}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U8.length)return'-';const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>512||ptr+len>U8.length)return(neg?'-':'')+'0';let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return(neg?'-':'')+v.toString();}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; reb();
   if(pend!==null){log[log.length-1]+=' => '+DV.getInt32(pend+24,true);pend=null;}
   if(idx===3254){log.push('Cmp('+rI(q(sp+8))+','+rI(q(sp+16))+')');pend=Number(sp);if(log.length>100000)log.shift();}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r)+" nCmp="+log.length);
 console.log("LAST 15:");log.slice(-15).forEach(l=>console.log(l));
 process.exit(0);
})();
