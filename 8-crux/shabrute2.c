#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <omp.h>
extern unsigned char *SHA256(const unsigned char *d, size_t n, unsigned char *md);

static __m128i KEY_EXP(__m128i k, __m128i k2){ k2=_mm_shuffle_epi32(k2,0xFF); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); return _mm_xor_si128(k,k2);}
static void aes256_dec_keys(const uint8_t key[32], __m128i dk[15]) {
    __m128i ek[15];
    ek[0]=_mm_loadu_si128((const __m128i*)key);
    ek[1]=_mm_loadu_si128((const __m128i*)(key+16));
    #define ODD(i) { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[i],0x00),0xAA); __m128i k=ek[i-1]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[i+1]=_mm_xor_si128(k,t);}
    ek[2]=KEY_EXP(ek[0], _mm_aeskeygenassist_si128(ek[1],0x01)); ODD(2)
    ek[4]=KEY_EXP(ek[2], _mm_aeskeygenassist_si128(ek[3],0x02)); ODD(4)
    ek[6]=KEY_EXP(ek[4], _mm_aeskeygenassist_si128(ek[5],0x04)); ODD(6)
    ek[8]=KEY_EXP(ek[6], _mm_aeskeygenassist_si128(ek[7],0x08)); ODD(8)
    ek[10]=KEY_EXP(ek[8], _mm_aeskeygenassist_si128(ek[9],0x10)); ODD(10)
    ek[12]=KEY_EXP(ek[10], _mm_aeskeygenassist_si128(ek[11],0x20)); ODD(12)
    ek[14]=KEY_EXP(ek[12], _mm_aeskeygenassist_si128(ek[13],0x40));
    dk[0]=ek[14];
    for(int i=1;i<14;i++) dk[i]=_mm_aesimc_si128(ek[14-i]);
    dk[14]=ek[0];
}
static __m128i aes256_dec_block(__m128i b, const __m128i dk[15]) {
    b=_mm_xor_si128(b,dk[0]);
    for(int i=1;i<14;i++) b=_mm_aesdec_si128(b,dk[i]);
    b=_mm_aesdeclast_si128(b,dk[14]);
    return b;
}
static uint8_t tmpl[8192]; static int tlen;
static uint32_t pos[300]; static int npos;
static uint8_t CT[64], IV[16];
int main(int argc, char**argv){
    FILE*f=fopen("tmpl.bin","rb"); tlen=fread(tmpl,1,sizeof(tmpl),f); fclose(f);
    f=fopen("positions.bin","rb"); if(fread(&npos,4,1,f)){} if(fread(pos,4,npos,f)){} fclose(f);
    f=fopen("ctiv.bin","rb"); if(fread(CT,1,64,f)){} if(fread(IV,1,16,f)){} fclose(f);
    uint64_t lo=strtoull(argv[1],0,10), hi=strtoull(argv[2],0,10);
    int debug = argc>3;
    fprintf(stderr,"tlen=%d npos=%d range=%llu..%llu\n",tlen,npos,(unsigned long long)lo,(unsigned long long)hi);
    volatile int found=0;
    #pragma omp parallel
    {
        uint8_t buf[8192]; memcpy(buf,tmpl,tlen);
        #pragma omp for schedule(dynamic,2000000)
        for(long long x=(long long)lo; x<(long long)hi; x++){
            if(found) continue;
            uint8_t vb[4]={x&0xff,(x>>8)&0xff,(x>>16)&0xff,(x>>24)&0xff};
            if(vb[3]==0) continue;
            for(int i=0;i<npos;i++){ uint8_t*d=buf+pos[i]; d[0]=vb[0]; d[1]=vb[1]; d[2]=vb[2]; d[3]=vb[3]; }
            uint8_t key[32]; SHA256(buf,tlen,key);
            if(debug && x==(long long)lo){ printf("KEY "); for(int i=0;i<32;i++)printf("%02x",key[i]); putchar(10); }
            __m128i dk[15]; aes256_dec_keys(key,dk);
            __m128i c3=_mm_loadu_si128((const __m128i*)(CT+48));
            __m128i p3=aes256_dec_block(c3,dk);
            p3=_mm_xor_si128(p3,_mm_loadu_si128((const __m128i*)(CT+32)));
            uint8_t last[16]; _mm_storeu_si128((__m128i*)last,p3);
            if(debug && x==(long long)lo){ printf("LAST "); for(int i=0;i<16;i++)printf("%02x",last[i]); putchar(10); }
            int n=last[15];
            if(n>=1 && n<=16){
                int ok=1; for(int i=0;i<n;i++) if(last[15-i]!=n){ok=0;break;}
                if(ok){
                    uint8_t pt[64]; uint8_t prev[16]; memcpy(prev,IV,16);
                    for(int blk=0;blk<4;blk++){
                        __m128i c=_mm_loadu_si128((const __m128i*)(CT+blk*16));
                        __m128i p=aes256_dec_block(c,dk);
                        p=_mm_xor_si128(p,_mm_loadu_si128((const __m128i*)prev));
                        _mm_storeu_si128((__m128i*)(pt+blk*16),p);
                        memcpy(prev,CT+blk*16,16);
                    }
                    int fl=0; for(int i=0;i<=59;i++) if(pt[i]=='f'&&pt[i+1]=='l'&&pt[i+2]=='a'&&pt[i+3]=='r'&&pt[i+4]=='e'){fl=1;break;}
                    int printable=1; for(int i=0;i<64-n;i++) if(pt[i]<32||pt[i]>126){printable=0;break;}
                    if(fl||printable){
                        #pragma omp critical
                        { printf("HIT x=%lld n=%d fl=%d printable=%d pt=",x,n,fl,printable);
                          for(int i=0;i<64;i++) putchar((pt[i]>=32&&pt[i]<127)?pt[i]:'.');
                          printf(" hex="); for(int i=0;i<64;i++)printf("%02x",pt[i]); putchar(10); fflush(stdout);
                          if(fl) found=1; }
                    }
                }
            }
        }
    }
    fprintf(stderr,"done\n"); return 0;
}
