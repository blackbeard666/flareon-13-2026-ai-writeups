require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){const pl=48-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0);return b;}
function bLE(n){let a=[];n=BigInt(n||0);if(n<0n)n=-n;while(n>0n){a.push(Number(n&255n));n>>=8n;}return Buffer.from(a);}
function nd(children,k,v){const kb=bLE(k),vb=bLE(v);const p=[Buffer.from([1]),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(p);}
global.nd=nd;
(async()=>{
 let inst=null,DV=null,U8=null,on=false,done=false,LOG=[];
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 function bi(ptr){ptr=Number(ptr);if(ptr<=0x1000||ptr+24>U8.length)return '?';const neg=U8[ptr];const p=Number(q(ptr+8)),l=Number(q(ptr+16));if(p<=0x1000||l<=0||l>64||p+l>U8.length)return (neg?'-':'')+'0';let v=0n;for(let i=l-1;i>=0;i--)v=(v<<8n)|BigInt(U8[p+i]);return (neg?'-':'')+v.toString();}
 function dump(itab,data,label){
   itab=Number(itab)>>>0;data=Number(data)>>>0;
   const nm={0x4ef40:'NIL',0x4ef60:'PAIR/Node',0x4ef80:'VALUE'}[itab]||('0x'+itab.toString(16));
   LOG.push(label+': itab='+nm+' data=0x'+data.toString(16));
   if(data>0x1000){let w=[];for(let i=0;i<5;i++)w.push('0x'+q(data+i*8).toString(16));LOG.push('   words='+w.join(' ')+'  (asVAL bi='+bi(data)+')');
     LOG.push('   key@24='+bi(q(data+24))+' val@32='+bi(q(data+32)));}
 }
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst||done)return;
   if(idx===3269){ done=true; U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);
     const it=Number(q(sp+8)),da=Number(q(sp+16));
     dump(it,da,'TOP');
     const sp2=Number(q(da)),ln=Number(q(da+8));
     LOG.push('TOP.children slice ptr=0x'+sp2.toString(16)+' len='+ln);
     for(let e=0;e<ln&&e<4;e++){dump(q(sp2+e*16),q(sp2+e*16+8),'  child'+e);}
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const msg=eval(process.argv[2]);
 if(msg.length<32||msg.length>47){console.log("LEN OOR "+msg.length);process.exit(0);}
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 console.log("result="+JSON.stringify(r),"len="+msg.length);
 console.log(LOG.join('\n'));
 process.exit(0);
})();