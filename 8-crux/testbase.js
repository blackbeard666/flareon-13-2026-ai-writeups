const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const digits=[0x18,0x8,0x11,0xb,0xb,0x11,0x18,0x12,0x19,0x12,0x14,0xa,0xf,0x9,0xf,0x18,0x16,0x13,0xe,0x5,0x2,0xf,0x1,0x14,0xb,0xf,0x17,0x16,0x3,0xe,0x4,0xf,0x11,0x12,0x6,0x0,0xb,0x6,0xe,0x14,0x5,0x8];
  function tryP(P){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");return [inp,check(inp)];}
  function toBytes(n,len,be){let b=Buffer.alloc(len);for(let i=0;i<len;i++){b[be?len-1-i:i]=Number(n&0xffn);n>>=8n;}return b;}
  for(let base=26;base<=64;base++){
    for(const rev of [false,true]){
      const dg=rev?[...digits].reverse():digits;
      let n=0n; for(const x of dg) n=n*BigInt(base)+BigInt(x);
      for(const be of [true,false]){
        const P=toBytes(n,48,be);
        const [inp,r]=tryP(P);
        if(r!=="Bad input"){console.log("PASS base="+base+" rev="+rev+" be="+be,JSON.stringify(r),"INPUT="+inp);}
      }
    }
  }
  console.log("done sweep");
  process.exit(0);
})();
