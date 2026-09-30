require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("a729030050ad50044041f006","hex"); // gate -> force fall-through to 3269
const names={0x4ef80:'VAL',0x4ef60:'PAIR',0x4ef40:'NIL',0:'nil'};
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');
 const idx=base.indexOf(pat); const buf=Buffer.from(base);
 if(idx>=0){buf[idx+4]=0x1a;buf[idx+5]=0x41;buf[idx+6]=0x00;}
 let inst=null,DV=null,U8=null;let on=false;let events=[];let pending=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function tn(v){v=Number(v);return names[v]||('0x'+v.toString(16));}
 function bigOfVAL(data){ // VAL data -> big.Int struct {neg(bool)@0, abs nat slice @8:ptr,@16:len}
   data=Number(data); if(data<=0x10000||data+24>U8.length)return '?';
   const neg=U8[data]; const bptr=Number(q(data+8)); const blen=Number(q(data+16));
   if(bptr>0x10000&&blen>0&&blen<64&&bptr+blen<=U8.length){
     const b=Buffer.from(U8.slice(bptr,bptr+blen));
     // nat words little-endian u64; blen is word count for big.Int nat. show hex bytes
     return (neg?'-':'')+'nat['+blen+']='+b.toString('hex');
   }
   return (neg?'-':'')+'nat?bptr='+bptr.toString(16)+' len='+blen;
 }
 function iface(itab,data,depth){
   itab=Number(itab); data=Number(data);
   if(itab===0x4ef40||itab===0)return 'NIL';
   if(itab===0x4ef80)return 'VAL('+bigOfVAL(data)+')';
   if(itab===0x4ef60){ if(depth>5)return 'PAIR..'; const cp=data; if(cp<=0x10000||cp+32>U8.length)return 'PAIR(oob)';
     return 'PAIR['+iface(q(cp),q(cp+8),depth+1)+' , '+iface(q(cp+16),q(cp+24),depth+1)+']'; }
   return tn(itab)+'@'+data.toString(16);
 }
 const go=new Go();
 go.importObject.env={trace:(id,sp)=>{
   if(!on||!inst)return;
   if(id===1348||id===671)return;
   // flush pending results only once we've returned to caller frame (sp >= callee sp)
   if(pending.length && Number(sp)>=pending[pending.length-1].sp){
     const p=pending.pop();
     const ok=Number(q(p.sp+48))&0xff;
     p.rec.ret_ok=ok;
     p.rec.ret_words=[]; for(let i=6;i<12;i++)p.rec.ret_words.push(q(p.sp+i*8).toString(16));
   }
   if(id===3268){
     const rec={sp:Number(sp).toString(16)};
     const a=[]; for(let i=1;i<=5;i++)a.push(q(sp+i*8));
     rec.raw=a.map(x=>x.toString(16));
     // interpret as: arg0=a[0](itab?) ... try pairing consecutive as iface
     rec.a0_a1_iface=iface(a[0],a[1],0);
     rec.a2_a3_iface=iface(a[2],a[3],0);
     rec.a4=a[4].toString(16);
     events.push(rec);
     pending.push({sp:Number(sp),rec});
   }
 }};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2],"hex");
 on=true;events=[];pending=[];let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 // post-hoc read ok byte at each captured 3268 sp+48 (preserved since later frames use lower sp)
 for(const e of events){const spn=parseInt(e.sp,16);e.ret_ok=Number(q(spn+48))&0xff;e.post_words=[];for(let i=1;i<=8;i++)e.post_words.push(q(spn+i*8).toString(16));}
 console.log("msg="+msg.toString('hex'),"len="+msg.length,"result="+JSON.stringify(r),"n3268="+events.length);
 for(let i=0;i<events.length;i++){const e=events[i];
   console.log(`[${i}] sp=${e.sp} ok=${e.ret_ok}`);
   console.log(`    raw=[${e.raw.join(',')}] a4=${e.a4}`);
   console.log(`    (a0,a1)=${e.a0_a1_iface}`);
   console.log(`    (a2,a3)=${e.a2_a3_iface}`);
   if(e.ret_words)console.log(`    retwords[sp+48..]=[${e.ret_words.join(',')}]`);
 }
 process.exit(0);
})();
