require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null,aesN=0,off56=null,win=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3190){ aesN++; if(aesN===2){ sp=Number(sp); off56=q(sp+64); win=[]; for(let o=48;o<=88;o+=8) win.push('sp+'+o+'=0x'+q(sp+o).toString(16)); } }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 return {off56:off56!=null?'0x'+off56.toString(16):null, win};
}
(async()=>{ for(const f of ['certP.b64','certP_lv1.b64','cand_180.b64','cand_306.b64']){ const x=await run(f); console.log(f,"off56(sp+64)=",x.off56); if(x.win)console.log("   window:",x.win.join(' ')); } process.exit(0); })();
