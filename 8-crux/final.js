require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,gate=false,dumps=[];
 const P=95681613235744740119807961018865688051340183696570761153419351987106658443873n;
 function reb(){U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);}
 function q(o){o=Number(o);return DV.getBigUint64(o,true);}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U8.length)return null;const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>512||ptr+len>U8.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return neg?-v:v;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; reb();
   if(idx===3254){const a=rI(q(sp+8)),b=rI(q(sp+16));if(a===P&&b===P)gate=true;}
   if(gate){
     if(idx===3272){dumps.push('3272 args: +8='+rI(q(sp+8))+' +16='+q(sp+16));}
     if(idx===3190){const outp=Number(q(sp+8)),inp=Number(q(sp+40));dumps.push('AES out=0x'+outp.toString(16)+' in=0x'+inp.toString(16));}
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;reb();
 console.log("result="+JSON.stringify(r));dumps.forEach(d=>console.log(d));
 // final scan for flag-like strings
 const hay=Buffer.from(U8);const s=hay.toString('latin1');const re=/[\x20-\x7e]{10,}/g;let m,hits=[];
 while((m=re.exec(s))){const t=m[0];if(/flare|@|_20|\.com/.test(t)&&!/runtime|reflect|\.go|golang|GOROOT|gcController|mheap|sync\.|http|crypto\/|\/cpu|span|malloc|sched/.test(t))hits.push(t.slice(0,90));}
 console.log("FLAG CANDIDATES:");[...new Set(hits)].slice(0,15).forEach(h=>console.log('  '+h));
 process.exit(0);
})();
