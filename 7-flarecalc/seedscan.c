#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
static uint8_t raw[4096]; static int rawlen;
static uint8_t decF[4096];
static int loadf(const char*fn,uint8_t*b){FILE*f=fopen(fn,"rb");if(!f)return -1;int n=fread(b,1,4096,f);fclose(f);return n;}
static int REXOP[256], OF2[256], FFOP[256];
static void init_tables(){
    int rex[]={0x89,0x8b,0x83,0x01,0x03,0x8d,0x63,0x85,0x39,0x3b,0xff,0xc7,0x31,0x33,0x29,0x2b,0x21,0x09,0x87,0x88,0x8a,0x0b,0x23,0x05,0x25,-1};
    for(int i=0;rex[i]>=0;i++) REXOP[rex[i]]=1;
    for(int b=0x80;b<=0x8f;b++) OF2[b]=1;
    int of[]={0x1f,0xb6,0xb7,0x10,0x11,0x57,0x28,0x29,-1};
    for(int i=0;of[i]>=0;i++) OF2[of[i]]=1;
    int ff[]={0x15,0x25,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0xd0,0xd1,0xd2,0xd3,-1};
    for(int i=0;ff[i]>=0;i++) FFOP[ff[i]]=1;
}
static int digram(uint8_t*o,int len){
    int s=0;
    for(int i=0;i<len-1;i++){
        uint8_t a=o[i],b=o[i+1];
        if(a>=0x40&&a<=0x4f&&REXOP[b]) s++;
        else if(a==0x0f&&OF2[b]) s++;
        else if(a==0xe8||a==0xe9) s++;
        else if(a==0xff&&FFOP[b]) s++;
    }
    return s;
}
int main(int argc,char**argv){
    setvbuf(stdout,NULL,_IONBF,0);
    rawlen=loadf("raw_3829.bin",raw); if(rawlen<=0)return 1;
    int FOLD=190;
    { uint8_t b=(uint8_t)FOLD; for(int i=0;i<rawlen;i++){ b=(uint8_t)(b*0x6d+0x39); decF[i]=raw[i]^b; } }
    init_tables();
    uint64_t START=argc>1?strtoull(argv[1],0,0):0;
    uint64_t END  =argc>2?strtoull(argv[2],0,0):0x100000000ULL;
    int THRESH=argc>3?atoi(argv[3]):8;
    int NB=256;
    uint8_t out[320];
    for(uint64_t seed=START;seed<END;seed++){
        if((seed&0x7FFFFFF)==0) fprintf(stderr,"[%llx] %.1f%%\n",(unsigned long long)START,100.0*(seed-START)/(END-START));
        uint32_t st=(uint32_t)seed; int i=0,c=0;
        while(i<rawlen && c<NB){ out[c++]=decF[i]; st=st*1103515245u+12345u; uint32_t sk=(st%3)+1; for(uint32_t k=0;k<sk;k++) st=st*1103515245u+12345u; i+=1+sk; }
        if(c<NB) continue;
        if(digram(out,c)>=THRESH){ printf("SEED=%u score=%d\n",(uint32_t)seed,digram(out,c)); }
    }
    return 0;
}
