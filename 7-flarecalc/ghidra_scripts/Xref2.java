import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.Address;
import java.io.*;
public class Xref2 extends GhidraScript {
  public void run() throws Exception {
    PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/xref2.c"));
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    FunctionManager fm=currentProgram.getFunctionManager();
    long[] addrs={0x1400e9268L,0x1400e9228L};
    java.util.Set<Function> funcs=new java.util.LinkedHashSet<>();
    for(long a: addrs){ for(Reference r: getReferencesTo(toAddr(a))){ Function f=fm.getFunctionContaining(r.getFromAddress()); if(f!=null) funcs.add(f);} }
    pw.println("// funcs touching DAT_1400e9268/DAT_1400e9228: "+funcs.size());
    for(Function f: funcs){ pw.println("  "+f.getName()+" @ "+f.getEntryPoint()+" size~"+f.getBody().getNumAddresses()); }
    // decompile the smaller ones (likely init + hash), skip the huge WndProc
    for(Function f: funcs){
      if(f.getBody().getNumAddresses()>4000) continue;
      pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" =====");
      DecompileResults r=di.decompileFunction(f,120,monitor);
      if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
    }
    pw.close(); println("done");
  }
}
