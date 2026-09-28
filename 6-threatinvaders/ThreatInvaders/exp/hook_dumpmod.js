var A = ptr("0x7ff778c96ba0");
send({t:"info", note:"locating module"});
var m = Process.findModuleByAddress(A);
if(m){ send({t:"module", name:m.name, base:m.base.toString(), size:m.size}); 
  // dump whole module in chunks
} else {
  send({t:"nomodule"});
  // find the enclosing memory range
  var r = Process.findRangeByAddress(A);
  if(r){ send({t:"range", base:r.base.toString(), size:r.size, prot:r.protection}); }
}
send({t:"READY"});
