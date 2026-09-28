import ghidra.app.script.GhidraScript; import ghidra.app.decompiler.*; import ghidra.program.model.listing.*; import ghidra.program.model.address.Address; import ghidra.program.model.symbol.*;
import java.io.*;
public class Xref3380 extends GhidraScript { public void run() throws Exception {
  PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/calc_trigger.c"));
  DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
  long base=0x140000000L;
  ReferenceManager rm=currentProgram.getReferenceManager();
  // xrefs to FUN_140003380, FUN_140002000, FUN_1400019d0, and the vtable ptr 0x1400dde60
  long[] tolook={0x3380,0x34ce,0x2000,0x19d0};
  java.util.Set<Long> done=new java.util.HashSet<>();
  for(long t: tolook){
    Address ta=toAddr(base+t);
    pw.println("\n//===== refs TO "+Long.toHexString(base+t)+" =====");
    ReferenceIterator it=rm.getReferencesTo(ta);
    java.util.Set<Long> callers=new java.util.HashSet<>();
    while(it.hasNext()){ Reference r=it.next(); Address fa=r.getFromAddress();
      Function cf=getFunctionContaining(fa);
      pw.println("//  from "+fa+(cf!=null?(" in "+cf.getName()):"")+" "+r.getReferenceType());
      if(cf!=null) callers.add(cf.getEntryPoint().getOffset());
    }
    // decompile callers of 3380 and 34ce
    if(t==0x3380 || t==0x34ce){
      for(long c: callers){ if(!done.add(c)) continue;
        Function f=getFunctionAt(toAddr(c));
        pw.println("\n// --- caller "+f.getName()+" ---");
        DecompileResults r=di.decompileFunction(f,150,monitor);
        if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC()); else pw.println("//fail");
      }
    }
  }
  // also decompile FUN_1400034ce itself
  for(long t: new long[]{0x34ce}){ Address a=toAddr(base+t); Function f=getFunctionContaining(a);
    if(f==null){try{disassemble(a);}catch(Exception e){} f=createFunction(a,null);}
    if(f!=null && done.add(f.getEntryPoint().getOffset()+0x1000000)){
      pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" =====");
      DecompileResults r=di.decompileFunction(f,150,monitor);
      if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC()); else pw.println("//fail");
    }
  }
  pw.close(); println("done");
}}
