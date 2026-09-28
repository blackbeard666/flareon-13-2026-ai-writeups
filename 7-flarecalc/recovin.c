#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
// func_0x9070: s=0x2437; for c: s=s*0x81+ (signed char)c
static uint32_t h_str(uint32_t s,const char*p){ while(*p){ s=s*0x81u + (uint32_t)(int32_t)(int8_t)*p; p++; } return s; }
int main(int argc,char**argv){
    uint32_t SEED=1116755918u;
    int HI=argc>1?atoi(argv[1]):3000;
    char a[16],b[16],c[16];
    for(int A=0;A<HI;A++){
        int la=snprintf(a,sizeof(a),"%d-",A);
        uint32_t sA=h_str(0x2437u,a);
        for(int B=0;B<HI;B++){
            int lb=snprintf(b,sizeof(b),"%d-",B);
            uint32_t sAB=h_str(sA,b);
            for(int C=0;C<HI;C++){
                snprintf(c,sizeof(c),"%d",C);
                if(h_str(sAB,c)==SEED){ printf("MATCH %d-%d-%d\n",A,B,C); }
            }
        }
        if((A%200)==0) fprintf(stderr,"A=%d\n",A);
    }
    fprintf(stderr,"done\n");
    return 0;
}
