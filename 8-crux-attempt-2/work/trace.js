const fs=require('fs');globalThis.window=globalThis;
require('../ext/x/wasm_exec.js');
const names={};for(const [k,e,s] of JSON.parse(fs.readFileSync(__dirname+'/funcs.json')))names[k+20]=s;
const wasm=process.env.WASM||(__dirname+'/i.wasm');
let pending=null,depth=0,log=[],mem;const DUMP=+(process.env.DUMP||48);
const hex=(a,n)=>{const b=Buffer.from(mem.buffer,a,n);let r=b.toString('hex');const dv=new DataView(mem.buffer);let ex=[];
for(let o=0;o+16<=n;o+=8){const p=Number(dv.getBigUint64(a+o,true)),l=Number(dv.getBigUint64(a+o+8,true));if(p>0x1000&&p<mem.buffer.byteLength&&l>0&&l<=200){const t=Buffer.from(mem.buffer,p,l);const pr=[...t].filter(c=>c>=32&&c<127).length;ex.push(pr>=l*0.9?`[${o}]"${t.toString('latin1')}"`:`[${o}]x${t.toString('hex')}`);}}
return r+(ex.length?'  '+ex.join(' '):'');};
function onHook(v){
  if(v<0x80000000){const sp=v&~1;const [tag]=pending;const fi=(tag&0xffff)>>1;const exit=(tag>>>30)==3;
    const dv=new DataView(mem.buffer);
    if(!exit){const BIG={3254:2,3258:2,3257:2,3256:2,3253:2,3259:2,3260:2,3261:3,3262:3,3268:2,3255:2,3263:2,3265:2};let bs='';if(BIG[fi]){for(let k=0;k<BIG[fi];k++){const p=Number(dv.getBigUint64(sp+8+8*k,true));if(p>0&&p<mem.buffer.byteLength-32){const neg=dv.getUint8(p);const dp=Number(dv.getBigUint64(p+8,true)),dl=Number(dv.getBigUint64(p+16,true));if(dl<4096&&dp+dl<=mem.buffer.byteLength){const b=Buffer.from(mem.buffer,dp,dl);bs+=' big'+k+'='+(neg?'-':'')+'0x'+(Buffer.from(b).reverse().toString('hex')||'0');}}}}log.push(bs+`${' '.repeat(depth)}> ${fi} ${names[fi]||''} sp=${sp.toString(16)} args=${hex(sp+8,DUMP)}`);depth++;}
    else{depth--;log.push(`${' '.repeat(Math.max(depth,0))}< ${fi} ${hex(sp+8,DUMP)}`);}
  } else pending=[v>>>0];
}
(async()=>{const go=new Go();const io=go.importObject;const orig=io.gojs['runtime.getRandomData'];
io.gojs['runtime.getRandomData']=(sp)=>{sp>>>=0; if(sp&1||sp>=0x80000000){onHook(sp);return;} orig(sp);};
const {instance}=await WebAssembly.instantiate(fs.readFileSync(wasm),io);mem=instance.exports.mem;go.run(instance);
setTimeout(()=>{log=[];for(const a of process.argv.slice(2)){log.push('INPUT '+JSON.stringify(a));const r=globalThis.check(a);log.push('RESULT '+r);}
fs.writeFileSync(process.env.OUT||(__dirname+'/trace.txt'),log.join('\n'));console.log(log.length,'lines');process.exit(0)},100);})();
