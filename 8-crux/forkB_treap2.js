require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null,DV=null,U8=null;let on=false;let ev=[];
 function q(o){return Number(DV.getBigUint64(o,true));}
 function hx(p,n){if(p<0x1000||p+n>U8.length)return null;return Buffer.from(U8.slice(p,p+n)).toString('hex');}
 function asc(p,n){if(p<0x1000||p+n>U8.length)return null;return Buffer.from(U8.slice(p,p+n)).toString('latin1');}
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if([3254,3250].includes(idx)){
     const w=[];for(let i=1;i<=6;i++)w.push(q(sp+i*8));
     const derefs=w.map(v=> (v>0x1000&&v<U8.length)? hx(v,32):null);
     ev.push([idx,w.map(x=>x.toString(16)),derefs]);
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 on=true;ev=[];const r=check(mkMsg(Buffer.from([0])));on=false;
 console.log("leaf[0] =>",JSON.stringify(r));
 ev.forEach(([i,w,d])=>{console.log("f"+i,"words="+w.join(','));d.forEach((x,k)=>{if(x)console.log("   arg"+(k+1)+"@"+w[k]+" hex="+x+" asc="+JSON.stringify(asc(parseInt(w[k],16),16)));});});
 process.exit(0);
})();
