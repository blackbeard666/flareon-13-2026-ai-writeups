require('./wasm_exec.js');
const fs=require('fs');
(async()=>{
  const go=new Go();
  const ev=[];
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.log32=(kind,a,b)=>{ ev.push([kind,a>>>0,b>>>0]); };
  go.importObject.env.log64=(kind,a,b)=>{ ev.push([kind, BigInt.asUintN(64,a), BigInt.asUintN(64,b)]); };
  const {instance}=await WebAssembly.instantiate(fs.readFileSync('main_cmp.wasm'),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const inp=process.argv[2]||Buffer.from(Array.from({length:48},(_,i)=>i)).toString('base64');
  console.log("INPUT:",JSON.stringify(inp),"len",inp.length);
  ev.length=0;
  const res=check(inp);
  console.log("RESULT:",JSON.stringify(res));
  console.log("NEVENTS:",ev.length);
  const kindname={1:'eqz32',2:'eq32',3:'ne32',4:'eqz64',5:'eq64',6:'ne64',7:'ltu64',8:'gtu64',9:'leu64',10:'geu64'};
  const lines=ev.map((e,i)=>{
    const [k,a,b]=e;
    const eq = (a===b)||(String(a)===String(b));
    return `${i} ${kindname[k]} a=${typeof a==='bigint'?('0x'+a.toString(16)):('0x'+a.toString(16))} b=${typeof b==='bigint'?('0x'+b.toString(16)):('0x'+b.toString(16))} ${eq?'==':'!='}`;
  });
  fs.writeFileSync('cmp_events.txt', lines.join('\n'));
  console.log("wrote cmp_events.txt");
  // print last 40
  console.log(lines.slice(-40).join('\n'));
  process.exit(0);
})();
