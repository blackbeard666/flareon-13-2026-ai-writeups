require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("a729030050ad50044041f006","hex");
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0,0);return b;}
function ile(n){const o=[];while(n>0){o.push(n&0xff);n=Math.floor(n/256);}return Buffer.from(o);}
function node(children,kb,vb){kb=kb||Buffer.alloc(0);vb=vb||Buffer.alloc(0);
  let parts=[Buffer.from([1]),u32(children.length)];
  for(const c of children){parts.push(u32(c.length));parts.push(c);}
  parts.push(u32(kb.length));parts.push(kb);parts.push(u32(vb.length));parts.push(vb);
  return Buffer.concat(parts);}
function atom(kb,vb){return node([],kb,vb);}
// random tree generator constrained to <=47 bytes
function randTree(depth){
  if(depth<=0||Math.random()<0.4){
    const kl=Math.floor(Math.random()*3), vl=Math.floor(Math.random()*3);
    const kb=Buffer.alloc(kl,1), vb=Buffer.alloc(vl,1);
    if(kl)kb[kl-1]=1+Math.floor(Math.random()*4); if(vl)vb[vl-1]=1+Math.floor(Math.random()*4);
    return atom(kb,vb);
  }
  const nc=1+Math.floor(Math.random()*3); const ch=[];
  for(let i=0;i<nc;i++)ch.push(randTree(depth-1));
  return node(ch);
}
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');const idx=base.indexOf(pat);const buf=Buffer.from(base);
 if(idx>=0){buf[idx+4]=0x1a;buf[idx+5]=0x41;buf[idx+6]=0x00;}
 let inst=null,DV=null,U8=null;let on=false;let n3268=0,n3269=0;
 const go=new Go();
 go.importObject.env={trace:(id,sp)=>{if(!on||!inst)return;if(id===3268)n3268++;if(id===3269)n3269++;}};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 let best=[];let hits=[];
 const N=parseInt(process.argv[2]||"5000");
 for(let i=0;i<N;i++){
   const m=randTree(3);
   if(m.length<32||m.length>47)continue;
   on=true;n3268=0;n3269=0;let r;try{r=check(mk(m));}catch(e){r='ERR';}on=false;
   if(n3268>0){hits.push([m.toString('hex'),n3268,n3269,JSON.stringify(r)]);if(hits.length<=10)console.log('HIT n3268='+n3268+' n3269='+n3269+' r='+r+' '+m.toString('hex'));}
   if(n3269>best.length){best=[m.toString('hex'),n3269];}
 }
 console.log('total hits reaching 3268:',hits.length,'of',N);
 console.log('max n3269 seen:',best);
 process.exit(0);
})();
