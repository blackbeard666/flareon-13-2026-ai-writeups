require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,D=null,U=null,aesN=0,out=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3190){ aesN++; if(aesN===2){ sp=Number(sp)>>>0; const f=sp+8;
     const decptr=q(f+664),declen=q(f+552),deccap=q(f+560);
     const buf752=q(f+752);
     const off56=q(f+56),off64=q(f+64);
     let dec=null;
     if(decptr>0x1000&&declen>0&&declen<4096&&decptr+declen<=U.length) dec=Buffer.from(U.slice(decptr,decptr+declen));
     let b752=null; if(buf752>0x1000&&buf752+64<=U.length) b752=Buffer.from(U.slice(buf752,buf752+64));
     out={declen,deccap,decptr:'0x'+decptr.toString(16),
          dec_ascii:dec?dec.toString('latin1'):null,
          dec_hex:dec?dec.toString('hex'):null,
          buf752_hex:b752?b752.toString('hex'):null,
          off56:'0x'+off56.toString(16),off64:'0x'+off64.toString(16)};
   }}
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync(process.argv[2]||'certP.b64','utf8').trim()); on=false;
 console.log('result=',JSON.stringify(r));
 console.log(JSON.stringify(out,null,1));
 process.exit(0);
})();
