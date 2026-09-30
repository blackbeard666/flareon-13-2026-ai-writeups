require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function node(children){const parts=[b(1),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}return Buffer.concat(parts);}
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)throw new Error("len "+msg.length);const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const watch=[3267,3269,3251,3252,3254,3272,2992,3242];
 function test(name,msg){
   if(msg.length<32||msg.length>47){console.log(name.padEnd(40),"BADLEN "+msg.length);return;}
   on=true;for(const k in cnt)delete cnt[k];let r;try{r=check(mkFromMsg(msg));}catch(e){r="ERR";}on=false;
   console.log(name.padEnd(40),"L="+msg.length,watch.map(w=>w+":"+(cnt[w]||0)).join(" "),(cnt[3269]?" PARSED_OK":""),JSON.stringify(r));
 }
 // leaf candidates
 const L1=b(0); // [00]
 const L2=b(0,0); // [00,00]
 const L5=Buffer.concat([b(0),u32(0)]);
 // Build a node filling exactly 32 with leaf children of length 1 -> each entry=5 bytes; header 5; 5+5k=32 -> k=5.4 no
 // use children length 1 (5 bytes each): 5 header + n*5 = L. For L=32: n*5=27 no. L=45: n=8 -> 5+40=45. yes
 test("node(8x leaf[00]) L=45", node(Array(8).fill(L1)));
 // fill 32 exactly: header5 + entries. entry sizes 4+clen. want sum=27. Use one child len 23: 4+23=27
 test("node(leaf len23) L=32", node([Buffer.concat([b(0),Buffer.alloc(22,0)])]));
 test("node(2 leaves) fill32", node([Buffer.concat([b(0),Buffer.alloc(9,0)]),Buffer.concat([b(0),Buffer.alloc(9,0)])])); // 5+ (4+10)+(4+10)=37? recalc
 // node with children exactly filling: try leaves of len1 and pad node count
 // L=32: header5, need 27 from entries. entries of (4+1)=5 -> 5*5=25 (+2 short). (4+1)*5 + (4+... )
 // Simpler: single leaf child of length 23 (entry 4+23=27) done above.
 // nested: node(node(leaf))
 test("node(node(leaf len14)) L32", node([node([Buffer.concat([b(0),Buffer.alloc(13,0)])])]));
 // just a bare leaf as top-level (len 32)
 test("bare leaf[00]*32", Buffer.concat([b(0),Buffer.alloc(31,0)]));
 test("bare node count0 pad", Buffer.concat([node([]),Buffer.alloc(27,0)]));
 process.exit(0);
})();
