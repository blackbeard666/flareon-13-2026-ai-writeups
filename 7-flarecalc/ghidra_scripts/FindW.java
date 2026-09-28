import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
public class FindW extends GhidraScript {
  public void run() throws Exception {
    PrintWriter pw=new PrintWriter(new FileWriter("C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/findw.c"));
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    FunctionManager fm=currentProgram.getFunctionManager(); SymbolTable st=currentProgram.getSymbolTable();
    java.util.Set<Function> cs=new java.util.LinkedHashSet<>();
    for(String t: new String[]{"FindWindowW","SetTimer","SendMessageW"}){
      for(Symbol s: st.getSymbols(t)) for(Reference r: getReferencesTo(s.getAddress())){
        Function f=fm.getFunctionContaining(r.getFromAddress()); if(f!=null) cs.add(f); }
    }
    for(Function f: cs){
      pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" =====");
      DecompileResults r=di.decompileFunction(f,90,monitor);
      if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
    }
    pw.close(); println("done");
  }
}
