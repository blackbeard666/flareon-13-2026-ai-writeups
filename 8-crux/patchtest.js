require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}

const pat=Buffer.from("a729030050ad50044041f006","hex"); // ...50 ad 50 04 40 41 f0 06
async function runVariant(name, repl){
 const base=fs.readFileSync('main_instr.wasm');
 const idx=base.indexOf(pat);
 if(idx<0){console.log(name,"pattern not found");return;}
 const buf=Buffer.from(base);
 if(repl){ // repl is 3 bytes to replace the '50 ad 50' at idx+4
   buf[idx+4]=repl[0];buf[idx+5]=repl[1];buf[idx+6]=repl[2];
 }
 const go=new Go();let on=false;const cnt={};
 go.importObject.env={trace:(i)=>{ if(on) cnt[i]=(cnt[i]||0)+1; }};
 const {instance}=await WebAssembly.instantiate(buf,go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 on=true;const r=check(mkMsg(Buffer.from("A".repeat(32))));on=false;
 const watch=[3267,3269,3251,3252,3254,3272,2992,3242];
 console.log(name,"patternIdx=0x"+idx.toString(16),"result="+JSON.stringify(r));
 console.log("   ",watch.map(w=>w+":"+(cnt[w]||0)).join(" "));
}
(async()=>{
 await runVariant("ORIGINAL   ", null);
 await runVariant("FORCE-880  ", [0x1a,0x41,0x01]); // drop; i32.const 1 -> always take 880
 await runVariant("FORCE-FALL ", [0x1a,0x41,0x00]); // drop; i32.const 0 -> always fall through to 3269
 process.exit(0);
})();
