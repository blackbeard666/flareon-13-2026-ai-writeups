require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
const WASM=fs.readFileSync('main.wasm');
function mk(msg){const padlen=48-msg.length;if(padlen<1||padlen>16)return null;const p=Buffer.concat([msg,Buffer.alloc(padlen,padlen)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
const needle=Buffer.from("6239eee47f337eaf","hex");
(async()=>{
 const file=process.argv[2];
 const lines=fs.readFileSync(file,'utf8').split(/\r?\n/).filter(x=>x.trim());
 for(const raw of lines){
   const [label,hex]=raw.split(/\s+/).length>1?[raw.split(/\s+/)[0],raw.split(/\s+/).pop()]:['',raw];
   const msg=Buffer.from(hex,'hex'); const inp=mk(msg); if(!inp){console.log(label,"skip");continue;}
   const go=new Go();
   const {instance}=await WebAssembly.instantiate(WASM,go.importObject);
   go.run(instance);await new Promise(r=>setImmediate(r));
   let r; try{r=globalThis.check(inp);}catch(e){r="ERR";}
   const m=Buffer.from(instance.exports.mem.buffer);
   const hit=m.indexOf(needle)>=0;
   console.log((label||hex)+" r="+JSON.stringify(r)+(hit?"  *** POST-EVAL REACHED ***":""));
 }
 process.exit(0);
})();
