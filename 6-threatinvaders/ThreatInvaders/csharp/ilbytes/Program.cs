using System;using System.IO;using System.Reflection.Metadata;using System.Reflection.Metadata.Ecma335;
class P{
 static string AttrName(MetadataReader md,CustomAttribute a){
   var c=a.Constructor;
   if(c.Kind==HandleKind.MemberReference){var mr=md.GetMemberReference((MemberReferenceHandle)c);var pt=mr.Parent;
     if(pt.Kind==HandleKind.TypeReference){var tr=md.GetTypeReference((TypeReferenceHandle)pt);return md.GetString(tr.Namespace)+"."+md.GetString(tr.Name);}
     if(pt.Kind==HandleKind.TypeDefinition){var td=md.GetTypeDefinition((TypeDefinitionHandle)pt);return md.GetString(td.Name);}}
   if(c.Kind==HandleKind.MethodDefinition){var m=md.GetMethodDefinition((MethodDefinitionHandle)c);var td=md.GetTypeDefinition(m.GetDeclaringType());return md.GetString(td.Name);}
   return "?";
 }
 static void Main(){
  var path=@"C:\Users\cavila\Desktop\ctf\flareon13-2026\6-threatinvaders\ThreatInvaders\extracted\ThreatInvaders.dll";
  using var fs=File.OpenRead(path); using var pe=new System.Reflection.PortableExecutable.PEReader(fs);
  var md=pe.GetMetadataReader();
  foreach(var th in md.TypeDefinitions){var td=md.GetTypeDefinition(th);var tn=md.GetString(td.Name);
    if(tn!="TelemetryDto"&&tn!="TelemetryReporter")continue;
    Console.WriteLine("TYPE "+tn+" attrs:");
    foreach(var ah in td.GetCustomAttributes())Console.WriteLine("  "+AttrName(md,md.GetCustomAttribute(ah)));
    foreach(var ph in td.GetProperties()){var pr=md.GetPropertyDefinition(ph);Console.WriteLine("  PROP "+md.GetString(pr.Name)+":");
      foreach(var ah in pr.GetCustomAttributes())Console.WriteLine("     "+AttrName(md,md.GetCustomAttribute(ah)));}
    foreach(var fh in td.GetFields()){var f=md.GetFieldDefinition(fh);var fn=md.GetString(f.Name);
      foreach(var ah in f.GetCustomAttributes()){var an=AttrName(md,md.GetCustomAttribute(ah));if(an.Contains("Json")||an.Contains("Converter"))Console.WriteLine("  FIELD "+fn+" "+an);}}
  }
 }
}
