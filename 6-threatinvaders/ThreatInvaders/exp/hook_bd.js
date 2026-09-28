var BD = ptr("BD_ADDR");
function dnStrTail(p){ try{ if(p.isNull())return "<null>"; var l=p.add(8).readS32(); if(l<0||l>200000)return "<l>"; var start=Math.max(0,l-40); return p.add(0xC+start*2).readUtf16String(l-start);}catch(e){return "<e>";} }
Interceptor.attach(BD,{
  onEnter:function(a){ this.flen = a[2].isNull()? -1 : a[2].add(8).readS32();
     this.fhead = a[2].isNull()? "" : Array.from(new Uint8Array(a[2].add(0x10).readByteArray(8))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join(''); },
  onLeave:function(r){ send({t:"BD", inLen:this.flen, inHead:this.fhead, jsonTail: dnStrTail(r)}); }
});
send({t:"READY"});
