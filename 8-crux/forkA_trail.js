require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)return null;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const watch=[3267,3269,3251,3252,3254,3272,2992];
 function test(name,msg){
   if(!msg||msg.length<32||msg.length>47){console.log(name,"BADLEN",msg&&msg.length);return;}
   on=true;for(const k in cnt)delete cnt[k];let r;try{r=check(mkFromMsg(msg));}catch(e){r="ERR";}on=false;
   console.log(name.padEnd(38),"L="+msg.length,watch.map(w=>w+":"+(cnt[w]||0)).join(" "),(cnt[3269]?" <<PARSED_OK":""),JSON.stringify(r));
 }
 // hypothesis A: node = [1][count][ (len)(child) xN ][val:u32]; leaf = [0][val:u32]
 // leaf variants: [0], [0]+u32
 function leafA(v){return Buffer.concat([b(0),u32(v)]);}       // 5 bytes
 function leaf0(){return b(0);}                                 // 1 byte
 function nodeA(children,val){const p=[b(1),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(val));return Buffer.concat(p);}
 // empty node with trailing val: [1][0][val] =9 bytes; pad? must fill 32..47. Need exact fill.
 // Build root nodeA with leaf children to fill exactly.
 // sizes: leafA=5, leaf0=1. node header=5, trailing=4 => node overhead=9 + sum(4+childlen)
 // root with k leaf0 children: 9 + k*(4+1) = 9+5k. For 32<=..<=47: k in {5(34),6(39),7(44)}
 for(const k of [5,6,7]) test("nodeA("+k+"xleaf0)val0", nodeA(Array(k).fill(leaf0()),0));
 // root with leafA children: 9 + k*(4+5)=9+9k -> k in{3(36),4(45)}
 for(const k of [3,4]) test("nodeA("+k+"xleafA)val0", nodeA(Array(k).fill(leafA(0)),0));
 // hypothesis B: leaf = [0] only (no val), node has trailing. root k leaf0
 // (same as above nodeA with leaf0)
 // hypothesis C: maybe leaf also has trailing? try leaf as [0][val] and check bare leaf top-level (must be node though)
 // vary trailing val
 for(const v of [0,1,7,0x41]) test("nodeA(5xleaf0)val"+v, nodeA(Array(5).fill(leaf0()),v));
 // deeper tree: root(nodeA(leaf0*?),...) 
 test("root(nodeA(leaf0*1)+leaf0*?)", nodeA([nodeA([leaf0()],0)],0)); // check length
 process.exit(0);
})();
