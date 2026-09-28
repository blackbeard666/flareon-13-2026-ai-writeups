import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.Address;
import java.io.*;
public class Xref extends GhidraScript {
  public void run() throws Exception {
    PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/xref.c"));
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    FunctionManager fm=currentProgram.getFunctionManager();
    Address t=toAddr(0x1400026b0L);
    java.util.Set<Function> callers=new java.util.LinkedHashSet<>();
    for(Reference r: getReferencesTo(t)){ Function f=fm.getFunctionContaining(r.getFromAddress()); if(f!=null) callers.add(f); }
    pw.println("// callers of FUN_1400026b0: "+callers.size());
    for(Function f: callers){
      pw.println("\n// ===== CALLER "+f.getName()+" @ "+f.getEntryPoint()+" =====");
      DecompileResults r=di.decompileFunction(f,120,monitor);
      if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
    }
    pw.close(); println("done callers="+callers.size());
  }
}
