require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mkFromMsg(msg){const padlen=48-msg.length;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
function scan(after){const found=new Set();for(let i=0x100000;i<after.length;i++){let j=i;while(j<after.length&&after[j]>=32&&after[j]<127)j++;if(j-i>=5){const s=after.slice(i,j).toString('latin1');if(/[a-z]/.test(s))found.add(s);i=j;}else i++;}return found;}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 // baseline with failing input
 check(mkFromMsg(Buffer.from("41".repeat(32),"hex")));
 const base=scan(Buffer.from(instance.exports.mem.buffer));
 // valid tree
 const msg=Buffer.from("01010000000f000000010000000001000000020100000001010000000100000000","hex");
 check(mkFromMsg(msg));
 const now=scan(Buffer.from(instance.exports.mem.buffer));
 const neu=[...now].filter(s=>!base.has(s));
 console.log("NEW strings on valid-tree run:",neu.length);
 for(const s of neu.filter(s=>!/runtime|reflect|abi|GODEBUG|goroutine|struct \{|interface \{|go\.shape|internal|crypto\/|maps\.|sync\.|syscall/.test(s)).slice(0,80)) console.log("  "+JSON.stringify(s));
 process.exit(0);
})();
