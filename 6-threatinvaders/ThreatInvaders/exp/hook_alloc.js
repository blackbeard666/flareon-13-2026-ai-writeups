var BD = ptr("BD_ADDR");
// find the 'new byte[4096]' alloc call: E8 rel32 at ~+0x56
var code=new Uint8Array(BD.readByteArray(0x70));
var allocTgt=null;
for(var i=0x40;i<0x60;i++){ if(code[i]==0xE8){ var rel=BD.add(i+1).readS32(); allocTgt=BD.add(i+5).add(rel); break; } }
send({t:"alloc", addr: allocTgt? allocTgt.toString():"none"});
if(allocTgt){
  Interceptor.attach(allocTgt,{ onEnter:function(a){
    var cnt=a[1].toInt32();
    if(cnt===600){  // updater output length in our test
      var bt=Thread.backtrace(this.context, Backtracer.ACCURATE).slice(0,12).map(function(x){
        var s=DebugSymbol.fromAddress(x); return x.toString()+(s&&s.name?(" "+s.moduleName+"!"+s.name):"");});
      send({t:"alloc600", bt:bt});
    }
  }});
}
send({t:"READY"});
