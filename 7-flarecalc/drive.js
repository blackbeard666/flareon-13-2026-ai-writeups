function hh(p,n){try{return Array.from(new Uint8Array(p.readByteArray(n))).map(x=>('0'+x.toString(16)).slice(-2)).join('')}catch(e){return '<e>'}}
function asc(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<n;i++)s+=(b[i]>=32&&b[i]<127)?String.fromCharCode(b[i]):'.';return s;}catch(e){return'<e>'}}
var vp=Module.findExportByName('KERNEL32.dll','VirtualProtect')||Module.findExportByName('kernelbase.dll','VirtualProtect');
Interceptor.attach(vp,{onEnter:function(a){var np=a[2].toInt32(); if(np&0xf0){ this.addr=a[0]; this.sz=a[1].toInt32(); this.exec=true;} },
  onLeave:function(r){ if(this.exec){ send({t:'VP',addr:this.addr.toString(),size:this.sz,ascii:asc(this.addr,Math.min(this.sz,160)),hex:hh(this.addr,64)}); } }});
Interceptor.attach(Module.findExportByName('USER32.dll','SetWindowTextW'),{onEnter:function(a){try{send({t:'SWTW',s:a[1].readUtf16String()});}catch(e){}}});
Interceptor.attach(Module.findExportByName('USER32.dll','SetWindowTextA'),{onEnter:function(a){try{send({t:'SWTA',s:a[1].readAnsiString()});}catch(e){}}});
send({t:'READY'});
