require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  let tracing=false; let inst=null; const caps=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.trace=(idx)=>{
    if(!tracing||!inst) return;
    if(idx===3187){
      let sp=-1; try{ sp=inst.exports.g0(); }catch(e){ sp=-2; }
      const m=Buffer.from(inst.exports.mem.buffer);
      caps.push([sp, Buffer.from(m)]);
    }
  };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_g0.wasm'),go.importObject);
  inst=instance;
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const inb=Buffer.from(process.argv[2],'hex');
  tracing=true; check(inb.toString('base64')); tracing=false;
  console.log("captures",caps.length);
  caps.forEach(([sp,m],i)=>{
    if(sp<0){console.log('sp err',sp);return;}
    const recv=Number(m.readBigUInt64LE(sp+144));
    const srcp=Number(m.readBigUInt64LE(sp+152));
    const dstp=Number(m.readBigUInt64LE(sp+176));
    console.log(`cap${i} sp=${sp.toString(16)} recv=${recv.toString(16)} src=${srcp.toString(16)} dst=${dstp.toString(16)}`);
    console.log(`   src16=`, m.slice(srcp,srcp+16).toString('hex'));
    console.log(`   recv+0 (240B rk) first32=`, m.slice(recv,recv+32).toString('hex'));
    fs.writeFileSync(`rk_cap${i}.bin`, m.slice(recv, recv+512));
  });
  process.exit(0);
})();
