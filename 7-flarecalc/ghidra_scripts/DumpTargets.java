import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
import java.io.*;
import java.util.*;

public class DumpTargets extends GhidraScript {
  DecompInterface di;
  PrintWriter pw;
  Set<Long> done=new HashSet<>();

  void dump(Function f, String tag) throws Exception {
    if(f==null) return;
    if(!done.add(f.getEntryPoint().getOffset())) return;
    pw.println("\n// ===== "+tag+" "+f.getName()+" @ "+f.getEntryPoint()+" =====");
    DecompileResults r=di.decompileFunction(f,120,monitor);
    if(r!=null&&r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
    else pw.println("// decompile failed");
  }

  public void run() throws Exception {
    String out="C:/Users/cavila/Desktop/ctf/flareon13-2026/7-flarecalc/decomp5.c";
    pw=new PrintWriter(new FileWriter(out));
    di=new DecompInterface(); di.openProgram(currentProgram);
    FunctionManager fm=currentProgram.getFunctionManager();
    AddressFactory af=currentProgram.getAddressFactory();

    long[] targets={0x140008400L,0x1400083d0L,0x1400083a0L,0x140008370L,0x1400082f0L,0x1400082b0L,0x140008270L};
    for(long t: targets){
      Address a=af.getDefaultAddressSpace().getAddress(t);
      Function f=fm.getFunctionContaining(a);
      if(f==null) f=fm.getFunctionAt(a);
      if(f==null){ pw.println("// no function at "+Long.toHexString(t)); continue; }
      dump(f,"[lambda]");
      for(Function callee: f.getCalledFunctions(monitor)) dump(callee,"[callee]");
    }

    // Find functions referencing the RTTI type-descriptor region (ExecuteMapLookup / UpdateCalcContext lambdas)
    Address lo=af.getDefaultAddressSpace().getAddress(0x1400e5400L);
    Address hi=af.getDefaultAddressSpace().getAddress(0x1400e56d0L);
    ReferenceManager rm=currentProgram.getReferenceManager();
    Set<Function> rtti=new LinkedHashSet<>();
    for(Reference ref: rm.getReferenceIterator(currentProgram.getMemory().getMinAddress())){
      Address to=ref.getToAddress();
      if(to!=null && to.compareTo(lo)>=0 && to.compareTo(hi)<0){
        Function f=fm.getFunctionContaining(ref.getFromAddress());
        if(f!=null) rtti.add(f);
      }
    }
    pw.println("\n// ==== functions referencing RTTI 0xe5400-0xe56d0 ====");
    for(Function f: rtti) pw.println("//   "+f.getName()+" @ "+f.getEntryPoint());
    for(Function f: rtti) dump(f,"[rtti-ref]");

    // Callers of interesting imports
    String[] imps={"GetModuleFileNameW","CreateFileW","ReadFile","SetFilePointerEx","SetFilePointer",
                   "GetFileSize","MapViewOfFile","CreateFileMappingW","TrySubmitThreadpoolCallback",
                   "CryptDecrypt","CryptAcquireContextW","BCryptOpenAlgorithmProvider","WinVerifyTrust",
                   "CryptDecodeObjectEx","CertCreateCertificateContext","CryptHashData",
                   "GetModuleFileNameA","LoadResource","FindResourceW","VirtualAlloc"};
    pw.println("\n// ==== callers of interesting imports ====");
    SymbolTable st=currentProgram.getSymbolTable();
    for(String s: imps){
      SymbolIterator si=st.getSymbols(s);
      boolean any=false;
      for(Symbol sym: si){
        any=true;
        ReferenceIterator refs=rm.getReferencesTo(sym.getAddress());
        for(Reference r: refs){
          Function f=fm.getFunctionContaining(r.getFromAddress());
          pw.println("//   "+s+" <- "+(f==null?"?":f.getName()+" @ "+f.getEntryPoint())+" (from "+r.getFromAddress()+")");
        }
      }
      if(!any) pw.println("//   "+s+": symbol not found");
    }
    pw.close();
    println("wrote "+out+" ("+done.size()+" funcs)");
  }
}
