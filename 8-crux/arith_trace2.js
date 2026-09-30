require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bigLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function leaf(k,v){k=k||0;v=v||0;const kb=bigLE(k),vb=bigLE(v);return Buffer.concat([Buffer.from([1]),u32(0),u32(kb.length),kb,u32(vb.length),vb]);}
function node(children,k,v){k=k||0;v=v||0;const kb=bigLE(k),vb=bigLE(v);const parts=[Buffer.from([1]),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}parts.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(parts);}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,log=[];
 function q(o){o=Number(o); if(o<0||o+8>U8.length) return 0n; return DV.getBigUint64(o,true);}
 function readInt(p){p=Number(p);if(p<=0||p+24>U8.length)return'<bad>';const neg=U8[p];const ptr=Number(q(p+8)),len=Number(q(p+16));if(ptr<=0||len<0||len>256||ptr+len>U8.length)return(neg?'-':'')+'0';let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U8[ptr+i]);return(neg?'-':'')+v.toString();}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3251)log.push('NewInt('+BigInt.asIntN(64,q(sp+8))+')');
   else if(idx===3254)log.push('Cmp('+readInt(q(sp+8))+','+readInt(q(sp+16))+')');
   else if(idx===3256)log.push('Add('+readInt(q(sp+8))+','+readInt(q(sp+16))+')');
   else if(idx===3257)log.push('Sub('+readInt(q(sp+8))+','+readInt(q(sp+16))+')');
   else if(idx===3258)log.push('Mul('+readInt(q(sp+8))+','+readInt(q(sp+16))+')');
   else if(idx===3262)log.push('DivMod('+readInt(q(sp+8))+','+readInt(q(sp+16))+')');
   else if(idx===3268)log.push('PRED(a0='+readInt(q(sp+8))+',a1='+readInt(q(sp+16))+',n='+BigInt.asIntN(64,q(sp+32))+')');
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const k=parseInt(process.argv[2]||'1'), v=parseInt(process.argv[3]||'1');
 const msg=node([leaf(k,v)]);
 on=true; let r; try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;} on=false;
 console.log("key="+k+" val="+v+" -> "+JSON.stringify(r)+"  ["+log.join(' ; ')+"]");
 process.exit(0);
})();
