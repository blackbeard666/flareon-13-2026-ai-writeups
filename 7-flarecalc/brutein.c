#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "md5.h"

static uint8_t raw[4096]; static int rawlen;
static int loadf(const char*fn,uint8_t*b){FILE*f=fopen(fn,"rb");if(!f)return -1;int n=fread(b,1,4096,f);fclose(f);return n;}

// templates: first bytes of common MSVC x64 prologues
typedef struct{uint8_t b[6];int len;} Tmpl;
static Tmpl T[]={
 {{0x48,0x89,0x5c,0x24},4},{{0x48,0x89,0x4c,0x24},4},{{0x48,0x89,0x54,0x24},4},
 {{0x48,0x89,0x74,0x24},4},{{0x48,0x89,0x7c,0x24},4},{{0x48,0x89,0x6c,0x24},4},
 {{0x40,0x53,0x48,0x83,0xec},5},{{0x40,0x55,0x48,0x8b,0xec},5},{{0x40,0x56,0x48,0x83,0xec},5},
 {{0x40,0x57,0x48,0x83,0xec},5},{{0x53,0x48,0x83,0xec},4},{{0x55,0x48,0x8b,0xec},4},
 {{0x56,0x48,0x83,0xec},4},{{0x57,0x48,0x83,0xec},4},{{0x4c,0x8b,0xdc,0x49,0x89},5},
 {{0x48,0x8b,0xc4,0x48,0x89},5},{{0x48,0x83,0xec,0x28},4},{{0x48,0x83,0xec,0x38},4},
 {{0x48,0x83,0xec,0x48},4},{{0x48,0x83,0xec,0x58},4},{{0x48,0x83,0xec,0x68},4},
 {{0x48,0x81,0xec},3},{{0x53,0x55,0x56,0x57},4},{{0x53,0x56,0x57,0x48},4},
 {{0x41,0x54,0x41,0x55},4},{{0x41,0x56,0x41,0x57},4},{{0x48,0x8b,0xc4,0x53},4},
};
static int NT=sizeof(T)/sizeof(T[0]);

int main(int argc,char**argv){
    setvbuf(stdout,NULL,_IONBF,0);
    rawlen=loadf("raw_3829.bin",raw);
    if(rawlen<=0){fprintf(stderr,"no raw\n");return 1;}
    uint32_t KEY=3829;
    if(argc>1 && strcmp(argv[1],"test")==0){
        const char*tests[]={"1-2-3","0-0-0","10-20-30","525-193-718"};
        for(int ti=0;ti<4;ti++){
            const char*buf=tests[ti]; int L=strlen(buf);
            uint8_t msg[64]; memcpy(msg,buf,L);
            msg[L]=KEY&0xff;msg[L+1]=(KEY>>8)&0xff;msg[L+2]=(KEY>>16)&0xff;msg[L+3]=(KEY>>24)&0xff;
            uint8_t md[16]; md5_small(msg,L+4,md);
            uint8_t fold=0; for(int i=0;i<16;i++) fold=(uint8_t)(fold*0x1f+md[i]);
            uint8_t ks[32]; {uint8_t b=fold;for(int p=0;p<32;p++){b=(uint8_t)(b*0x6d+0x39);ks[p]=b;}}
            uint32_t st=0x2437; for(int i=0;i<L;i++) st=st*0x81+(uint32_t)(int32_t)(int8_t)buf[i];
            uint8_t out[8]; int pos=0;
            for(int j=0;j<6;j++){ out[j]=raw[pos]^ks[pos]; st=st*1103515245u+12345u; uint32_t sk=(st%3)+1; for(uint32_t k=0;k<sk;k++) st=st*1103515245u+12345u; pos+=1+sk; }
            printf("test %-14s md5=%02x%02x%02x%02x fold=%d out6=%02x%02x%02x%02x%02x%02x\n",buf,md[0],md[1],md[2],md[3],fold,out[0],out[1],out[2],out[3],out[4],out[5]);
        }
        return 0;
    }
    int LO=argc>1?atoi(argv[1]):0, HI=argc>2?atoi(argv[2]):1000;
    // known folds from frequency recovery
    // 3829->190, 3827->90, 3824->116, 3822->146
    char buf[64]; uint8_t md[16];
    long long tried=0, found=0;
    #define FOLDOF(K,inbuf,inlen,outfold) do{ \
        uint8_t m2[64]; memcpy(m2,inbuf,inlen); \
        m2[inlen]=(K)&0xff;m2[inlen+1]=((K)>>8)&0xff;m2[inlen+2]=((K)>>16)&0xff;m2[inlen+3]=((K)>>24)&0xff; \
        uint8_t d2[16]; md5_small(m2,inlen+4,d2); uint8_t f2=0; for(int _i=0;_i<16;_i++) f2=(uint8_t)(f2*0x1f+d2[_i]); outfold=f2; }while(0)
    for(int A=LO;A<HI;A++){
      for(int B=0;B<HI;B++){
        for(int C=0;C<HI;C++){
          int L=snprintf(buf,sizeof(buf),"%d-%d-%d",A,B,C);
          tried++;
          uint8_t f;
          FOLDOF(3829,buf,L,f); if(f!=190) continue;
          FOLDOF(3827,buf,L,f); if(f!=90) continue;
          FOLDOF(3824,buf,L,f); if(f!=116) continue;
          FOLDOF(3822,buf,L,f); if(f!=146) continue;
          found++; printf("HIT %s\n",buf);
        }
      }
      if((A%50)==0) fprintf(stderr,"A=%d tried=%lld found=%lld\n",A,tried,found);
    }
    fprintf(stderr,"done tried=%lld found=%lld\n",tried,found);
    return 0;
}
