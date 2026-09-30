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
  function encIn(P){const c=crypto.createCipheriv("aes-256-cbc",k1,IV);c.setAutoPadding(false);return Buffer.concat([c.update(P),c.final()]).toString("base64");}
  function work(P){cnt=0;const r=check(encIn(P));return [cnt,r];}
  let P=Buffer.alloc(48);
  for(let i=47;i>=0;i--){
    let best=-1,bestw=-1,ties=[];
    for(let x=0;x<256;x++){P[i]=x;const [w,r]=work(P); if(r!=="Bad input")console.log("PASS i="+i+" x="+x+" "+JSON.stringify(r)); if(w>bestw){bestw=w;best=x;ties=[x];}else if(w===bestw)ties.push(x);}
    P[i]=best;
    console.log("byte",i,"=0x"+best.toString(16),"work="+bestw,"ties="+ties.length,ties.length<=16?ties.map(t=>t.toString(16)).join(","):"");
  }
  const [w,r]=work(P);
  console.log("P=",P.toString("hex"),"result",JSON.stringify(r),"work",w);
  console.log("INPUT=",encIn(P));
  process.exit(0);
})();
