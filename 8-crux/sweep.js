// Systematic sweep of feasible tree inputs. Records 3190 count + call profile per input.
const O=require('./oracle_map.js');
const watch=[3269,3190,3268,3256,3254,3251,3257,3258,3252,3272,2992];
(async()=>{
 let check=await O.fresh();
 const cnt=()=>global.__cnt;
 // wrap run to also return counts
 const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
 // reimplement a run that returns counts object
 const crypto=require('crypto');
 const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
 function mk(msg){const p=Buffer.concat([msg,Buffer.alloc(48-msg.length,48-msg.length)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
 // We need access to the counter; re-fresh with our own trace
 const fs=require('fs');require('./wasm_exec.js');const WASM=fs.readFileSync('main_instr2.wasm');
 let C={},on=false;
 async function fresh2(){const go=new Go();go.importObject.env={trace:(i)=>{if(on)C[i]=(C[i]||0)+1;}};const {instance}=await WebAssembly.instantiate(WASM,go.importObject);go.run(instance);await new Promise(r=>setImmediate(r));return globalThis.check;}
 check=await fresh2();
 const seen={};
 async function T(label,msg){
   if(msg.length<32||msg.length>47){return {skip:msg.length};}
   C={};on=true;let r,crash=false;try{r=check(mk(msg));}catch(e){r="ERR";crash=true;}on=false;
   const g=w=>C[w]||0;
   const prof=watch.map(w=>g(w)).join(',');
   const accept=g(3190)>=2||g(3272)>0||g(2992)>0;
   const line=label.padEnd(26)+" L"+msg.length+" 3190="+g(3190)+" prof["+watch.join(',')+"]=["+prof+"] "+JSON.stringify(r)+(accept?"  <<<ACCEPT>>>":"");
   if(!seen[prof]){seen[prof]=label;}
   if(crash)check=await fresh2();
   return {g,prof,accept,line,r};
 }
 const results=[];
 const push=async(l,m)=>{const x=await T(l,m);if(!x.skip){results.push(x.line);if(x.accept)console.log("ACCEPT",l,m.toString('hex'));}};

 // ---- Group 1: list[leaf(K,V)] single-byte sweep ----
 // pad V to reach length 34 so K,V values isolated (length const). len=30+|K|+|V|. use V as multibyte pad? keep value semantics: use K single byte, V single byte, pad to 34 via extra? We can't pad w/o changing tree. So vary and accept differing lengths.
 for(let K=0;K<=16;K++){
   for(let V=0;V<=16;V++){
     const kb=K===0?null:O.bigLE(K), vb=V===0?null:O.bigLE(V);
     const msg=O.node([O.leaf(kb,vb)],0,null);
     await push(`1L k=${K},v=${V}`,msg);
   }
 }
 // larger single values (multi-byte) to reach various lengths, K=1
 for(const V of [255,256,65535,65536,0x10000000,0xffffffff]){
   const msg=O.node([O.leaf(1,O.bigLE(V))],0,null); await push(`1L k=1,v=${V}`,msg);
 }
 // key big, val small
 for(const K of [255,256,65535,0xffffffff]){
   const msg=O.node([O.leaf(O.bigLE(K),1)],0,null); await push(`1L k=${K},v=1`,msg);
 }
 // equal key==val
 for(const X of [1,2,3,5,7,42,255,256]){const msg=O.node([O.leaf(O.bigLE(X),O.bigLE(X))],0,null);await push(`1L k=v=${X}`,msg);}

 // ---- Group 2: two empty leaves (only 2-child shape at 47B) ----
 await push(`2L empty,empty`,O.node([O.leaf(0,0),O.leaf(0,0)],0,null));

 // ---- Group 3: depth-3 chain ----
 await push(`chain L[L[leaf00]]`,O.node([O.node([O.leaf(0,0)],0,null)],0,null));

 // ---- Group 4: list with 1 child that is a list (depth2 inner leaf) with data in inner leaf ----
 // top L[ L[ leaf(K,V) ] ]: size = 17(top)+17(mid overhead+prefix)+... too big? top:1+4+(4+midlen)+4+4; mid:1+4+(4+leaflen)+4+4; leaf=13+k+v
 // top=13+4+midlen; mid=13+4+leaflen; leaf=13+k+v => top=13+4+13+4+13+k+v=47+k+v -> only k=v=0. already chain.

 // ---- Group 5: list of 1 leaf where we vary length by val bytes but keep value pattern (probe length sensitivity) ----
 for(const n of [2,5,9,13,17]){const msg=O.node([O.leaf(1,O.valLen(n))],0,null);await push(`1L k=1,vlen=${n}`,msg);}

 for(const l of results) console.log(l);
 // distinct profiles summary
 console.log("\n--- distinct profiles (prof -> first label) ---");
 for(const [p,l] of Object.entries(seen)) console.log("["+p+"] "+l);
 process.exit(0);
})();
