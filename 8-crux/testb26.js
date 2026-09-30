const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const tgt=[24,8,17,11,11,17,24,18,25,18,20,10,15,9,15,24,22,19,14,5,2,15,1,20,11,15,23,22,3,14,4,15,17,18,6,0,11,6,14,20,5,8];
  function tryP(P,nm){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");const r=check(inp);console.log(nm,JSON.stringify(r), r!=="Bad input"?("INPUT="+inp):"");return r;}
  function toBytes(n,len,be){let b=Buffer.alloc(len);for(let i=0;i<len;i++){b[be?len-1-i:i]=Number(n&0xffn);n>>=8n;}return b;}
  for(const base of [26,27,28,29]){
    // LSB-first: tgt[0] is least significant
    let mL=0n; for(let i=tgt.length-1;i>=0;i--) mL=mL*BigInt(base)+BigInt(tgt[i]);
    // MSB-first
    let mM=0n; for(let i=0;i<tgt.length;i++) mM=mM*BigInt(base)+BigInt(tgt[i]);
    for(const [nm,m] of [["LSB",mL],["MSB",mM]]){
      const nbytes=(m.toString(16).length+1)>>1;
      tryP(toBytes(m,48,true), `base${base} ${nm} be(48) nbytes=${nbytes}`);
      tryP(toBytes(m,48,false), `base${base} ${nm} le(48)`);
    }
  }
  process.exit(0);
})();
