require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("a729030050ad50044041f006","hex");
const TARGET=new Set([3251,3254,3256,3257,3258,3261,3262,3268]);
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');const idx=base.indexOf(pat);const buf=Buffer.from(base);
 if(idx>=0){buf[idx+4]=0x1a;buf[idx+5]=0x41;buf[idx+6]=0x00;}
 let inst=null,DV=null,U8=null;let on=false;let evs=[];let pend=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function intAt(p){p=Number(p);if(p<=0x10000||p+24>U8.length)return null;
   const neg=U8[p]; const dp=Number(q(p+8)),ln=Number(q(p+16));
   if(dp<=0x10000||ln<0||ln>128||dp+ln>U8.length)return null;
   const bytes=Buffer.from(U8.slice(dp,dp+ln));
   // interpret as little-endian integer
   let v=0n;for(let i=ln-1;i>=0;i--)v=(v<<8n)|BigInt(bytes[i]);
   return {neg,ln,hex:bytes.toString('hex'),leval:(neg?'-':'')+v.toString()};
 }
 function word(sp,i){return q(sp+i*8);}
 const go=new Go();
 go.importObject.env={trace:(id,sp)=>{if(!on||!inst)return; if(id===1348||id===671)return;
   if(pend.length){const p=pend.pop();
     const rw=[];for(let i=1;i<=6;i++)rw.push(word(p.sp,i).toString(16));
     p.rec.ret_words=rw;
     // try interpret each ret word as *Int
     p.rec.ret_ints={};for(let i=1;i<=6;i++){const v=intAt(word(p.sp,i));if(v)p.rec.ret_ints['w'+i]=v.leval+'/'+v.hex;}
   }
   if(TARGET.has(id)){
     const rec={id,sp:Number(sp).toString(16)};
     const w=[];for(let i=1;i<=6;i++)w.push(word(sp,i).toString(16));
     rec.args=w;
     rec.argints={};for(let i=1;i<=6;i++){const v=intAt(word(sp,i));if(v)rec.argints['a'+i]=v.leval+'/'+v.hex;}
     evs.push(rec);pend.push({sp:Number(sp),rec});
   }
 }};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2],"hex");
 const lim=parseInt(process.argv[3]||"60");
 on=true;evs=[];pend=[];let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("msg="+msg.toString('hex'),"result="+JSON.stringify(r),"events="+evs.length);
 for(const e of evs.slice(0,lim)){
   console.log(`f${e.id} sp=${e.sp} args=[${e.args.join(',')}]`);
   if(Object.keys(e.argints).length)console.log('   argints '+JSON.stringify(e.argints));
   if(e.ret_words)console.log('   ret=['+e.ret_words.join(',')+'] '+(e.ret_ints&&Object.keys(e.ret_ints).length?JSON.stringify(e.ret_ints):''));
 }
 process.exit(0);
})();
