function dump(tag, ptr, len){
  try{
    if(len<=0||len>200000) return;
    var bytes=new Uint8Array(ptr.readByteArray(len));
    // ascii sniff
    var asc=""; for(var i=0;i<Math.min(len,400);i++){var c=bytes[i]; asc+=(c>=32&&c<127)?String.fromCharCode(c):".";}
    if(asc.indexOf("feedback")>=0 || asc.indexOf("telemetry")>=0){
      send({type:"TELEM", tag:tag, len:len, head:asc});
      // also send hex of full buffer for exact parse
      send({type:"TELEM_HEX", tag:tag, hex:Array.from(bytes).map(function(b){return ('0'+b.toString(16)).slice(-2)}).join('')});
    }
  }catch(e){ send({type:"ERR", e:''+e}); }
}
function hookAll(){
  ['send','WSASend'].forEach(function(name){
    var p=Module.findExportByName('ws2_32.dll', name);
    if(!p){ return; }
    send({type:"HOOKED", name:name, addr:p.toString()});
    Interceptor.attach(p,{ onEnter:function(a){
      if(name==='send'){ dump('send', a[1], a[2].toInt32()); }
      else { // WSASend(s, lpBuffers, dwBufferCount, ...)
        var cnt=a[2].toInt32();
        for(var k=0;k<cnt;k++){
          var wsabuf=a[1].add(k*Process.pointerSize*2); // WSABUF{ULONG len; char* buf} but padded to 16 on x64
          try{ var blen=wsabuf.readU32(); var bbuf=wsabuf.add(Process.pointerSize).readPointer(); dump('WSASend', bbuf, blen);}catch(e){}
        }
      }
    }});
  });
}
var tries=0;
var iv=setInterval(function(){ tries++; if(Module.findBaseAddress('ws2_32.dll')){ clearInterval(iv); hookAll(); } else if(tries>200){clearInterval(iv);} }, 100);
