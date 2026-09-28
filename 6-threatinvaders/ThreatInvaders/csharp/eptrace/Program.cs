using System;using System.Collections.Generic;using System.Linq;using System.Threading;using System.Threading.Tasks;using System.Runtime.InteropServices;
using Microsoft.Diagnostics.NETCore.Client;using Microsoft.Diagnostics.Tracing;using Microsoft.Diagnostics.Tracing.Parsers;using Microsoft.Diagnostics.Tracing.Parsers.Clr;
class P{
 [DllImport("kernel32.dll",SetLastError=true)] static extern IntPtr OpenProcess(int access,bool inherit,int pid);
 [DllImport("kernel32.dll",SetLastError=true)] static extern bool ReadProcessMemory(IntPtr h,IntPtr addr,byte[] buf,int size,out int read);
 const string OUT=@"C:\Users\cavila\Desktop\ctf\flareon13-2026\6-threatinvaders\ThreatInvaders\exp\";
 static IntPtr hproc;
 static ulong Rd8(ulong a){ byte[] b=new byte[8]; return ReadProcessMemory(hproc,(IntPtr)a,b,8,out _)? BitConverter.ToUInt64(b,0):0; }
 static byte[] RdN(ulong a,int n){ byte[] b=new byte[n]; return ReadProcessMemory(hproc,(IntPtr)a,b,n,out int r)&&r>0? b:null; }
 static void Main(string[] a){
  int pid=int.Parse(a[0]);
  var map=new List<(ulong addr,int size,string name)>();  // all methods
  var client=new DiagnosticsClient(pid);
  var providers=new List<EventPipeProvider>{
    new EventPipeProvider("Microsoft-Windows-DotNETRuntime", System.Diagnostics.Tracing.EventLevel.Verbose, (long)ClrTraceEventParser.Keywords.Jit),
    new EventPipeProvider("Microsoft-Windows-DotNETRuntimeRundown", System.Diagnostics.Tracing.EventLevel.Verbose, (long)(ClrRundownTraceEventParser.Keywords.Jit | ClrRundownTraceEventParser.Keywords.NGen | ClrRundownTraceEventParser.Keywords.Loader)),
  };
  using var session=client.StartEventPipeSession(providers, requestRundown:true);
  var src=new EventPipeEventSource(session.EventStream);
  void handle(MethodLoadUnloadVerboseTraceData d){ map.Add(((ulong)d.MethodStartAddress,d.MethodSize,d.MethodNamespace+"."+d.MethodName)); }
  src.Clr.MethodLoadVerbose+=handle; src.Clr.MethodDCStartVerboseV2+=handle;
  var rundown=new ClrRundownTraceEventParser(src); rundown.MethodDCStartVerbose+=handle; rundown.MethodDCStopVerbose+=handle;
  var t=Task.Run(()=>{ try{src.Process();}catch{} });
  Thread.Sleep(7000); try{session.Stop();}catch{} t.Wait(4000);
  Console.WriteLine("captured "+map.Count+" methods");
  hproc=OpenProcess(0x0010|0x0400,false,pid);
  // resolve helper: given a code address, find containing method
  string Resolve(ulong tgt){
    foreach(var m in map) if(tgt>=m.addr && tgt<m.addr+(ulong)m.size) return m.name+(tgt==m.addr?"":"+0x"+(tgt-m.addr).ToString("X"));
    return "??";
  }
  System.IO.File.WriteAllLines(OUT+"method_map.txt", map.OrderBy(m=>m.addr).Select(m=>m.addr.ToString("X")+"\t"+m.size+"\t"+m.name));
  foreach(var target in new[]{"set_FeedbackLength","set_FeedbackB64","set_GamesPlayed","FeedbackLengthGetter","FeedbackB64Getter","GamesPlayedGetter"}){
    var m=map.FirstOrDefault(x=>x.name.Contains(target));
    if(m.addr==0){ Console.WriteLine("NOT FOUND "+target); continue; }
    byte[] code=RdN(m.addr,m.size);
    if(code==null){ Console.WriteLine("read fail "+target); continue; }
    System.IO.File.WriteAllBytes(OUT+"jit2_"+target.Replace('.','_')+".bin",code); if(code.Length<=64) Console.WriteLine("   HEX: "+BitConverter.ToString(code));
    Console.WriteLine("\n==== "+target+" @0x"+m.addr.ToString("X")+" size "+m.size+" ====");
    for(int i=0;i+6<=code.Length;i++){
      // FF 15 disp32 : call qword ptr [rip+disp32]
      if(code[i]==0xFF && code[i+1]==0x15){
        int disp=BitConverter.ToInt32(code,i+2); ulong next=m.addr+(ulong)i+6; ulong ptr=next+(ulong)(long)disp;
        ulong tgt=Rd8(ptr);
        Console.WriteLine($"  +0x{i:X} call [rip+0x{disp:X}] -> *0x{ptr:X}=0x{tgt:X}  {Resolve(tgt)}");
      }
      // E8 rel32 : call rel32
      else if(code[i]==0xE8){
        int rel=BitConverter.ToInt32(code,i+1); ulong next=m.addr+(ulong)i+5; ulong tgt=next+(ulong)(long)rel;
        Console.WriteLine($"  +0x{i:X} call 0x{tgt:X}  {Resolve(tgt)}");
      }
    }
  }
 }
}
