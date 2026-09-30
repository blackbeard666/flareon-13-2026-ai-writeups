import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import java.io.*;
public class DecompAddrs extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outPath = args.length>0? args[0] : "C:/Users/cavila/Desktop/ctf/flareon13-2026/6-threatinvaders/ThreatInvaders/exp/decomp_out.c";
        PrintWriter pw = new PrintWriter(new FileWriter(outPath));
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        long[] addrs = new long[]{0x1405d3f30L,0x1405d40e0L,0x1405d49a0L};
        for (long a : addrs) {
            Address addr = toAddr(a);
            Function f = getFunctionContaining(addr);
            if (f==null){ f = createFunction(addr,null); }
            if (f==null){ pw.println("// no function at "+Long.toHexString(a)); continue; }
            pw.println("\n// ===== "+f.getName()+" @ "+f.getEntryPoint()+" =====");
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            if (r!=null && r.decompileCompleted()) pw.println(r.getDecompiledFunction().getC());
            else pw.println("// decompile failed: "+(r!=null?r.getErrorMessage():"null"));
        }
        pw.close();
        println("wrote "+outPath);
    }
}
