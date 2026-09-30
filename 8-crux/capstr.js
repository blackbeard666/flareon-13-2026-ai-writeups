// Capture decoded strings: hook func3270 entry to record its base sp, then after it returns
// dump the whole memory and scan the region around 0x3688a0 and heap for readable strings created during check.
require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkMsg(M){const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(true);return Buffer.concat([c.update(M),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();let inst=null;
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 // snapshot heap before
 const before=Buffer.from(inst.exports.mem.buffer.slice(0));
 check(mkMsg(Buffer.from("A".repeat(32))));
 const after=Buffer.from(inst.exports.mem.buffer);
 // find ascii runs that are NEW or changed (present in after)
 const found=new Set();
 for(let i=0x100000;i<after.length;i++){
   let j=i;while(j<after.length&&after[j]>=32&&after[j]<127)j++;
   if(j-i>=6){const s=after.slice(i,j).toString('latin1');
     if(/[a-z]/.test(s)&&/ |!|\./.test(s)) found.add(s);
     i=j;} else i++;
 }
 const arr=[...found].filter(s=>!/runtime|reflect|abi|internal|crypto|GODEBUG|goroutine|\bgc\b|struct \{|interface \{|go\.shape|sync\.|maps\.|syscall|Punctuat|Number\./.test(s));
 fs.writeFileSync('newstrings.txt',arr.join('\n'));
 console.log("candidate messages:",arr.length);
 console.log(arr.filter(s=>s.length<50).join('\n'));
 process.exit(0);
})();
