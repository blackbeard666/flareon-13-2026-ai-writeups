require('./wasm_exec.js');
const fs=require('fs'),crypto=require('crypto');
const key=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
const iv=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
function mk(m){let total=Math.ceil((m.length+1)/16)*16;const pl=total-m.length;const p=Buffer.concat([m,Buffer.alloc(pl,pl)]);const c=crypto.createCipheriv('aes-256-cbc',key,iv);c.setAutoPadding(false);return Buffer.concat([c.update(p),c.final()]).toString('base64');}
(async()=>{
 let inst=null,DV=null,U8=null,on=false,snaps=[];
 function reb(){U8=new Uint8Array(inst.exports.mem.buffer);DV=new DataView(inst.exports.mem.buffer);}
 function q(o){o=Number(o);return DV.getBigUint64(o,true);}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on||!inst)return; reb();
   if(idx===3190){ // dump args pointers and scan for ascii
     let ptrs=[];for(let o=8;o<=48;o+=8){ptrs.push(Number(q(sp+o)));}
     snaps.push({sp:Number(sp),ptrs});
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 const msg=Buffer.from(process.argv[2].trim(),'hex');
 on=true;let r;try{r=check(mk(msg));}catch(e){r='ERR:'+e.message;}on=false;
 reb();
 console.log("result="+JSON.stringify(r)+" AEScalls="+snaps.length);
 // scan whole memory for flare-on
 const hay=Buffer.from(U8);
 for(const pat of ['flare-on','@flare','flag','FLARE']){let i=hay.indexOf(pat);while(i>=0){console.log('found "'+pat+'" @0x'+i.toString(16)+': '+hay.slice(i-4,i+40).toString('latin1').replace(/[^\x20-\x7e]/g,'.'));i=hay.indexOf(pat,i+1);if(i>hay.length)break;}}
 process.exit(0);
})();
