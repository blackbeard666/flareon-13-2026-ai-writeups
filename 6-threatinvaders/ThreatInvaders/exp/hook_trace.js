var SF = ptr("SF_ADDR");   // SetFeedback(string)
var BD = ptr("BD_ADDR");   // BuildDocument(int, byte[])
function dnStr(p){ try{ if(p.isNull())return "<null>"; var l=p.add(8).readS32(); if(l<0||l>100000)return "<l"+l+">"; return p.add(0xC).readUtf16String(Math.min(l,80)); }catch(e){return "<e>";} }
function arrLen(p){ try{ if(p.isNull())return -1; return p.add(8).readS32(); }catch(e){return -2;} }
function arrHead(p,n){ try{ if(p.isNull())return ""; var l=p.add(8).readS32(); n=Math.min(n,l); var b=new Uint8Array(p.add(0x10).readByteArray(n)); return Array.from(b).map(function(x){return ('0'+x.toString(16)).slice(-2)}).join(''); }catch(e){return "<e>";} }
if(!SF.isNull()) Interceptor.attach(SF,{ onEnter:function(a){
  var s=dnStr(a[1]);
  var bt=Thread.backtrace(this.context, Backtracer.FUZZY).slice(0,8).map(function(x){return x.toString();});
  send({t:"SetFeedback", textLen:(a[1].isNull()?-1:a[1].add(8).readS32()), text:s, bt:bt});
}});
if(!BD.isNull()) Interceptor.attach(BD,{ onEnter:function(a){
  // BuildDocument(this=rcx, gamesPlayed=edx, feedback=r8)
  send({t:"BuildDocument", feedbackLen: arrLen(a[2]), feedbackHead: arrHead(a[2],32)});
}});
send({t:"READY"});
