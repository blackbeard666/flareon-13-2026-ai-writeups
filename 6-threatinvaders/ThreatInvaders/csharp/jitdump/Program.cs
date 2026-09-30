using System;using System.Linq;using System.IO;using Microsoft.Diagnostics.Runtime;
class P{
 static void Main(string[] a){
  int pid=int.Parse(a[0]); string dac=a.Length>1?a[1]:null;
  using var dt=DataTarget.AttachToProcess(pid, suspend:true);
  var cv=dt.ClrVersions[0];
  var rt=(dac!=null)?cv.CreateRuntime(dac, ignoreMismatch:true):cv.CreateRuntime();
  string OUT=@"C:\Users\cavila\Desktop\ctf\flareon13-2026\6-threatinvaders\ThreatInvaders\exp\";
  foreach(var mod in rt.EnumerateModules()){
    var nm=(mod.Name??"").ToLower();
    if(!nm.Contains("threatinvaders")) continue;
    Console.WriteLine("MODULE "+mod.Name);
    foreach(var t in mod.EnumerateTypeDefToMethodTableMap()){
      var type=rt.GetTypeByMethodTable(t.MethodTable);
      if(type==null){ continue; }
      if(!type.Name.Contains("TelemetryReporter")) continue;
      var methods=type.Methods;
      Console.WriteLine("TYPE "+type.Name+"  methodCount="+methods.Count());
      foreach(var meth in methods){
        Console.WriteLine("   METHOD "+meth.Name+" token=0x"+meth.MetadataToken.ToString("X")+" nat=0x"+meth.NativeCode.ToString("X")+" hot=0x"+meth.HotColdInfo.HotStart.ToString("X")+" size="+meth.HotColdInfo.HotSize+" state="+meth.CompilationType);
        var hc=meth.HotColdInfo;
        if(hc.HotStart!=0 && hc.HotSize>0 && hc.HotSize<60000){
          byte[] buf=new byte[hc.HotSize];
          if(dt.DataReader.Read(hc.HotStart,buf)>0){
            File.WriteAllBytes(OUT+"jit_"+type.Name.Replace('+','_').Replace('<','_').Replace('>','_')+"__"+meth.Name+"_0x"+hc.HotStart.ToString("X")+".bin",buf);
            Console.WriteLine("     DUMPED "+buf.Length+" bytes @ 0x"+hc.HotStart.ToString("X"));
          }
        }
      }
    }
  }
 }
}
