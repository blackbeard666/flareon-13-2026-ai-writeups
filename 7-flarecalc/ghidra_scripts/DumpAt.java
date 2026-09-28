import ghidra.app.script.GhidraScript; import ghidra.app.decompiler.*; import ghidra.program.model.listing.*; import ghidra.program.model.address.Address;
import java.io.*;
public class DumpAt extends GhidraScript { public void run() throws Exception {
  PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/blob3821_builder.c"));
  DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
  long base=0x140000000L;
  long[] offs={0x0,0x1000,0x2000,0x2ca4,0x2000,0x2500,0x2800};
  java.util.Set<Long> seen=new java.util.HashSet<>();
  for(long o: offs){ Address a=toAddr(base+o);
    Function f=getFunctionContaining(a); if(f==null) f=createFunction(a,null);
    if(f==null){ pw.println("// no func @"+Long.toHexString(base+o)); continue; }
    if(!seen.add(f.getEntryPoint().getOffset())) continue;
    pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" =====");
    DecompileResults r=di.decompileFunction(f,120,monitor);
    if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC()); else pw.println("//fail");
  }
  // also list ALL functions now
  int n=0; for(Function f: currentProgram.getFunctionManager().getFunctions(true)) n++;
  pw.println("\n// total funcs now: "+n);
  pw.close(); println("done");
}}
