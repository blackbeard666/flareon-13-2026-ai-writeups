using System;using System.IO;using ICSharpCode.Decompiler;using ICSharpCode.Decompiler.CSharp;using ICSharpCode.Decompiler.Metadata;
class P{static void Main(){
 var dir=@"C:\Users\cavila\Desktop\ctf\flareon13-2026\6-threatinvaders\ThreatInvaders\extracted\asm";
 var f=dir+@"\ThreatInvaders.dll";var r=new UniversalAssemblyResolver(f,false,null);r.AddSearchDirectory(dir);
 var d=new CSharpDecompiler(f,r,new DecompilerSettings());
 File.WriteAllText(@"C:\Users\cavila\Desktop\ctf\flareon13-2026\6-threatinvaders\ThreatInvaders\extracted\full11.cs",d.DecompileWholeModuleAsString());
 Console.WriteLine("ok");
}}
