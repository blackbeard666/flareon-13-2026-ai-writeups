require('./wasm_exec.js');
const fs=require('fs');
async function run(file){
 let inst=null,on=false,U=null,D=null;
 let E=null, aftered=false, n3184=0;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function u32(o){return D.getUint32(o>>>0,true);}
 function u16(o){return D.getUint16(o>>>0,true);}
 function u8(o){return U[o>>>0];}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'(bad ptr '+p.toString(16)+')';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   sp=Number(sp);
   if(idx===3272 && E===null){
     E=sp;
     console.log('\n### '+file+' : func3272 ENTRY sp='+sp.toString(16));
     const A0=u32(sp+8), A1=q(sp+16), A2=u16(sp+24), A3=u8(sp+26), A4=q(sp+32);
     console.log(' A0(sp+8,u32)  =', A0.toString(16), (A0>0x1000?('  -> '+hx(A0,64)):''));
     console.log(' A1(sp+16,i64) =', A1.toString(16));
     console.log(' A2(sp+24,u16) =', A2.toString(16));
     console.log(' A3(sp+26,u8)  =', A3.toString(16));
     console.log(' A4(sp+32,i64) =', A4.toString(16), (A4>0x1000 && A4<U.length?('  -> '+hx(A4,32)):''));
     const G=q(0x20abb0);
     console.log(' G=[0x20abb0]=',G.toString(16),' off52=',u32(G+52).toString(16),' off72=',q(G+72).toString(16),' off96=',u8(G+96).toString(16),' off112=',q(G+112).toString(16),' g[0x20ab28]=',q(0x20ab28).toString(16));
   } else if(E!==null && idx===3184){
     n3184++;
     if(!aftered){ aftered=true;
       const ptr=q(E+32), len=q(E+40), cap=q(E+48);
       console.log(' OUTPUT slice: ptr='+ptr.toString(16)+' len='+len+' cap='+cap);
       if(ptr>0x1000 && len>0 && len<=256) console.log(' OUTPUT CT   = '+hx(ptr,Math.min(len,64)));
     }
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 on=true; const r=globalThis.check(fs.readFileSync(file,'utf8').trim()); on=false;
 console.log(' result:',JSON.stringify(r));
}
(async()=>{
 const files = process.argv.slice(2);
 const list = files.length?files:['certP.b64','certP_lv1.b64','certP_lv2.b64'];
 for(const f of list){ try{ await run(f); }catch(e){ console.log(f,'ERR',e.message);} }
 process.exit(0);
})();
