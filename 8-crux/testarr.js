const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const tgt=Buffer.from([24,8,17,11,11,17,24,18,25,18,20,10,15,9,15,24,22,19,14,5,2,15,1,20,11,15,23,22,3,14,4,15,17,18,6,0,11,6,14,20,5,8]);
  function tryP(P,nm){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");const r=check(inp);if(r!=="Bad input")console.log("PASS",nm,JSON.stringify(r),"INPUT="+inp);return r;}
  // arrangements
  let P;
  P=Buffer.concat([tgt,Buffer.alloc(6)]); tryP(P,"tgt+6zero");
  P=Buffer.concat([Buffer.alloc(6),tgt]); tryP(P,"6zero+tgt");
  P=Buffer.concat([tgt,Buffer.from([42,0,0,0,0,0])]); tryP(P,"tgt+len42");
  P=Buffer.concat([tgt,Buffer.from([0,0,0,0,0,42])]); tryP(P,"tgt+len42end");
  // map digits->a-z
  const az=Buffer.from([...tgt].map(d=>0x61+d)); 
  tryP(Buffer.concat([az,Buffer.alloc(6)]),"az+6");
  tryP(Buffer.concat([az,Buffer.from([42,0,0,0,0,0])]),"az+len");
  // map digits->A-Z
  const AZ=Buffer.from([...tgt].map(d=>0x41+d));
  tryP(Buffer.concat([AZ,Buffer.alloc(6)]),"AZ+6");
  console.log("done, none passed unless shown");
  process.exit(0);
})();
