const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const tgt=[24,8,17,11,11,17,24,18,25,18,20,10,15,9,15,24,22,19,14,5,2,15,1,20,11,15,23,22,3,14,4,15,17,18,6,0,11,6,14,20,5,8];
  function tryP(P,nm){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");const r=check(inp);if(r!=="Bad input")console.log("PASS",nm,JSON.stringify(r),"INPUT="+inp);return r;}
  const low=Buffer.from(tgt.map(d=>0x61+d)); // a+d
  const up=Buffer.from(tgt.map(d=>0x41+d));
  console.log("letters:",low.toString());
  // trailers
  for(const [tn,tr] of [["zero",Buffer.alloc(6)],["len42",Buffer.from([42,0,0,0,0,0])],["42end",Buffer.from([0,0,0,0,0,42])],["spaces",Buffer.from("      ")],["nl",Buffer.from([10,10,10,10,10,10])],["pad6",Buffer.from([6,6,6,6,6,6])]]){
    tryP(Buffer.concat([low,tr]),"low+"+tn);
    tryP(Buffer.concat([up,tr]),"up+"+tn);
  }
  // reversed target
  const lowR=Buffer.from([...tgt].reverse().map(d=>0x61+d));
  tryP(Buffer.concat([lowR,Buffer.alloc(6)]),"lowRev+zero");
  console.log("done");
  process.exit(0);
})();
