require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const names={0x4ef80:'VAL',0x4ef60:'PAIR',0x4ef40:'NIL'};
(async()=>{
 let inst=null,DV=null,U8=null;let on=false;let cap=null,n=0;
 function q(o){return DV.getBigUint64(Number(o),true);}
 function tn(v){v=Number(v);return names[v]||('0x'+v.toString(16));}
 function dumpIface(ptr,depth){ // ptr -> {itab, data}; recurse
   ptr=Number(ptr); if(ptr<=0||ptr+16>U8.length||depth>4) return '?';
   const itab=Number(q(ptr)); const data=Number(q(ptr+8));
   if(itab===0x4ef40) return 'NIL';
   if(itab===0x4ef80){ // value: data points to big.Int {neg? , ptr,len,cap} or bytes
     let vb=''; if(data>0x10000&&data+24<U8.length){const bptr=Number(q(data+8)),blen=Number(q(data+16)); if(bptr>0x10000&&blen>0&&blen<64&&bptr+blen<U8.length) vb=Buffer.from(U8.slice(bptr,bptr+blen)).toString('hex'); }
     return 'VAL('+vb+')';
   }
   if(itab===0x4ef60){ // pair: data -> {car_itab,car_data, cdr_itab,cdr_data}
     const cp=data; if(cp<=0||cp+32>U8.length) return 'PAIR(?)';
     const car=dumpIface(cp,depth+1); const cdr=dumpIface(cp+16,depth+1);
     return 'PAIR['+car+' , '+cdr+']';
   }
   return tn(itab);
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; if(idx===3269){n++;if(n===1){cap=q(sp+8);}} }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2],"hex");
 on=true;cap=null;n=0;check(mk(msg));on=false;
 // cap is the interface data ptr (arg). It's itab already 0x4ef60. Actually sp+8=itab? Let me treat sp+8 as itab, sp+16 as data
 // We captured q(sp+8). Let me reconstruct: build a fake iface: the arg is {itab@sp+8, data@sp+16}
 console.log(process.argv[3]||"", "n3269="+n);
 process.exit(0);
})();
