const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const tgt=[24,8,17,11,11,17,24,18,25,18,20,10,15,9,15,24,22,19,14,5,2,15,1,20,11,15,23,22,3,14,4,15,17,18,6,0,11,6,14,20,5,8];
  function tryRaw(P,nm){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");const r=check(inp);if(r!=="Bad input"){console.log("PASS!!!",nm,JSON.stringify(r),"INPUT="+inp);return true;}return false;}
  const trailers=[];
  for(let L=0;L<48;L++){const t=Buffer.alloc(6);t[5]=L;trailers.push(["end"+L,t]);const t2=Buffer.alloc(6);t2[0]=L;trailers.push(["st"+L,t2]);}
  trailers.push(["z",Buffer.alloc(6)]);
  // mapping functions
  const maps={
    id:d=>d, aLow:d=>0x61+d, aUp:d=>0x41+d,
  };
  for(let off=0;off<128;off++) maps["off"+off]=d=>(off+d)&0xff;
  for(let x=0;x<256;x++) maps["xor"+x]=d=>d^x;
  for(const rev of [false,true]){
    const T=rev?[...tgt].reverse():tgt;
    for(const mn in maps){
      const body=Buffer.from(T.map(maps[mn]));
      // try as full 42 + trailer, and check length 42 or 48
      for(const [tn,tr] of [["z6",Buffer.alloc(6)],["len42end",Buffer.from([0,0,0,0,0,42])],["len42st",Buffer.from([42,0,0,0,0,0])]]){
        if(tryRaw(Buffer.concat([body,tr]),"rev"+rev+" "+mn+" "+tn)) {process.exit(0);}
      }
    }
  }
  console.log("done none");
  process.exit(0);
})();
