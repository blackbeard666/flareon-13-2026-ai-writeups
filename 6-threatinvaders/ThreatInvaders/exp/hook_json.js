var addrStr = "ADDR_PLACEHOLDER";
var target = ptr(addrStr);
function readDotNetString(p){
  try{
    if(p.isNull()) return "<null>";
    var len = p.add(8).readS32();
    if(len<0||len>100000) return "<len "+len+">";
    return p.add(0xC).readUtf16String(len);
  }catch(e){ return "<err "+e+">"; }
}
Interceptor.attach(target, { onEnter: function(a){
  // UploadTelemetryAsync(this=rcx, json=rdx, ct=r8)
  var json = readDotNetString(a[1]);
  if(json && json.indexOf("feedback")>=0){
    send({t:"JSON", s: json.length>600? json.slice(0,120)+" ... "+json.slice(-80) : json});
  }
}});
send({t:"READY", addr: addrStr});
