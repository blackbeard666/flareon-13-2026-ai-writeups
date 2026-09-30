require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const pat=Buffer.from("42bbe6f1c10051450440","hex");
const needle=Buffer.from("6239eee47f337eaf","hex");
(async()=>{
 const base=fs.readFileSync('main_instr2.wasm');
 // find all occurrences
 const idxs=[];let i=base.indexOf(pat);while(i>=0){idxs.push(i);i=base.indexOf(pat,i+1);}
 console.log("pattern occurrences:",idxs.map(x=>x.toString(16)));
 const which=parseInt(process.argv[3]||"1"); // which occurrence to patch (0-based); default 2nd(element check)
 const buf=Buffer.from(base);
 if(idxs[which]!==undefined){ buf[idxs[which]+6]=0x52; console.log("patched occurrence",which,"at 0x"+idxs[which].toString(16),"byte->0x52 (i64.ne)"); }
 let inst=null;let on=false;let seen=null;
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; if(idx===3251||idx===3254||idx===3256){const m=Buffer.from(inst.exports.mem.buffer);const p=m.indexOf(needle);if(p>=0&&!seen)seen={at:p.toString(16),region:m.slice(p-40,p+40).toString('hex')};} }};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2]||"01010000000d0000000100000000000000000000000000000000020000000101","hex");
 on=true;let r;try{r=check(mk(msg));}catch(e){r="ERR:"+e.message;}on=false;
 const m=Buffer.from(instance.exports.mem.buffer);
 console.log("msg="+msg.toString('hex'),"r="+JSON.stringify(r));
 console.log("post-eval reached (during):", seen?JSON.stringify(seen):"NO");
 let all=[],p=m.indexOf(needle);while(p>=0){all.push(p.toString(16));p=m.indexOf(needle,p+1);}
 console.log("const in final mem:",all.length, all[0]||"");
 if(all.length){const q=parseInt(all[0],16);console.log("  decoded-region:",m.slice(q-8,q+56).toString('hex'));}
 process.exit(0);
})();
