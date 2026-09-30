const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  function tryP(P){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");return [inp, check(inp)];}
  const digits=[0x18,0x8,0x11,0xb,0xb,0x11,0x18,0x12,0x19,0x12,0x14,0xa,0xf,0x9,0xf,0x18,0x16,0x13,0xe,0x5,0x2,0xf,0x1,0x14,0xb,0xf,0x17,0x16,0x3,0xe,0x4,0xf,0x11,0x12,0x6,0x0,0xb,0x6,0xe,0x14,0x5,0x8];
  function numFrom(dig, base){ let n=0n; for(const d of dig) n=n*BigInt(base)+BigInt(d); return n; }
  function toBytes(n, len, be){ let b=Buffer.alloc(len); for(let i=0;i<len;i++){ b[be?(len-1-i):i]=Number(n&0xffn); n>>=8n; } return b; }
  for(const base of [29]){
    for(const rev of [false,true]){
      const dg = rev? [...digits].reverse():digits;
      const n = numFrom(dg, base);
      for(const be of [true,false]){
        const P = toBytes(n, 48, be);
        const [inp,r]=tryP(P);
        console.log(`base${base} rev=${rev} be=${be}: `,JSON.stringify(r), r!=="Bad input"?("INPUT="+inp):"");
      }
    }
  }
  // also: plaintext = raw digit bytes + padding variants
  for(const len of [42,8,16,2]){
    const P=Buffer.alloc(48); for(let i=0;i<42;i++)P[i]=digits[i]; P[47]=len;
    const [inp,r]=tryP(P); console.log("rawdigits len="+len, JSON.stringify(r));
  }
  process.exit(0);
})();
