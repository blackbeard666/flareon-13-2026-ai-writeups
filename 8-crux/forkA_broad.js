require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const u32=(n)=>{const x=Buffer.alloc(4);x.writeUInt32LE(n>>>0);return x;};
const b=(...a)=>Buffer.from(a);
function nodeC(count,body){return Buffer.concat([b(1),u32(count),body]);}
function mkFromMsg(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)return null;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 let tried=0,hits=[];
 function test(msg){
   if(!msg||msg.length<32||msg.length>47)return;
   const inp=mkFromMsg(msg);if(!inp)return;
   on=true;for(const k in cnt)delete cnt[k];try{check(inp);}catch(e){}on=false;tried++;
   if(cnt[3269]){hits.push(msg.toString('hex'));console.log("HIT L="+msg.length,msg.toString('hex'),"3269="+cnt[3269]);}
 }
 // 1) leaf with integer payload as ROOT: [0][bytes...] various lengths
 for(let L=32;L<=47;L++){ test(Buffer.concat([b(0),Buffer.alloc(L-1,0)])); test(Buffer.concat([b(0),Buffer.alloc(L-1,0xff)])); }
 // 2) node with children that are integer-leaves ([0][val bytes])
 function ileaf(bytes){return Buffer.concat([b(0),bytes]);}
 // root with 2 int-leaf children of chosen sizes to fill L
 for(let L=32;L<=47;L++){ // 5 header + (4+ a) + (4+ c) = L
   const rem=L-5-8; if(rem<0)continue; const a=Math.floor(rem/2), c=rem-a;
   const body=Buffer.concat([u32(1+a),ileaf(Buffer.alloc(a,1)),u32(1+c),ileaf(Buffer.alloc(c,2))]);
   test(nodeC(2,body));
 }
 // 3) random messages
 for(let i=0;i<3000;i++){ const L=32+(i%16); const m=crypto.randomBytes(L); m[0]=1; m.writeUInt32LE((i%3),1); test(m); }
 for(let i=0;i<2000;i++){ const L=32+(i%16); const m=crypto.randomBytes(L); m[0]=0; test(m); }
 // 4) node count matching small, children random
 console.log("tried",tried,"hits",hits.length);
 process.exit(0);
})();
