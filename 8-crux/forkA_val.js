require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)return null;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
// node with children and a value blob
function nodeV(children,val){const p=[b(1),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(val.length));p.push(val);return Buffer.concat(p);}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const watch=[3267,3269,3251,3252,3254,3272,2992];
 let hits=[];
 function test(name,msg,quiet){
   if(!msg||msg.length<32||msg.length>47){if(!quiet)console.log(name,"BADLEN",msg&&msg.length);return;}
   on=true;for(const k in cnt)delete cnt[k];let r;try{r=check(mkFromMsg(msg));}catch(e){r="ERR";}on=false;
   if(cnt[3269]){hits.push([name,msg.toString('hex')]);}
   if(!quiet)console.log(name.padEnd(40),"L="+msg.length,watch.map(w=>w+":"+(cnt[w]||0)).join(" "),(cnt[3269]?" <<PARSED_OK":""),JSON.stringify(r));
 }
 // leaf = node with 0 children and a value: nodeV([],val)
 // empty val
 test("nodeV([],'')", nodeV([],Buffer.alloc(0)));           //9 -> too short, pad handled by fill? need 32..47
 // fill: nodeV([], val of len 23) = 5+4+23=32
 test("nodeV([],val23=zeros)", nodeV([],Buffer.alloc(23,0)));
 test("nodeV([],val23=ones)", nodeV([],Buffer.alloc(23,1)));
 test("nodeV([],val23=0xff)", nodeV([],Buffer.alloc(23,0xff)));
 // node with 1 child (itself a valued leaf) + own value
 // child = nodeV([],cval); root = nodeV([child], rval)
 const c1=nodeV([],Buffer.alloc(4,0)); // 5+4+4=13
 test("nodeV([c1],val)", nodeV([c1],Buffer.alloc(6,0))); //5 + (4+13) + (4+6)=32
 // sweep value lengths for a single-node
 for(let vl=0;vl<=42;vl++){ const m=nodeV([],Buffer.alloc(vl,0)); if(m.length>=32&&m.length<=47) test("nodeV([],val"+vl+"z)",m,true);}
 for(let vl=0;vl<=42;vl++){ const m=nodeV([],Buffer.alloc(vl,1)); if(m.length>=32&&m.length<=47) test("nodeV([],val"+vl+"o)",m,true);}
 console.log("HITS:",JSON.stringify(hits));
 process.exit(0);
})();
