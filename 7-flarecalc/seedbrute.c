#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

static uint8_t raw3829[4096]; static int len3829;
static uint8_t raw3827[4096]; static int len3827;
static uint8_t raw3824[4096]; static int len3824;

static int loadf(const char*fn, uint8_t*buf){ FILE*f=fopen(fn,"rb"); if(!f){perror(fn);return -1;} int n=fread(buf,1,4096,f); fclose(f); return n; }

// prologue templates (first bytes). 0xFF = wildcard.
typedef struct { uint8_t b[6]; int len; } Tmpl;
static Tmpl T[] = {
  {{0x48,0x89,0x5c,0x24},4},
  {{0x48,0x89,0x54,0x24,0x10},5},
  {{0x48,0x89,0x4c,0x24,0x08},5},
  {{0x48,0x89,0x74,0x24},4},
  {{0x48,0x89,0x7c,0x24},4},
  {{0x40,0x53,0x48,0x83,0xec},5},
  {{0x40,0x55,0x48,0x8b,0xec},5},
  {{0x4c,0x8b,0xdc,0x49,0x89},5},
  {{0x48,0x8b,0xc4,0x48,0x89},5},
  {{0x56,0x57,0x48,0x83,0xec},5},
  {{0x55,0x48,0x8b,0xec},4},
  {{0x53,0x48,0x83,0xec},4},
  {{0x48,0x83,0xec,0x28},4},
  {{0x48,0x83,0xec,0x38},4},
  {{0x48,0x83,0xec,0x48},4},
};
static int NT = sizeof(T)/sizeof(T[0]);

static int inv109;
#define MAXPOS 64
static uint8_t KS[256][MAXPOS]; // KS[fold][p]
static inline uint8_t ksbyte(uint8_t fold, int p){ return KS[fold][p]; }

int main(int argc,char**argv){
    setvbuf(stdout,NULL,_IONBF,0);
    uint64_t START = argc>1 ? (uint64_t)strtoull(argv[1],0,0) : 0;
    uint64_t END   = argc>2 ? (uint64_t)strtoull(argv[2],0,0) : 0x100000000ULL;
    len3829=loadf("raw_3829.bin",raw3829);
    len3827=loadf("raw_3827.bin",raw3827);
    len3824=loadf("raw_3824.bin",raw3824);
    if(len3829<=0)return 1;
    // inv of 109 mod 256
    for(int x=0;x<256;x++){ if(((109*x)&0xff)==1){inv109=x;break;} }
    // precompute keystream table: KS[fold][p] = b after (p+1) iterations of b=b*0x6d+0x39 from fold
    for(int fold=0;fold<256;fold++){ uint8_t b=(uint8_t)fold; for(int p=0;p<MAXPOS;p++){ b=(uint8_t)(b*0x6d+0x39); KS[fold][p]=b; } }

    int NPOS=8;
    int pos[32];
    long long found=0;
    for(uint64_t seed=START; seed<END; seed++){
        if((seed & 0xFFFFFFF)==0) fprintf(stderr,"[%s] seed=0x%llx found=%lld\n",argv[1]?argv[1]:"0",(unsigned long long)seed,found);
        // compute deinterleave positions for first NPOS outputs
        uint32_t st=(uint32_t)seed; int i=0; int ok=1;
        for(int j=0;j<NPOS;j++){
            pos[j]=i;
            uint32_t r=(st=st*1103515245u+12345u);
            uint32_t skip=(r%3)+1;
            for(uint32_t k=0;k<skip;k++) st=st*1103515245u+12345u;
            i+=1+skip;
            if(i>=len3829){ if(j<6){ok=0;} break; }
        }
        if(!ok) continue;
        // try templates on blob 3829
        for(int t=0;t<NT;t++){
            int L=T[t].len;
            // fold from output[0] = raw[pos0]^ks(fold,pos0) == T[0]; pos0=pos[0]=0
            uint8_t need_ks0 = raw3829[pos[0]] ^ T[t].b[0];
            // ks(fold,0)=fold*0x6d+0x39 == need_ks0 -> fold=(need_ks0-0x39)*inv109
            uint8_t fold = (uint8_t)(((int)need_ks0 - 0x39) * inv109);
            int match=1;
            for(int j=1;j<L;j++){
                uint8_t o = raw3829[pos[j]] ^ ksbyte(fold,pos[j]);
                if(o!=T[t].b[j]){ match=0; break; }
            }
            if(match){
                found++;
                printf("SEED=%u FOLD3829=%u TMPL=%d out=", (uint32_t)seed, fold, t);
                for(int j=0;j<NPOS && pos[j]<len3829;j++) printf("%02x", raw3829[pos[j]]^ksbyte(fold,pos[j]));
                printf("\n");
                if(found>2000){ printf("...too many, stopping\n"); return 0; }
            }
        }
    }
    fprintf(stderr,"done found=%lld\n",found);
    return 0;
}
