require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,D=null,U=null,rec={};
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hexAt(p,n){p=p>>>0; if(p<0x1000||p+n>U.length)return null; return Buffer.from(U.slice(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   sp=Number(sp)>>>0; const ret=q(sp)>>>0; const f=sp+8;
   // 3184 NewCipher @6b8b: retaddr 0x1cb2056a
   if(idx===3184 && ret===0x1cb2056a){ rec.keyptr=q(f+0); rec.keylen=q(f+8); rec.key=hexAt(q(f+0),q(f+8)); }
   // 3272 @6b0a: retaddr 0x1cb20568 -> its result read later; capture its ARG frame
   if(idx===3272 && ret===0x1cb20568){ rec.f3272_args=[0,8,16,24,32].map(o=>'0x'+q(f+o).toString(16)); }
   // 3166 NewCBCDecrypter @6c96: retaddr 0x1cb2056f
   if(idx===3166 && ret===0x1cb2056f){ rec.f3166_args=[0,8,16,24,32].map(o=>'0x'+q(f+o).toString(16));
     // arg8=iv? arg0=block,arg8=? Try read 16 bytes at each ptr
     rec.f3166_iv_try=hexAt(q(f+16),16); rec.f3166_a1=hexAt(q(f+8),16);}
   // 3190 @6dc4: retaddr 0x1cb20577  (the validation/decrypt)
   if(idx===3190 && ret===0x1cb20577){ rec.f3190_6dc4_args=[0,8,16,24].map(o=>'0x'+q(f+o).toString(16));
     rec.f3190_dst=hexAt(q(f+0),64); rec.f3190_off56_entry='0x'+q(f+56).toString(16);}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim()); on=false;
 console.log('result=',JSON.stringify(r));
 console.log(JSON.stringify(rec,null,1));
 process.exit(0);
})();
