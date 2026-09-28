var BD = ptr("BD_ADDR");
// find the Math.Min call at ~+0x6B (FF 15 disp32) and resolve target
function resolveStub(t){
  // follow jmp stubs: E9 rel32, or FF 25 [rip] (jmp qword ptr), or 48 B8 imm; FF E0
  for(var hops=0; hops<4; hops++){
    var b0=t.readU8();
    if(b0==0xE9){ var rel=t.add(1).readS32(); t=t.add(5).add(rel); continue; }
    if(b0==0xFF && t.add(1).readU8()==0x25){ var d=t.add(2).readS32(); t=t.add(6).add(d).readPointer(); continue; }
    if(b0==0x48 && t.add(1).readU8()==0xB8){ /* mov rax,imm; jmp rax */ var imm=t.add(2).readPointer(); if(t.add(10).readU8()==0xFF&&t.add(11).readU8()==0xE0){ t=imm; continue;} }
    break;
  }
  return t;
}
var code = BD.readByteArray(0x90);
var arr = new Uint8Array(code);
var callsite=-1;
for(var i=0;i<arr.length-6;i++){ if(arr[i]==0xFF && arr[i+1]==0x15){ // first FF15 after offset 0x60 is likely Math.Min
   if(i>=0x60){ callsite=i; break; } } }
send({t:"info", callsite: callsite});
if(callsite>=0){
  var instr=BD.add(callsite);
  var disp=instr.add(2).readS32();
  var ptrLoc=instr.add(6).add(disp);
  var tgt=ptrLoc.readPointer();
  var real=resolveStub(tgt);
  send({t:"mintarget", ptrLoc:ptrLoc.toString(), tgt:tgt.toString(), real:real.toString(),
        bytes: Array.from(new Uint8Array(real.readByteArray(64))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join('')});
  // hook the real function, log args + ret
  Interceptor.attach(real, { onEnter:function(a){ this.a0=a[0].toInt32(); this.a1=a[1].toInt32(); },
    onLeave:function(r){ send({t:"mincall", a0:this.a0, a1:this.a1, ret:r.toInt32()}); } });
}
send({t:"READY"});
