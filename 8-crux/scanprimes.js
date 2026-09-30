require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,reached=false;
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function rI(p){p=Number(p);if(p<=0x1000||p+24>U8.length)return null;const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0x1000||len<0||len>256||ptr+len>U8.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return neg?-v:v;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3254){const a=rI(q(sp+8)),b=rI(q(sp+16));if(a!==null&&b!==null&&(a>1000n||b>1000n))reached=true;}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 global.__check=globalThis.check; global.__mk=mk; global.__seton=(v)=>{on=v}; global.__reached=()=>reached; global.__rst=()=>{reached=false};
 // read certs from argv file
 const lines=fs.readFileSync(process.argv[2],'utf8').trim().split('\n');
 for(const line of lines){const [p,h]=line.split(' ');const msg=Buffer.from(h,'hex');on=true;reached=false;let r;try{r=__check(mk(msg));}catch(e){r='ERR'};on=false;
   console.log('p='+p+' size='+msg.length+' reachedEval='+(reached?1:0)+' result='+JSON.stringify(r));}
 process.exit(0);
})();
