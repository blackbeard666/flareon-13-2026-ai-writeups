#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ---- SHA256 ---- */
typedef struct{uint32_t s[8];uint64_t len;uint8_t buf[64];int bl;}SHA;
static const uint32_t K[64]={0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
#define RR(x,n) (((x)>>(n))|((x)<<(32-(n))))
static void shc(SHA*c,const uint8_t*p){uint32_t w[64],a,b,cc,d,e,f,g,h,t1,t2;int i;
 for(i=0;i<16;i++)w[i]=(p[i*4]<<24)|(p[i*4+1]<<16)|(p[i*4+2]<<8)|p[i*4+3];
 for(;i<64;i++){uint32_t s0=RR(w[i-15],7)^RR(w[i-15],18)^(w[i-15]>>3);uint32_t s1=RR(w[i-2],17)^RR(w[i-2],19)^(w[i-2]>>10);w[i]=w[i-16]+s0+w[i-7]+s1;}
 a=c->s[0];b=c->s[1];cc=c->s[2];d=c->s[3];e=c->s[4];f=c->s[5];g=c->s[6];h=c->s[7];
 for(i=0;i<64;i++){uint32_t S1=RR(e,6)^RR(e,11)^RR(e,25);uint32_t ch=(e&f)^((~e)&g);t1=h+S1+ch+K[i]+w[i];uint32_t S0=RR(a,2)^RR(a,13)^RR(a,22);uint32_t mj=(a&b)^(a&cc)^(b&cc);t2=S0+mj;h=g;g=f;f=e;e=d+t1;d=cc;cc=b;b=a;a=t1+t2;}
 c->s[0]+=a;c->s[1]+=b;c->s[2]+=cc;c->s[3]+=d;c->s[4]+=e;c->s[5]+=f;c->s[6]+=g;c->s[7]+=h;}
static void shini(SHA*c){c->s[0]=0x6a09e667;c->s[1]=0xbb67ae85;c->s[2]=0x3c6ef372;c->s[3]=0xa54ff53a;c->s[4]=0x510e527f;c->s[5]=0x9b05688c;c->s[6]=0x1f83d9ab;c->s[7]=0x5be0cd19;c->len=0;c->bl=0;}
static void shupd(SHA*c,const uint8_t*p,size_t n){c->len+=n;while(n){int t=64-c->bl;if(t>(int)n)t=n;memcpy(c->buf+c->bl,p,t);c->bl+=t;p+=t;n-=t;if(c->bl==64){shc(c,c->buf);c->bl=0;}}}
static void shfin(SHA*c,uint8_t*o){uint64_t bits=c->len*8;uint8_t pad=0x80;shupd(c,&pad,1);uint8_t z=0;while(c->bl!=56)shupd(c,&z,1);uint8_t L[8];for(int i=0;i<8;i++)L[i]=bits>>(56-i*8);shupd(c,L,8);for(int i=0;i<8;i++){o[i*4]=c->s[i]>>24;o[i*4+1]=c->s[i]>>16;o[i*4+2]=c->s[i]>>8;o[i*4+3]=c->s[i];}}
/* ---- AES-256 decrypt ---- */
static const uint8_t sb[256]={0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16};
static uint8_t isb[256];
static uint8_t xt(uint8_t x){return (x<<1)^((x>>7)*0x1b);}
static uint8_t mul(uint8_t a,uint8_t b){uint8_t r=0;while(b){if(b&1)r^=a;a=xt(a);b>>=1;}return r;}
static uint8_t rk[240];
static void expand(const uint8_t*key){memcpy(rk,key,32);uint8_t t[4];int i=32;uint8_t rc=1;
 while(i<240){for(int j=0;j<4;j++)t[j]=rk[i-4+j];
  if(i%32==0){uint8_t tmp=t[0];t[0]=sb[t[1]]^rc;t[1]=sb[t[2]];t[2]=sb[t[3]];t[3]=sb[tmp];rc=xt(rc);}
  else if(i%32==16){for(int j=0;j<4;j++)t[j]=sb[t[j]];}
  for(int j=0;j<4;j++){rk[i]=rk[i-32]^t[j];i++;}}}
static void invmix(uint8_t*s){for(int c=0;c<4;c++){uint8_t a0=s[c*4],a1=s[c*4+1],a2=s[c*4+2],a3=s[c*4+3];
 s[c*4]=mul(a0,14)^mul(a1,11)^mul(a2,13)^mul(a3,9);s[c*4+1]=mul(a0,9)^mul(a1,14)^mul(a2,11)^mul(a3,13);s[c*4+2]=mul(a0,13)^mul(a1,9)^mul(a2,14)^mul(a3,11);s[c*4+3]=mul(a0,11)^mul(a1,13)^mul(a2,9)^mul(a3,14);}}
static void decblock(uint8_t*b){/* state column-major: b[0..15] as 4 cols of 4 */
 uint8_t s[16];for(int i=0;i<16;i++)s[i]=b[i];
 // AddRoundKey round14
 for(int i=0;i<16;i++)s[i]^=rk[14*16+i];
 for(int r=13;r>=1;r--){
  // InvShiftRows: rows shifted. state[row][col], col-major index = col*4+row
  uint8_t t[16];
  for(int col=0;col<4;col++)for(int row=0;row<4;row++){int src=((col-row+4)&3)*4+row;t[col*4+row]=s[src];}
  for(int i=0;i<16;i++)s[i]=isb[t[i]];
  for(int i=0;i<16;i++)s[i]^=rk[r*16+i];
  invmix(s);
 }
 {uint8_t t[16];for(int col=0;col<4;col++)for(int row=0;row<4;row++){int src=((col-row+4)&3)*4+row;t[col*4+row]=s[src];}for(int i=0;i<16;i++)s[i]=isb[t[i]];}
 for(int i=0;i<16;i++)s[i]^=rk[i];
 for(int i=0;i<16;i++)b[i]=s[i];}
static uint8_t tmpl[8192];int tlen;
static uint32_t pos[300];int npos;
static uint8_t CT[64],IV[16];
int main(int argc,char**argv){
 for(int i=0;i<256;i++)isb[sb[i]]=i;
 FILE*f=fopen("tmpl.bin","rb");tlen=fread(tmpl,1,sizeof(tmpl),f);fclose(f);
 f=fopen("positions.bin","rb");fread(&npos,4,1,f);fread(pos,4,npos,f);fclose(f);
 f=fopen("ctiv.bin","rb");fread(CT,1,64,f);fread(IV,1,16,f);fclose(f);
 uint64_t lo=strtoull(argv[1],0,10),hi=strtoull(argv[2],0,10);
 fprintf(stderr,"tlen=%d npos=%d range=%llu..%llu\n",tlen,npos,(unsigned long long)lo,(unsigned long long)hi);
 for(uint64_t x=lo;x<hi;x++){
  uint8_t vb[4]={x&0xff,(x>>8)&0xff,(x>>16)&0xff,(x>>24)&0xff};
  if(vb[3]==0)continue; // L=4 requires top byte nonzero (canonical)
  for(int i=0;i<npos;i++){uint8_t*d=tmpl+pos[i];d[0]=vb[0];d[1]=vb[1];d[2]=vb[2];d[3]=vb[3];}
  SHA c;shini(&c);shupd(&c,tmpl,tlen);uint8_t key[32];shfin(&c,key);
  expand(key);
  if(x==lo&&argc>3){printf("KEY ");for(int i=0;i<32;i++)printf("%02x",key[i]);putchar(10);fflush(stdout);}
  // decrypt 4 CBC blocks
  uint8_t pt[64];uint8_t prev[16];memcpy(prev,IV,16);
  for(int blk=0;blk<4;blk++){uint8_t b[16];memcpy(b,CT+blk*16,16);decblock(b);for(int i=0;i<16;i++)pt[blk*16+i]=b[i]^prev[i];memcpy(prev,CT+blk*16,16);}
  if(x==lo&&argc>3){printf("PT ");for(int i=0;i<64;i++)printf("%02x",pt[i]);putchar(10);fflush(stdout);}
  // check valid PKCS7 padding
  int n=pt[63];int ok=(n>=1&&n<=16);if(ok)for(int i=0;i<n;i++)if(pt[63-i]!=n){ok=0;break;}
  if(ok){
   if(argc>3){printf("PAD x=%llu n=%d ",(unsigned long long)x,n);putchar(10);fflush(stdout);}
   int fl=0;for(int i=0;i<=59;i++)if(pt[i]=='f'&&pt[i+1]=='l'&&pt[i+2]=='a'&&pt[i+3]=='r'&&pt[i+4]=='e'){fl=1;break;}
   if(fl){printf("HIT x=%llu pt=",(unsigned long long)x);for(int i=0;i<64;i++)putchar((pt[i]>=32&&pt[i]<127)?pt[i]:'.');putchar(32);printf("hex=");for(int i=0;i<64;i++)printf("%02x",pt[i]);putchar(10);fflush(stdout);}
  }
  if((x&0x3ffffff)==0)fprintf(stderr,"x=%llu\n",(unsigned long long)x);
 }
 fprintf(stderr,"done \n");return 0;}
