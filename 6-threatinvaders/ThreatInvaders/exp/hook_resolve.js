var BD = ptr("BD_ADDR");
function follow(t){
  for(var h=0;h<6;h++){
    var b0=t.readU8(), b1=t.add(1).readU8();
    if(b0==0xE9){ t=t.add(5).add(t.add(1).readS32()); continue; }
    if(b0==0xFF && b1==0x25){ t=t.add(6).add(t.add(2).readS32()).readPointer(); continue; }
    if(b0==0x48 && b1==0x8B && t.add(2).readU8()==0x05 && t.add(7).readU8()==0x66){ // FixupPrecode: mov rax,[rip+x]; dec word[rax]; jz; jmp [rip]; jmp [rip]
      // second jmp (offset 16) is the real target after fixup; read its pointer
      var j2=t.add(16); // FF 25 zz
      if(j2.readU8()==0xFF && j2.add(1).readU8()==0x25){ t=j2.add(6).add(j2.add(2).readS32()).readPointer(); continue; }
      var j1=t.add(10);
      if(j1.readU8()==0xFF && j1.add(1).readU8()==0x25){ t=j1.add(6).add(j1.add(2).readS32()).readPointer(); continue; }
    }
    break;
  }
  return t;
}
var code=new Uint8Array(BD.readByteArray(0x70));
var cs=-1;
for(var i=0x60;i<0x70;i++){ if(code[i]==0xFF&&code[i+1]==0x15){cs=i;break;} }
var instr=BD.add(cs); var ptrLoc=instr.add(6).add(instr.add(2).readS32());
var tgt=ptrLoc.readPointer();
var real=follow(tgt);
send({t:"resolved", cs:cs, tgt:tgt.toString(), real:real.toString(),
      bytes: Array.from(new Uint8Array(real.readByteArray(160))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join('')});
// hook after the call to read rax (min result)
Interceptor.attach(BD.add(cs+6), { onEnter:function(a){ send({t:"minret", rax: this.context.rax.toInt32()}); } });
send({t:"READY"});
