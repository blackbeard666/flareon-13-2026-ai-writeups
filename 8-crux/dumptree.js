require('./wasm_exec.js');const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const p=Buffer.concat([msg,Buffer.alloc(48-msg.length,48-msg.length)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const names={0x4ef80:'VAL',0x4ef60:'PAIR',0x4ef40:'NIL'};
(async()=>{
 let inst=null,DV=null,U8=null,on=false,cap=null,n=0;
 function q(o){return DV.getBigUint64(Number(o),true);}
 function dumpIface(itab,data,depth){
   itab=Number(itab);data=Number(data);
   if(itab===0x4ef40)return 'NIL';
   if(itab===0x4ef80){let vb='';if(data>0x10000&&data+24<U8.length){const bptr=Number(q(data+8)),blen=Number(q(data+16));if(bptr>0x10000&&blen>0&&blen<64&&bptr+blen<U8.length)vb=Buffer.from(U8.slice(bptr,bptr+blen)).toString('hex');}return 'VAL('+vb+')';}
   if(itab===0x4ef60){const cp=data;if(cp<=0||cp+32>U8.length||depth>6)return 'PAIR(?)';return 'PAIR['+dumpIface(q(cp),q(cp+8),depth+1)+' , '+dumpIface(q(cp+16),q(cp+24),depth+1)+']';}
   return names[itab]||('0x'+itab.toString(16));
 }
 const go=new Go();go.importObject.env={trace:(idx,sp)=>{if(!on||!inst)return;if(idx===3269){n++;if(n===1){cap={itab:q(sp+8),data:q(sp+16)};}}}};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;const msg=Buffer.from(process.argv[2],"hex");
 on=true;cap=null;n=0;check(mk(msg));on=false;
 console.log("n3269="+n, cap?("itab=0x"+Number(cap.itab).toString(16)+" tree="+dumpIface(cap.itab,cap.data,0)):"no cap");
 process.exit(0);
})();
