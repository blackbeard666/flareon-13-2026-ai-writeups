require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
const i32=(n)=>Buffer.from([n&255,(n>>8)&255,(n>>16)&255,(n>>>24)&255]);
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(idx)=>{ if(on)cnt[idx]=(cnt[idx]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 function T(name,M){for(const k in cnt)delete cnt[k];on=true;const r=check(mkMsg(M));on=false;
   console.log(name.padEnd(30),"3269="+(cnt[3269]||0),"3251="+(cnt[3251]||0),"3272="+(cnt[3272]||0),"2992="+(cnt[2992]||0),"3252="+(cnt[3252]||0),"3254="+(cnt[3254]||0),JSON.stringify(r));}
 const EL=Buffer.concat([Buffer.from([1]),i32(0)]); // [1][0] empty list, 5 bytes
 T('emptylist(5B)',EL);
 T('EL+0x00*8',Buffer.concat([EL,Buffer.alloc(8,0)]));
 T('EL+0x2a*8',Buffer.concat([EL,Buffer.alloc(8,0x2a)]));
 T('EL+"flag"',Buffer.concat([EL,Buffer.from('flag@flare-on.com')]));
 T('EL+incr16',Buffer.concat([EL,Buffer.from([0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15])]));
 T('[0](E)',Buffer.from([0]));
 T('[0]+8',Buffer.from([0,1,2,3,4,5,6,7,8]));
 process.exit(0);
})();
