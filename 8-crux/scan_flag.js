require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 const go=new Go();
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main.wasm'),go.importObject);
 go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 const DV0=new DataView(instance.exports.mem.buffer);
 console.log("0x20aba0 initial=0x"+DV0.getBigUint64(0x20aba0,true).toString(16));
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}
 console.log("result="+JSON.stringify(r));
 const U8=new Uint8Array(instance.exports.mem.buffer);
 // scan for printable runs containing @ or flare or - between letters
 const hay=Buffer.from(U8); const s=hay.toString('latin1');
 const re=/[\x20-\x7e]{8,}/g; let m; const hits=[];
 while((m=re.exec(s))){const t=m[0];if(/@|flare|_20|on\.com|\.com/i.test(t)&&!/runtime|golang|\.go|GOROOT|http|reflect|cpu|sync|gc |mheap|span/i.test(t))hits.push(t);}
 console.log("candidate strings:",hits.length);hits.slice(0,20).forEach(h=>console.log('  '+h.slice(0,80)));
 process.exit(0);
})();
