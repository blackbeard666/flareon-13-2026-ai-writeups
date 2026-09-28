#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "md5.h"

// func_0x9070 style hash h=h*129+c ; seed const 0x2437 ; hash129 uses 0x2547 but we only need func_0x9070 here
#define M32 0xffffffffu
static uint32_t INV129;

static uint32_t hstr(uint32_t s,const char*p){ while(*p){ s=s*129u + (uint32_t)(unsigned char)*p; p++; } return s; }
static uint32_t peeln(uint32_t s,const char*digs,int len){ for(int i=len-1;i>=0;i--) s=(s-(uint32_t)(unsigned char)digs[i])*INV129; return s; }

// open-addressing hash table: state -> (A,B) packed
#define TBLBITS 28
#define TBLSIZE (1u<<TBLBITS)
#define TBLMASK (TBLSIZE-1)
static uint32_t *KEYS; static uint32_t *VALS; // KEYS[i]=state (0=empty sentinel handled), VALS[i]=A<<16|B
static uint8_t *USED;

static void tput(uint32_t st,uint32_t val){
    uint32_t h=(st*2654435761u)&TBLMASK;
    while(USED[h]){ if(KEYS[h]==st) return; h=(h+1)&TBLMASK; }
    USED[h]=1; KEYS[h]=st; VALS[h]=val;
}
static int tget(uint32_t st,uint32_t *outval){
    uint32_t h=(st*2654435761u)&TBLMASK;
    while(USED[h]){ if(KEYS[h]==st){*outval=VALS[h];return 1;} h=(h+1)&TBLMASK; }
    return 0;
}

static uint32_t SEED=1116755918u;
static uint8_t foldof(const char*inp,int len,uint32_t key){
    uint8_t m2[64]; memcpy(m2,inp,len);
    m2[len]=key&0xff;m2[len+1]=(key>>8)&0xff;m2[len+2]=(key>>16)&0xff;m2[len+3]=(key>>24)&0xff;
    uint8_t d2[16]; md5_small(m2,len+4,d2); uint8_t f=0; for(int i=0;i<16;i++) f=(uint8_t)(f*0x1f+d2[i]); return f;
}
static int checkfold(const char*inp,int len){
    if(foldof(inp,len,3829)!=190) return 0;
    if(foldof(inp,len,3827)!=90) return 0;
    if(foldof(inp,len,3824)!=116) return 0;
    if(foldof(inp,len,3822)!=146) return 0;
    return 1;
}

int main(int argc,char**argv){
    setvbuf(stdout,NULL,_IONBF,0);
    for(uint32_t x=0;x<0x100000000ULL;x++){ if((129u*x)==1u){INV129=x;break;} } // inverse mod 2^32
    KEYS=calloc(TBLSIZE,4); VALS=calloc(TBLSIZE,4); USED=calloc(TBLSIZE,1);
    int RA=argc>1?atoi(argv[1]):5000, RB=argc>2?atoi(argv[2]):5000;
    char tmp[24];
    for(int A=0;A<RA;A++){
        int la=snprintf(tmp,sizeof(tmp),"%d-",A);
        uint32_t sA=hstr(0x2437u,tmp);
        for(int B=0;B<RB;B++){
            snprintf(tmp,sizeof(tmp),"%d-",B);
            tput(hstr(sA,tmp), ((uint32_t)A<<16)|(uint32_t)B);
        }
    }
    fprintf(stderr,"forward built RA=%d RB=%d\n",RA,RB);
    // backward: C from 0..2^32, maintain decimal digits incrementally
    char dig[12]; int dl=1; dig[0]='0';
    unsigned long long collisions=0, checks=0;
    for(unsigned long long C=0; C<0x100000000ULL; C++){
        uint32_t s=peeln(SEED,dig,dl);
        uint32_t val;
        if(tget(s,&val)){
            collisions++;
            int A=val>>16, B=val&0xffff;
            char inp[40]; int L=snprintf(inp,sizeof(inp),"%d-%d-",A,B);
            memcpy(inp+L,dig,dl); int TL=L+dl; inp[TL]=0;
            checks++;
            if(checkfold(inp,TL)){ printf("*** REAL INPUT: %s\n",inp); }
        }
        // increment decimal digits (dig is big-endian decimal of C+1)
        int i=dl-1;
        while(i>=0){ if(dig[i]<'9'){dig[i]++;break;} dig[i]='0'; i--; }
        if(i<0){ memmove(dig+1,dig,dl); dig[0]='1'; dl++; }
        if((C&0xFFFFFFF)==0) fprintf(stderr,"C=%llu coll=%llu\n",C,collisions);
    }
    fprintf(stderr,"done coll=%llu checks=%llu\n",collisions,checks);
    return 0;
}
