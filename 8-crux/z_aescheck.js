const crypto=require('crypto');
const key=Buffer.from("a1c0cf649ab8c16f8ade1d226bd804884463fc7afc0f134d652202a04606e3b9","hex");
const ct=Buffer.from("78b95d284fb5a232df1ccc908e10fe1a2d7faa97cc43c2797087f03ad311c512997cd0e4fb72ca3072c3e2ad0de6232f","hex");
const target="b757e1cbcc569f8b53eb945b80e071e70eb472130b29a720a745a75b08f08b823a1239202e323fdececcf513f0928e54";
function tryd(mode,iv){try{const d=crypto.createDecipheriv(mode,key,iv);d.setAutoPadding(false);const o=Buffer.concat([d.update(ct),d.final()]);return o.toString('hex');}catch(e){return 'ERR '+e.message;}}
const zero=Buffer.alloc(16,0);
console.log("target      :",target);
console.log("ECB dec     :",tryd('aes-256-ecb',null));
console.log("CBC iv=0 dec :",tryd('aes-256-cbc',zero));
// try iv = first 16 bytes of stage1 iv
console.log("CBC iv=5ff2 :",tryd('aes-256-cbc',Buffer.from("5ff26040c4c20b9f2ffdefa7ecf65d91","hex")));
// encrypt directions
function trye(mode,iv){try{const c=crypto.createCipheriv(mode,key,iv);c.setAutoPadding(false);const o=Buffer.concat([c.update(ct),c.final()]);return o.toString('hex');}catch(e){return 'ERR '+e.message;}}
console.log("ECB enc(ct) :",trye('aes-256-ecb',null));
