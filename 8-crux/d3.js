require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){const pl=48-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function nd(children,k,v){k=k||0;v=v||0;const kb=bLE(k),vb=bLE(v);const p=[Buffer.from([1]),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
global.nd=nd;
(async()=>{
 let inst=null,DV=null,U8=null,on=false,first=null;
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function walk(itab,data,depth){
   itab=Number(itab);data=Number(data);
   if(depth>10)return '...';
   if(itab===0x4ef40||itab===0)return 'NIL';
   if(itab===0x4ef80){const neg=U8[data];const p=Number(q(data+8)),l=Number(q(data+16));let v=0n;if(p>0x1000&&l>0&&l<64){for(let i=l-1;i>=0;i--)v=(v<<8n)|BigInt(U8[p+i]);}return 'V('+(neg?'-':'')+v+')';}
   if(itab===0x4ef60){return '['+walk(q(data),q(data+8),depth+1)+' . '+walk(q(data+16),q(data+24),depth+1)+']';}
   return '?0x'+itab.toString(16);
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return;
   if(idx===3269 && first===null){ first={itab:Number(q(sp+8)),data:Number(q(sp+16))}; }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 const msg=eval(process.argv[2]);
 if(msg.length<32||msg.length>47){console.log("LEN "+msg.length+" OOR");process.exit(0);}
 on=true;first=null;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r),"len="+msg.length);
 if(first)console.log("arg to eval: itab=0x"+first.itab.toString(16)+" => "+walk(first.itab,first.data,0));
 process.exit(0);
})();