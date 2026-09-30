require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function leaf(k,v){const kb=k? bigLE(k):Buffer.alloc(0); const vb=v?bigLE(v):Buffer.alloc(0); return Buffer.concat([Buffer.from([1]),u32(0),u32(kb.length),kb,u32(vb.length),vb]);}
function node(children,k,v){const kb=k?bigLE(k):Buffer.alloc(0); const vb=v?bigLE(v):Buffer.alloc(0); const parts=[Buffer.from([1]),u32(children.length)]; for(const c of children){parts.push(u32(c.length)); parts.push(c);} parts.push(u32(kb.length),kb,u32(vb.length),vb); return Buffer.concat(parts);}
function bigLE(n){let a=[];n=BigInt(n);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}if(a.length==0)a=[];return Buffer.from(a);}
const NAMES={0x4ef40:'NIL',0x4ef60:'PAIR',0x4ef80:'VAL'};
(async()=>{
 let inst=null,DV=null,U8=null,cap=null,n=0;
 function q(o){return Number(DV.getBigUint64(Number(o),true));}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(idx===3269 && inst && n===0){ n++; cap={itab:q(sp+8+8*27), data:0}; /*grab words*/ cap.words=[];for(let i=0;i<40;i++)cap.words.push(q(sp+i*8)); } }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=node([leaf(2,1)]); // list[ leaf(key=2,val=1) ]
 console.log("msg hex:",msg.toString('hex'),"len",msg.length);
 n=0;cap=null;check(mk(msg));
 // Find the argument interface to 3269: scan sp words for a pointer whose *(+0) or itab is 0x4ef60/80/40
 function walk(itab,data,depth,seen){
   if(depth>8) return '...';
   const nm=NAMES[itab]||('itab0x'+itab.toString(16));
   if(itab===0x4ef40) return 'NIL';
   if(itab===0x4ef80){ // VALUE -> data is *BigInt {neg@0,ptr@8,len@16}
     const neg=U8[data]; const p=q(data+8),l=q(data+16); let mag='';
     if(p>0x1000&&l>0&&l<64) mag=Buffer.from(U8.slice(p,p+l)).toString('hex');
     return 'VAL('+(neg?'-':'')+'0x'+(mag||'0')+')';
   }
   if(itab===0x4ef60){ // PAIR -> data is ptr to {car_itab@0,car_data@8,cdr_itab@16,cdr_data@24}
     const ci=q(data),cd=q(data+8),di=q(data+16),dd=q(data+24);
     return '['+walk(ci,cd,depth+1)+' . '+walk(di,dd,depth+1)+']';
   }
   // unknown: dump 32 bytes
   return nm+'{'+Buffer.from(U8.slice(data,data+32)).toString('hex')+'}';
 }
 // The arg interface: from cap.words find consecutive (itab,data) where itab in known set
 let found=false;
 for(let i=0;i<cap.words.length-1;i++){
   const it=cap.words[i];
   if(it===0x4ef60||it===0x4ef80||it===0x4ef40){
     console.log("arg iface at word",i,"itab",NAMES[it],"=>",walk(it,cap.words[i+1],0));
     found=true; break;
   }
 }
 if(!found){ console.log("words:",cap.words.map((w,i)=>i+':'+w.toString(16)).join(' ')); }
 process.exit(0);
})();
