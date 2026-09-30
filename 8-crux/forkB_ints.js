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
 function run(M){for(const k in cnt)delete cnt[k];on=true;const r=check(mkMsg(M));on=false;return {r,v:cnt[3269]||0,k:cnt[3251]||0,big:cnt[3272]||0,b2:cnt[2992]||0};}
 function T(name,M){const o=run(M);console.log(name.padEnd(34),"len="+M.length,"3269="+o.v,"3251="+o.k,"3272="+o.big,"2992="+o.b2,JSON.stringify(o.r));}
 // [1] + K int32 zeros
 for(let K=0;K<=6;K++) T('[1]+'+K+'x i32(0)', Buffer.concat([Buffer.from([1]),...Array(K).fill(i32(0))]));
 // [1] + 3 int32 with various values
 T('[1]+i32(1,2,3)', Buffer.concat([Buffer.from([1]),i32(1),i32(2),i32(3)]));
 T('[1]+i32(0,0,1)', Buffer.concat([Buffer.from([1]),i32(0),i32(0),i32(1)]));
 T('[1]+i32(3,0,0)', Buffer.concat([Buffer.from([1]),i32(3),i32(0),i32(0)]));
 // maybe first int32 is count N, then N more
 T('[1]N=1+i32(5)', Buffer.concat([Buffer.from([1]),i32(1),i32(5)]));
 T('[1]N=2+i32(5,6)', Buffer.concat([Buffer.from([1]),i32(2),i32(5),i32(6)]));
 process.exit(0);
})();
