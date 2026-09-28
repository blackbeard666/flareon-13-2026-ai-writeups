import ghidra.app.script.GhidraScript; import ghidra.app.decompiler.*; import ghidra.program.model.listing.*;
import java.io.*;
public class DumpAll extends GhidraScript { public void run() throws Exception {
  PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/blob3821_decomp.c"));
  DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
  int n=0; for(Function f: currentProgram.getFunctionManager().getFunctions(true)){
    pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" size~"+f.getBody().getNumAddresses()+" =====");
    DecompileResults r=di.decompileFunction(f,90,monitor);
    if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC()); else pw.println("// fail");
    n++;
  }
  pw.close(); println("dumped "+n+" funcs");
}}
