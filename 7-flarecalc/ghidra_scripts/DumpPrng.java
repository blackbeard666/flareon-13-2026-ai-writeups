import ghidra.app.script.GhidraScript; import ghidra.app.decompiler.*; import ghidra.program.model.listing.*; import ghidra.program.model.address.Address;
import java.io.*;
public class DumpPrng extends GhidraScript { public void run() throws Exception {
  PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/blob3821_prng.c"));
  DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
  long base=0x140000000L;
  long[] offs={0x9070,0x95b8,0x9114,0xaa44};
  java.util.Set<Long> seen=new java.util.HashSet<>();
  for(long o: offs){ Address a=toAddr(base+o);
    Function f=getFunctionContaining(a);
    if(f==null){ try{ disassemble(a); }catch(Exception e){} f=createFunction(a,null); }
    if(f==null){ pw.println("\n// no func @"+Long.toHexString(base+o)); continue; }
    if(!seen.add(f.getEntryPoint().getOffset())) continue;
    pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" off=0x"+Long.toHexString(f.getEntryPoint().getOffset()-base)+" =====");
    DecompileResults r=di.decompileFunction(f,180,monitor);
    if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC()); else pw.println("//fail");
  }
  pw.close(); println("done");
}}
