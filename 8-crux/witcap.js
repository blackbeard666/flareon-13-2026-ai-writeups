require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
 let inst=null,on=false,U=null,D=null,caps=[],lim=60;
 function reb(){U=new Uint8Array(inst.exports.mem.buffer);D=new DataView(inst.exports.mem.buffer);}
 function q(o){o=o>>>0;return D.getUint32(o,true)+D.getUint32(o+4,true)*4294967296;}
 function rI(p){p=p>>>0;if(p<=0x1000||p+24>U.length)return null;const neg=U[p];const ptr=q(p+8),len=q(p+16);if(ptr<=0x1000||len<0||len>1024||ptr+len>U.length)return null;let v=0n;for(let i=len-1;i>=0;i--)v=(v<<8n)|BigInt(U[ptr+i]);return neg?-v:v;}
 const go=new Go();
 go.importObject.env={trace:(idx,sp)=>{ if(!on)return; if(U.buffer!==inst.exports.mem.buffer)reb();
   if(idx===3262 && caps.length<lim){ // modexp base@+8, exp@+16, mod@+24
     const b=rI(q(Number(sp)+8)), e=rI(q(Number(sp)+16)), m=rI(q(Number(sp)+24));
     caps.push([b===null?'?':b.toString(), e===null?'?':e.toString(), m===null?'?':m.toString()]);
   }
 }};
 const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_instr2.wasm'),go.importObject);
 inst=instance;reb();go.run(instance);await new Promise(r=>setImmediate(r));reb();
 const check=globalThis.check;
 on=true; check(fs.readFileSync('certP.b64','utf8').trim()); on=false;
 console.log("first",caps.length,"modexp(base,exp,mod):");
 for(const c of caps) console.log("  base="+c[0]+" exp="+c[1]+" mod="+c[2]);
 process.exit(0);
})();
