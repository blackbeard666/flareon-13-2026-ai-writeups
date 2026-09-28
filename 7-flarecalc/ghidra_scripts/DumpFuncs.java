import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
public class DumpFuncs extends GhidraScript {
  public void run() throws Exception {
    String out="C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/decomp.c";
    PrintWriter pw=new PrintWriter(new FileWriter(out));
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    String[] pats={"ExecuteMapLookup","UpdateCalcContext","MapLookup","CalcContext","WndProc","WinMain","Decrypt","decrypt","Verify","Decode"};
    FunctionManager fm=currentProgram.getFunctionManager();
    // also dump a name list
    PrintWriter fl=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/funcs.txt"));
    java.util.Set<Function> done=new java.util.HashSet<>();
    for(Function f: fm.getFunctions(true)){
      String n=f.getName();
      fl.println(f.getEntryPoint()+"\t"+n);
      for(String p: pats){ if(n.toLowerCase().contains(p.toLowerCase())){
        if(done.add(f)){
          pw.println("\n// ===== "+n+" @ "+f.getEntryPoint()+" =====");
          DecompileResults r=di.decompileFunction(f,90,monitor);
          if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
          else pw.println("// decompile failed");
        }
        break;
      }}
    }
    fl.close(); pw.close();
    println("wrote "+out+" ("+done.size()+" funcs)");
  }
}
