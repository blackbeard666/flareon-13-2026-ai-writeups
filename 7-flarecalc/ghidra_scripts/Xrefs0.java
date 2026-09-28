import ghidra.app.script.GhidraScript; import ghidra.program.model.listing.*; import ghidra.program.model.address.Address; import ghidra.program.model.symbol.*;
public class Xrefs0 extends GhidraScript { public void run() throws Exception {
  long base=0x140000000L;
  Address entry=toAddr(base);
  println("=== References TO 0x140000000 ===");
  ReferenceManager rm=currentProgram.getReferenceManager();
  ReferenceIterator it=rm.getReferencesTo(entry);
  int n=0; while(it.hasNext()){ Reference r=it.next(); println("  from "+r.getFromAddress()+" type="+r.getReferenceType()); n++; }
  println("total refs to entry: "+n);
  // find functions with no callers (roots), i.e., entry-like
  println("=== Root functions (no incoming call refs) ===");
  FunctionManager fm=currentProgram.getFunctionManager();
  int roots=0;
  for(Function f: fm.getFunctions(true)){
    Address a=f.getEntryPoint();
    ReferenceIterator ri=rm.getReferencesTo(a);
    boolean called=false;
    while(ri.hasNext()){ Reference r=ri.next(); if(r.getReferenceType().isCall()||r.getReferenceType().isData()){ called=true; break; } }
    if(!called){ println("  ROOT "+f.getName()+" off=0x"+Long.toHexString(a.getOffset()-base)); roots++; }
  }
  println("total roots: "+roots);
}}
