require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bigLE(n){let a=[];n=BigInt(n||0);let neg=n<0n;if(neg)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function leaf(k,v){k=k||0;v=v||0;const kb=bigLE(k),vb=bigLE(v);return Buffer.concat([Buffer.from([1]),u32(0),u32(kb.length),kb,u32(vb.length),vb]);}
function node(children,k,v){k=k||0;v=v||0;const kb=bigLE(k),vb=bigLE(v);const parts=[Buffer.from([1]),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}parts.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(parts);}
const NAME={3251:'NewInt',3254:'Cmp',3256:'Add',3257:'Sub',3258:'Mul',3262:'DivMod',3261:'mkVal',3268:'PRED',3269:'eval'};
(async()=>{
 let inst=null,DV=null,U8=null,on=false,log=[];
 function q(o){o=Number(o); if(o<0||o+8>U8.length) return 0n; return DV.getBigUint64(o,true);}
 function readInt(p){ // p -> *Int {neg@0,ptr@8,len@16}
   p=Number(p); if(p<=0||p+24>U8.length) return '<badptr>';
   const neg=U8[p]; const ptr=Number(q(p+8)), len=Number(q(p+16));
   if(ptr<=0||len<0||len>256||ptr+len>U8.length) return (neg?'-':'')+'?{ptr='+ptr.toString(16)+',len='+len+'}';
   let v=0n; for(let i=len-1;i>=0;i--) v=(v<<8n)|BigInt(U8[ptr+i]);
   return (neg?'-':'')+v.toString();
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{
   if(!on||!inst)return;
   if(idx===3269){ log.push('eval(depth)'); return; }
   if(idx===3251){ // NewInt(int64@sp+8)
     const n=BigInt.asIntN(64,q(sp+8)); log.push('NewInt('+n+')'); return; }
   if(idx===3254){ log.push('Cmp(a='+readInt(q(sp+8))+', b='+readInt(q(sp+16))+')'); return; }
   if(idx===3256){ log.push('Add('+readInt(q(sp+8))+', '+readInt(q(sp+16))+')'); return; }
   if(idx===3257){ log.push('Sub('+readInt(q(sp+8))+', '+readInt(q(sp+16))+')'); return; }
   if(idx===3258){ log.push('Mul('+readInt(q(sp+8))+', '+readInt(q(sp+16))+')'); return; }
   if(idx===3262){ log.push('DivMod('+readInt(q(sp+8))+', '+readInt(q(sp+16))+')'); return; }
   if(idx===3268){ log.push('PRED(a0='+readInt(q(sp+8))+', a1='+readInt(q(sp+16))+', list@'+Number(q(sp+24)).toString(16)+', n='+BigInt.asIntN(64,q(sp+32))+')'); return; }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const which=process.argv[2]||'leaf2';
 let msg;
 if(which==='leaf2') msg=node([leaf(2,1)]);
 else if(which==='leaf1') msg=node([leaf(1,1)]);
 else if(which==='leaf3') msg=node([leaf(3,1)]);
 else if(which==='two') msg=node([leaf(2,3),leaf(0,5)]);
 else msg=node([leaf(parseInt(which),1)]);
 console.log("msg:",msg.toString('hex'),"len",msg.length);
 on=true; let r; try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;} on=false;
 console.log("result:",JSON.stringify(r));
 console.log("arith log ("+log.length+" ops):");
 for(const l of log) console.log("  "+l);
 process.exit(0);
})();
