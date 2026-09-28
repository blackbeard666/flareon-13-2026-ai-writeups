var base=Module.findBaseAddress("ThreatInvaders.exe");
function hexrd(rva,n){var b=new Uint8Array(base.add(rva).readByteArray(n));return Array.from(b).map(function(x){return('0'+x.toString(16)).slice(-2)}).join('');}
function dnStr(p){try{if(p.isNull())return"";var l=p.add(8).readS32();if(l<0||l>200)return"";return p.add(0xC).readUtf16String(l);}catch(e){return"";}}
// hook UploadTelemetryAsync via arg to get JSON, and read tableA/tableB at that time
send({t:"tableA",hex:hexrd(0x7FF800,16)});
send({t:"tableB",hex:hexrd(0x7FFA30,16)});
send({t:"READY"});
