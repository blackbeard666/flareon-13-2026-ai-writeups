require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)return null;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
// node with children, and TWO trailing length-prefixed blobs (k,v)
function nodeKV(children,k,v){const p=[b(1),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(k.length));p.push(k);p.push(u32(v.length));p.push(v);return Buffer.concat(p);}
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
   if(cnt[3269])hits.push([name,msg.toString('hex')]);
   if(!quiet)console.log(name.padEnd(42),"L="+msg.length,watch.map(w=>w+":"+(cnt[w]||0)).join(" "),(cnt[3269]?" <<OK":""),JSON.stringify(r));
 }
 // single node, empty children, k and v blobs
 test("nodeKV([],z9,z10)", nodeKV([],Buffer.alloc(9,0),Buffer.alloc(10,0)));
 test("nodeKV([],z0,z19)", nodeKV([],Buffer.alloc(0),Buffer.alloc(19,0)));
 test("nodeKV([],o9,o10)", nodeKV([],Buffer.alloc(9,1),Buffer.alloc(10,1)));
 // sweep k,v lengths
 for(let kl=0;kl<=20;kl++)for(let vl=0;vl<=20;vl++){const m=nodeKV([],Buffer.alloc(kl,0),Buffer.alloc(vl,0));if(m.length>=32&&m.length<=47)test("KV z"+kl+","+vl,m,true);}
 for(let kl=0;kl<=20;kl++)for(let vl=0;vl<=20;vl++){const m=nodeKV([],Buffer.alloc(kl,1),Buffer.alloc(vl,1));if(m.length>=32&&m.length<=47)test("KV o"+kl+","+vl,m,true);}
 // with 1 child
 const child=nodeKV([],Buffer.alloc(0),Buffer.alloc(0)); //5+4+4=13
 test("nodeKV([child],z,z)", nodeKV([child],Buffer.alloc(2,0),Buffer.alloc(2,0)));
 console.log("HITS:",JSON.stringify(hits.slice(0,20)),"count",hits.length);
 process.exit(0);
})();
