require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,U=null,D=null;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function hx(p,n){p=p>>>0;if(p<=0x1000||p+n>U.length)return'<oob>';return Buffer.from(U.subarray(p,p+n)).toString('hex');}
 function snap(label){ reb();
   const g1=q(0x20abb0); const g1s = g1>0x1000? hx(g1,72):'(null)';
   console.log(label);
   console.log("  *(0x20abb0)=0x"+g1.toString(16), "struct[0..72]="+g1s);
   console.log("  0x20ab98[16]="+hx(0x20ab98,16));
   console.log("  0x20ab50[16]="+hx(0x20ab50,16));
 }
 const go=new Go();
 go.importObject.env={trace:()=>{}}; // main_instr2 needs trace
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;go.run(instance);await new Promise(r=>setImmediate(r));
 const check=globalThis.check;
 snap("=== after init (no check) ===");
 check("AAAAAAAA"); snap("=== after check(bogus) ===");
 check(fs.readFileSync('certP.b64','utf8').trim()); snap("=== after check(certP) ===");
 check(fs.readFileSync('certP_lv1.b64','utf8').trim()); snap("=== after check(certP_lv1) ===");
 process.exit(0);
})();
