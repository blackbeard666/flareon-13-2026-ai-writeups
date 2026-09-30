function hh(p,n){try{return Array.from(new Uint8Array(p.readByteArray(n))).map(x=>('0'+x.toString(16)).slice(-2)).join('')}catch(e){return '<e>'}}
function asc(p,n){try{var b=new Uint8Array(p.readByteArray(n));var s='';for(var i=0;i<n;i++)s+=(b[i]>=32&&b[i]<127)?String.fromCharCode(b[i]):'.';return s;}catch(e){return'<e>'}}
function H(dll,fn,cb){var p=Module.findExportByName(dll,fn); if(p) Interceptor.attach(p,cb); }
H('KERNEL32.dll','CreateFileW',{onEnter:function(a){try{send({t:'FILE',n:a[0].readUtf16String()});}catch(e){}}});
H('KERNEL32.dll','LoadLibraryExW',{onEnter:function(a){try{send({t:'LOADLIB',n:a[0].readUtf16String()});}catch(e){}}});
H('KERNEL32.dll','GetProcAddress',{onEnter:function(a){try{send({t:'GPA',n:a[1].readAnsiString()});}catch(e){}}});
H('KERNEL32.dll','VirtualProtect',{onEnter:function(a){var np=a[2].toInt32(); if(np&0xf0){this.e=1;this.addr=a[0];this.sz=a[1].toInt32();}},onLeave:function(r){if(this.e)send({t:'VP',sz:this.sz,ascii:asc(this.addr,Math.min(this.sz,120))});}});
H('USER32.dll','SetWindowTextW',{onEnter:function(a){try{send({t:'D',s:a[1].readUtf16String()});}catch(e){}}});
H('USER32.dll','SetWindowTextA',{onEnter:function(a){try{send({t:'D',s:a[1].readAnsiString()});}catch(e){}}});
send({t:'READY'});
