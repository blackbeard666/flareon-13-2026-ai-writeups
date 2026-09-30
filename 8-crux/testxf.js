const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go();
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  const tgt=[24,8,17,11,11,17,24,18,25,18,20,10,15,9,15,24,22,19,14,5,2,15,1,20,11,15,23,22,3,14,4,15,17,18,6,0,11,6,14,20,5,8];
  const sboxHex="637c777bf26b6fc53001672bfed7ab76ca82c97dfa5947f0add4a2af9ca472c0b7fd9326363ff7cc34a5e5f171d8311504c723c31896059a071280e2eb27b27509832c1a1b6e5aa0523bd6b329e32f8453d100ed20fcb15b6acbbe394a4c58cfd0efaafb434d338545f9027f503c9fa851a3408f929d38f5bcb6da2110fff3d2cd0c13ec5f974417c4a77e3d645d197360814fdc222a908846eeb814de5e0bdbe0323a0a4906245cc2d3ac629195e479e7c8376d8dd54ea96c56f4ea657aae08ba78252e1ca6b4c6e8dd741f4bbd8b8a703eb5664803f60e613557b986c11d9ee1f8981169d98e949b1e87e9ce5528df8ca1890dbfe6426841992d0fb054bb16";
  const sbox=Buffer.from(sboxHex,"hex"); const inv=Buffer.alloc(256); for(let i=0;i<256;i++)inv[sbox[i]]=i;
  function tryP(bytes,nm){const P=Buffer.alloc(48);for(let i=0;i<bytes.length&&i<48;i++)P[i]=bytes[i];const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");const r=check(inp);if(r!=="Bad input")console.log("PASS",nm,JSON.stringify(r),inp);return r;}
  tryP(tgt.map(d=>sbox[d]),"sbox[t]");
  tryP(tgt.map(d=>inv[d]),"inv[t]");
  tryP(tgt.map(d=>d^0x60),"t^60");
  tryP(tgt.map(d=>0x60+d),"0x60+t");
  tryP(tgt.map(d=>0x40+d),"0x40+t");
  // with trailer length
  for(const [nm,fn] of [["sbox",d=>sbox[d]],["inv",d=>inv[d]],["A+",d=>0x41+d],["a+",d=>0x61+d]]){
    const b=tgt.map(fn); const P=Buffer.alloc(48); for(let i=0;i<42;i++)P[i]=b[i]; P[47]=42;
    const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");
    if(check(inp)!=="Bad input")console.log("PASS-trailer",nm,inp);
  }
  console.log("done");
  process.exit(0);
})();
