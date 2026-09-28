import ghidra.app.script.GhidraScript; import ghidra.app.decompiler.*; import ghidra.program.model.listing.*; import ghidra.program.model.address.Address;
import java.io.*;
public class DumpVM extends GhidraScript { public void run() throws Exception {
  PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/blob3821_vm.c"));
  DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
  long base=0x140000000L;
  long[] offs={0x2a84,0x9a30,0xad44,0xa674,0xa21c,0x6dfc,0x1000,0x2000,0x2500,0x2800,0xa9e8,0xaad4};
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
