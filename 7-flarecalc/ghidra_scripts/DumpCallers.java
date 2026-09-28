import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.Address;
import java.util.*;
import java.io.*;
public class DumpCallers extends GhidraScript {
  public void run() throws Exception {
    String out="C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/decomp2.c";
    PrintWriter pw=new PrintWriter(new FileWriter(out));
    DecompInterface di=new DecompInterface(); di.openProgram(currentProgram);
    String[] targets={"VirtualProtect","CreateFileW","GetModuleFileNameW","RegisterClassExW","SetWindowTextW","CreateWindowExW","SetTimer","LoadLibraryExW","GetProcAddress"};
    FunctionManager fm=currentProgram.getFunctionManager();
    SymbolTable st=currentProgram.getSymbolTable();
    Set<Function> callers=new LinkedHashSet<>();
    for(String t: targets){
      for(Symbol s: st.getSymbols(t)){
        Reference[] refs=getReferencesTo(s.getAddress());
        for(Reference r: refs){
          Function cf=fm.getFunctionContaining(r.getFromAddress());
          if(cf!=null) callers.add(cf);
        }
      }
    }
    pw.println("// callers of: "+String.join(",",targets)+"  -> "+callers.size()+" funcs");
    for(Function f: callers){
      pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+"  size~"+f.getBody().getNumAddresses()+" =====");
      DecompileResults r=di.decompileFunction(f,120,monitor);
      if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
      else pw.println("// decompile failed");
    }
    pw.close(); println("wrote "+out+" ("+callers.size()+")");
  }
}
