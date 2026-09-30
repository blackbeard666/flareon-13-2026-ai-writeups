const w=require('wabt'); const fs=require('fs');
w().then(wabt=>{
  const mod=wabt.readWasm(fs.readFileSync('main.wasm'), {readDebugNames:true});
  mod.applyNames();
  const {buffer}=mod.toText({foldExprs:false, inlineExport:false});
  fs.writeFileSync('main.wat', buffer);
  console.log('wat bytes:', buffer.length);
});
