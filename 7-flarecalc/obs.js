function hh(p,n){try{return Array.from(new Uint8Array(p.readByteArray(n))).map(x=>('0'+x.toString(16)).slice(-2)).join('')}catch(e){return '<e>'}}
['VirtualProtect'].forEach(function(n){
  var p=Module.findExportByName('KERNEL32.dll',n)||Module.findExportByName('kernelbase.dll',n);
  if(p) Interceptor.attach(p,{onEnter:function(a){
    var addr=a[0], sz=a[1].toInt32(), np=a[2].toInt32();
    // PAGE_EXECUTE* = 0x10,0x20,0x40,0x80
    if(np&0xf0){ send({t:'VP',addr:addr.toString(),size:sz,prot:np,head:hh(addr,64)}); }
  }});
});
['CreateFileW'].forEach(function(n){
  var p=Module.findExportByName('KERNEL32.dll',n);
  if(p) Interceptor.attach(p,{onEnter:function(a){ try{send({t:'CreateFileW',name:a[0].readUtf16String()});}catch(e){} }});
});
['SetWindowTextA'].forEach(function(n){var p=Module.findExportByName('USER32.dll',n); if(p) Interceptor.attach(p,{onEnter:function(a){try{send({t:'SWT_A',s:a[1].readAnsiString()});}catch(e){}}});});
['SetWindowTextW'].forEach(function(n){var p=Module.findExportByName('USER32.dll',n); if(p) Interceptor.attach(p,{onEnter:function(a){try{send({t:'SWT_W',s:a[1].readUtf16String()});}catch(e){}}});});
send({t:'READY'});
