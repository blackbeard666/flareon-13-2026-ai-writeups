var BD = ptr("BD_ADDR");
function follow(t){
  for(var h=0;h<6;h++){ var b0=t.readU8(),b1=t.add(1).readU8();
    if(b0==0xE9){t=t.add(5).add(t.add(1).readS32());continue;}
    if(b0==0xFF&&b1==0x25){t=t.add(6).add(t.add(2).readS32()).readPointer();continue;}
    if(b0==0x48&&b1==0x8B&&t.add(2).readU8()==0x05&&t.add(7).readU8()==0x66){
      var j2=t.add(16); if(j2.readU8()==0xFF&&j2.add(1).readU8()==0x25){t=j2.add(6).add(j2.add(2).readS32()).readPointer();continue;} }
    break; } return t;
}
// find the EncodeFeedbackBuffer call in BuildDocument: it's the FF15 right after the Array.Copy; take the 3rd FF15 overall or the one near +0x8E
var code=new Uint8Array(BD.readByteArray(0xA0));
var calls=[];
for(var i=0;i<code.length-6;i++){ if(code[i]==0xFF&&code[i+1]==0x15) calls.push(i); }
send({t:"calls", offs: calls});
// EncodeFeedbackBuffer call is around +0x8E; pick the call whose target resolves to a func taking (rcx=array, rdx=ptr)
var efbCs = calls.filter(function(x){return x>=0x88 && x<0x98;})[0];
if(efbCs===undefined) efbCs=calls[2];
var instr=BD.add(efbCs); var real=follow(instr.add(6).add(instr.add(2).readS32()).readPointer());
send({t:"efb", cs:efbCs, real:real.toString(),
      bytes: Array.from(new Uint8Array(real.readByteArray(320))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join('')});
Interceptor.attach(real,{
  onEnter:function(a){ this.lenPtr=a[1]; this.buf=a[0];
    this.lenIn = a[1].isNull()?-1:a[1].readS32();
    this.headIn = a[0].isNull()?"":Array.from(new Uint8Array(a[0].add(0x10).readByteArray(16))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join(''); },
  onLeave:function(r){
    var lenOut=this.lenPtr.isNull()?-1:this.lenPtr.readS32();
    var headOut=this.buf.isNull()?"":Array.from(new Uint8Array(this.buf.add(0x10).readByteArray(16))).map(function(x){return('0'+x.toString(16)).slice(-2)}).join('');
    send({t:"efbcall", lenIn:this.lenIn, lenOut:lenOut, headIn:this.headIn, headOut:headOut});
  }});
send({t:"READY"});
