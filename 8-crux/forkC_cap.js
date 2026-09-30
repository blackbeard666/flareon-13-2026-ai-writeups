require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null;let on=false;let caps=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 // interpret ptr as *big.Int: neg@0, abs slice {data@8,len@16}
 function bigAt(p){p=Number(p);if(p<=0x10000||p+24>U8.length)return null;
   const dp=Number(q(p+8)), ln=Number(q(p+16));
   if(dp<=0x10000||ln<0||ln>64||dp+ln*8>U8.length)return null;
   let v=0n;for(let i=ln-1;i>=0;i--){v=(v<<64n)|q(dp+i*8);}
   const neg=U8[p]&1; return (neg?'-':'')+v.toString();
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if([3251,3254,3256,3257,3258,3262,3268].includes(idx)){
     const ints=[];
     for(let i=1;i<8;i++){const p=q(sp+i*8);const b=bigAt(p);if(b!==null)ints.push('a'+i+'='+b);}
     if(ints.length) caps.push('f'+idx+' '+ints.join(' '));
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2]||"0100000000000000001300000001010101010101010101010101010101010101","hex");
 on=true;caps=[];check(mk(msg));on=false;
 console.log("msg="+msg.toString('hex'),"events="+caps.length);
 for(const c of caps) console.log("  "+c);
 process.exit(0);
})();
