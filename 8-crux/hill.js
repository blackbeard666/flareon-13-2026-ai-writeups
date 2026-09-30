const fs=require("fs"); require("./wasm_exec.js"); const crypto=require("crypto");
(async()=>{
  const go=new Go(); let cnt=0;
  go.importObject.env=go.importObject.env||{};
  go.importObject.env.log32=()=>{cnt++;}; go.importObject.env.log64=()=>{cnt++;};
  const {instance}=await WebAssembly.instantiate(fs.readFileSync("main_cmp.wasm"),go.importObject);
  go.run(instance); await new Promise(r=>setImmediate(r));
  const check=globalThis.check;
  const k1=Buffer.from("cabeba7ad156801d1c82381c7cb8a3c406ae2c3cd168a96cd8373684cdbf8723","hex");
  const IV=Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex");
  function ev(P){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);const inp=Buffer.concat([c.update(P),c.final()]).toString("base64");cnt=0;const r=check(inp);return [cnt,r,inp];}
  let P=Buffer.alloc(48);
  for(let pass=0;pass<3;pass++){
    let improved=false;
    for(let i=0;i<48;i++){
      let best=P[i],bw=-1;
      for(let x=0;x<256;x++){P[i]=x;const [w,r]=ev(P);if(r!=="Bad input"){console.log("PASS!",ev(P)[2]);process.exit(0);}if(w>bw){bw=w;best=x;}}
      if(P[i]!==best)improved=true;
      P[i]=best;
    }
    console.log("pass",pass,"P=",P.toString("hex"),"work=",ev(P)[0]);
    if(!improved)break;
  }
  console.log("final",P.toString("hex"),JSON.stringify(ev(P)[1]));
  process.exit(0);
})();
