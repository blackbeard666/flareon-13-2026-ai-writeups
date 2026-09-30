require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("a729030050ad50044041f006","hex");
// tree builders
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0,0);return b;}
function ile(n){const o=[];while(n>0){o.push(n&0xff);n=Math.floor(n/256);}return Buffer.from(o);}
function node(children,kb,vb){kb=kb||Buffer.alloc(0);vb=vb||Buffer.alloc(0);
  let parts=[Buffer.from([1]),u32(children.length)];
  for(const c of children){parts.push(u32(c.length));parts.push(c);}
  parts.push(u32(kb.length));parts.push(kb);parts.push(u32(vb.length));parts.push(vb);
  return Buffer.concat(parts);}
function atom(k,v){return node([],ile(k||0),ile(v||0));}
function padTo(children,kb,target){let m=node(children,kb,Buffer.alloc(0));if(m.length>target)return null;let need=target-m.length;return node(children,kb,Buffer.alloc(need,1));}
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');const idx=base.indexOf(pat);const buf=Buffer.from(base);
 if(idx>=0){buf[idx+4]=0x1a;buf[idx+5]=0x41;buf[idx+6]=0x00;}
 let inst=null,DV=null,U8=null;let on=false;let n3269=0,n3268=0;
 function q(o){o=Number(o);if(o<0||o+8>U8.length)return 0n;return DV.getBigUint64(o,true);}
 const go=new Go();
 go.importObject.env={trace:(id,sp)=>{if(!on||!inst)return;if(id===3269)n3269++;if(id===3268)n3268++;}};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 U8=new Uint8Array(instance.exports.mem.buffer);DV=new DataView(instance.exports.mem.buffer);
 const check=globalThis.check;
 // build many candidate shapes (32..47 bytes)
 const cands=[];
 function add(name,m){if(m&&m.length>=32&&m.length<=47)cands.push([name,m]);}
 // lists of lists (recursion producing pairs)
 add('L[L[atom]]',padTo([node([atom(0,0)],Buffer.alloc(0),Buffer.alloc(0))],Buffer.alloc(0),47));
 add('L[L[atom],atom]',node([node([atom(1,1)]),atom(2,2)]));
 add('L[atom,atom]k',padTo([atom(1,1),atom(2,2)],Buffer.alloc(0),47));
 add('L[L[a,a]]',node([node([atom(1,1),atom(2,2)])]));
 add('L[L[nil]]',padTo([node([atom(0,0)])],Buffer.alloc(0),47));
 add('L[L[L[a]]]',node([node([node([atom(1,1)])])]));
 add('L3[a,a,a]',node([atom(),atom(),atom()])); // 64 too big -> filtered
 add('L[a(bigv)]',padTo([atom(1,0)],Buffer.alloc(0),47));
 add('L[a,a]_kv',node([atom(1,2),atom(3,4)]));
 // list where children are lists of atoms (key,value) pairs (map entries)
 add('map1',node([node([atom(1,0),atom(0,9)])])); // entry [key=1,val=9]
 add('map2',padTo([node([atom(1,0),atom(0,9)])],Buffer.alloc(0),47));
 add('L[pair]',node([node([atom(0,1),atom(0,2)])]));
 // deep nesting single child chains
 let cur=atom(1,1); for(let d=0;d<3;d++){cur=node([cur]); }
 add('chain3',cur);
 // sweep root key values with list of 1 list
 for(let k=0;k<4;k++){add('L[L[a]]_k'+k,padTo([node([atom(k,0)])],ile(k),47));}
 for(const [name,m] of cands){
   on=true;n3269=0;n3268=0;let r;try{r=check(mk(m));}catch(e){r='ERR';}on=false;
   console.log((name+'            ').slice(0,16),'len='+m.length,'n3269='+n3269,'n3268='+n3268,'r='+JSON.stringify(r),m.toString('hex'));
 }
 process.exit(0);
})();
