// Dynamic oracle for ch8 crux eval mapping.
// Builds grammar trees, feeds check(), counts key func entries via env.trace on main_instr2.wasm.
// Accept signal: 3190 count == 2 (final flag decrypt) and/or 3272/2992 fire.
require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const WASM=fs.readFileSync('main_instr2.wasm');
function mk(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)throw new Error("len "+msg.length);const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}

// ---- grammar builders ----
function u32(n){const b=Buffer.alloc(4);b.writeUInt32LE(n>>>0,0);return b;}
// canonical LE bytes for nonneg bigint; empty for 0. last byte nonzero guaranteed.
function bigLE(v){v=BigInt(v);if(v<0n)throw new Error("neg");if(v===0n)return Buffer.alloc(0);const out=[];while(v>0n){out.push(Number(v&0xffn));v>>=8n;}return Buffer.from(out);}
// key/val may be: bigint/number -> bigLE, Buffer -> raw (caller ensures canonical), or null->empty
function enc(x){if(x==null)return Buffer.alloc(0);if(Buffer.isBuffer(x))return x;return bigLE(x);}
function leaf(k,v){const kb=enc(k),vb=enc(v);return Buffer.concat([Buffer.from([1]),u32(0),u32(kb.length),kb,u32(vb.length),vb]);}
function node(children,k,v){const kb=enc(k),vb=enc(v);const parts=[Buffer.from([1]),u32(children.length)];for(const c of children){parts.push(u32(c.length));parts.push(c);}parts.push(u32(kb.length),kb,u32(vb.length),vb);return Buffer.concat(parts);}

// pad a tree's leaf/val to reach a target total msg length in [32,47] by widening the LAST val we control.
// Simpler: caller sizes trees directly. Provide helper to make a val buffer of exact length ending nonzero.
function valLen(n){if(n===0)return Buffer.alloc(0);const b=Buffer.alloc(n,0x41);b[n-1]=0x01;return b;}

// ---- oracle core ----
const watch=[3267,3269,3270,3190,3268,3256,3254,3251,3257,3258,3252,3272,2992,3166,3184,3269];
let cnt={},on=false;
async function fresh(){
 const go=new Go();
 go.importObject.env={trace:(i,sp)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(WASM,go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 return globalThis.check;
}
async function run(check,label,msg){
 if(msg.length<32||msg.length>47){console.log(label.padEnd(30)+" SKIP len="+msg.length+" hex="+msg.toString('hex'));return check;}
 cnt={};on=true;let r,crashed=false;
 try{r=check(mk(msg));}catch(e){r="ERR:"+e.message;crashed=true;}
 on=false;
 const g=w=>cnt[w]||0;
 const accept=g(3190)>=2||g(3272)>0||g(2992)>0;
 const prof="ev3269:"+g(3269)+" treap3268:"+g(3268)+" cmp3256:"+g(3256)+" f3254:"+g(3254)+" f3251:"+g(3251)+" f3257:"+g(3257)+" f3258:"+g(3258)+" f3252:"+g(3252);
 const flag=accept?"  <<< ACCEPT >>>":(g(3269)>=2?"":" [no-eval]");
 console.log(label.padEnd(30)+" L"+msg.length+" 3190="+g(3190)+" | "+prof+" | r="+JSON.stringify(r)+flag);
 if(crashed) check=await fresh();
 return check;
}

module.exports={u32,bigLE,enc,leaf,node,valLen,mk,fresh,run};

if(require.main===module){(async()=>{
 let check=await fresh();
 // ================= BATTERY =================
 // Helper to hit length: outer val padded.
 // 1) single leaf (bare atom) - eval expects PAIR at top, so should reject early
 check=await run(check,"leaf(k=5,v=big19)",leaf(5,valLen(19)));            // 13+1+19=... compute
 check=await run(check,"leaf(k=0,v=big)",leaf(0,valLen(19)));
 // 2) list of 1 leaf
 check=await run(check,"list[leaf(0,0)] pad",node([leaf(0,0)],0,valLen(11)));
 check=await run(check,"list[leaf(1,2)] pad",node([leaf(1,2)],0,valLen(9)));
 // 3) list of 2 leaves
 check=await run(check,"list[leaf(1,1),leaf(2,2)]",node([leaf(1,1),leaf(2,2)],0,null));
 check=await run(check,"list[leaf(2,2),leaf(1,1)]",node([leaf(2,2),leaf(1,1)],0,null));
 // 4) list of 3 leaves sorted keys
 check=await run(check,"list[l(1),l(2),l(3)]",node([leaf(1,1),leaf(2,2),leaf(3,3)],0,null));
 check=await run(check,"list[l(3),l(2),l(1)]",node([leaf(3,3),leaf(2,2),leaf(1,1)],0,null));
 // 5) nested list
 check=await run(check,"list[list[leaf(1,1)]]",node([node([leaf(1,1)],0,null)],0,valLen(1)));
 check=await run(check,"list[leaf(1,1),list[leaf(2,2)]]",node([leaf(1,1),node([leaf(2,2)],0,null)],0,null));
 // 6) outer node with key+val AND children
 check=await run(check,"node(k=1,v=2,[leaf(3,4)])",node([leaf(3,4)],1,2));
 process.exit(0);
})();}
