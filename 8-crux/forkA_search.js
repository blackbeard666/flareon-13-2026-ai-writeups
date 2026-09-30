require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function node(children){const parts=[b(1),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}return Buffer.concat(parts);}
const leaf=()=>b(0);
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)throw new Error("len "+msg.length);const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 let hits=[];
 function test(name,msg){
   if(msg.length<32||msg.length>47) return;
   on=true;for(const k in cnt)delete cnt[k];try{check(mkFromMsg(msg));}catch(e){}on=false;
   if(cnt[3269]){hits.push([name,msg.toString('hex'),cnt[3269],cnt[3251]||0,cnt[3252]||0]);console.log("HIT",name,msg.length,"3269="+cnt[3269]);}
 }
 // generate candidate trees and pad-to-length variants by adding leaf children until length in [32,47]
 // Because trailing bytes must be consumed exactly, we grow the root's children with empty leaves.
 // A leaf child entry costs 4(len)+1 = 5 bytes. Root header = 5. So len = 5 + 5*k for k leaf children.
 // 5+5k in [32,47] -> k in {6(35),7(40),8(45)}  ... also can use node children.
 for(let k=1;k<=8;k++) test("root+"+k+"leaves", node(Array(k).fill(leaf())));
 // root with node children (each empty node child = 4+5=9 bytes): len=5+9m
 for(let m=1;m<=4;m++) test("root+"+m+"emptynodes", node(Array(m).fill(node([]))));
 // mixed: adjust to hit exact lengths 32..47 by combining leaf(5) and node(9) child entries
 for(let L=32;L<=47;L++){
   // solve 5 + 5*a + 9*c = L
   for(let c=0;c<=4;c++){ const rem=L-5-9*c; if(rem>=0 && rem%5===0){ const a=rem/5; const kids=[...Array(a).fill(leaf()),...Array(c).fill(node([]))]; test("L"+L+"_a"+a+"_c"+c, node(kids)); } }
 }
 // deeper: root -> node -> leaves
 for(let k=1;k<=6;k++){ const inner=node(Array(k).fill(leaf())); test("root(node("+k+"leaves))",node([inner])); }
 // root with a single node child containing node children
 test("root(node(node,node))", node([node([node([]),node([])])]));
 console.log("total hits:",hits.length);
 if(hits.length) console.log(JSON.stringify(hits,null,1));
 process.exit(0);
})();
