require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)return null;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function nodeKV(children,k,v){const p=[b(1),u32(children.length)];for(const c of children){p.push(u32(c.length));p.push(c);}p.push(u32(k.length));p.push(k);p.push(u32(v.length));p.push(v);return Buffer.concat(p);}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 function test(name,msg){
   if(!msg||msg.length<32||msg.length>47){console.log(name,"BADLEN",msg&&msg.length);return false;}
   on=true;for(const k in cnt)delete cnt[k];let r;try{r=check(mkFromMsg(msg));}catch(e){r="ERR";}on=false;
   console.log(name.padEnd(30),"L="+msg.length,"3267:"+(cnt[3267]||0),"3269:"+(cnt[3269]||0),(cnt[3269]?"OK":"  "),JSON.stringify(r),msg.toString('hex'));
   return !!cnt[3269];
 }
 // characterize value: single node empty key, value various content, total 32 (val len 19)
 test("val 19x00", nodeKV([],b(),Buffer.alloc(19,0)));
 test("val 19x01", nodeKV([],b(),Buffer.alloc(19,1)));
 test("val 19x02", nodeKV([],b(),Buffer.alloc(19,2)));
 test("val 19xff", nodeKV([],b(),Buffer.alloc(19,0xff)));
 test("val [1,0,0..]", nodeKV([],b(),Buffer.concat([b(1),Buffer.alloc(18,0)])));
 test("val [0,..,0,1]", nodeKV([],b(),Buffer.concat([Buffer.alloc(18,0),b(1)])));
 test("val ascii", nodeKV([],b(),Buffer.from("ABCDEFGHIJKLMNOPQRS")));
 // key nonempty, value nonempty
 test("k9x01 v10x01", nodeKV([],Buffer.alloc(9,1),Buffer.alloc(10,1)));
 test("k9x00 v10x01", nodeKV([],Buffer.alloc(9,0),Buffer.alloc(10,1)));
 // node with children (each a KV leaf)
 const leaf=nodeKV([],b(),b(5)); // 5+4+ (0) +4+1 =14? =1+4 +4+0 +4+1 =14
 test("root([leaf],k,v)", nodeKV([leaf],b(),Buffer.from([1,2,3])));
 process.exit(0);
})();
