require('./wasm_exec.js');const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const p=Buffer.concat([msg,Buffer.alloc(48-msg.length,48-msg.length)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,cap=null,n=0;
 function q(o){return DV.getBigUint64(Number(o),true);}
 const go=new Go();go.importObject.env={trace:(idx,sp)=>{if(!on||!inst)return;if(idx===3269){n++;if(n===1)cap={itab:q(sp+8),data:q(sp+16),sp:sp};}}};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;const msg=Buffer.from(process.argv[2],"hex");
 on=true;cap=null;n=0;check(mk(msg));on=false;
 const d=Number(cap.data);
 console.log("itab=0x"+Number(cap.itab).toString(16),"data=0x"+d.toString(16));
 function row(base){let s="0x"+base.toString(16)+": ";for(let i=0;i<48;i+=8)s+=q(base+i).toString(16).padStart(16,'0')+" ";return s;}
 console.log("at data:      ",row(d));
 // follow first 3 qwords as pointers
 for(let i=0;i<4;i++){const p=Number(q(d+i*8));if(p>0x10000&&p+48<U8.length)console.log("  ["+i+"]@0x"+p.toString(16)+": ",row(p));}
 process.exit(0);
})();
