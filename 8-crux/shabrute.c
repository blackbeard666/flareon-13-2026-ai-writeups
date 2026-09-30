// SHA-NI + AES-NI + OpenMP brute for ch8 crux leaf-val.
// flag = pkcs7_unpad(AES-256-CBC-dec(CT, key=SHA256(M), IV)); M = cert, 216 uniform 4-byte leaf-val slots.
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <omp.h>

/* ---- SHA-256 SHA-NI: canonical noloader/SHA-Intrinsics sha256_process_x86 ---- */
static void sha256_process(uint32_t state[8], const uint8_t data[], uint32_t length)
{
    __m128i STATE0, STATE1;
    __m128i MSG, TMP;
    __m128i MSG0, MSG1, MSG2, MSG3;
    __m128i ABEF_SAVE, CDGH_SAVE;
    const __m128i MASK = _mm_set_epi64x(0x0c0d0e0f08090a0bULL, 0x0405060700010203ULL);

    TMP = _mm_loadu_si128((const __m128i*) &state[0]);
    STATE1 = _mm_loadu_si128((const __m128i*) &state[4]);

    TMP = _mm_shuffle_epi32(TMP, 0xB1);          /* CDAB */
    STATE1 = _mm_shuffle_epi32(STATE1, 0x1B);    /* EFGH */
    STATE0 = _mm_alignr_epi8(TMP, STATE1, 8);    /* ABEF */
    STATE1 = _mm_blend_epi16(STATE1, TMP, 0xF0); /* CDGH */

    while (length >= 64)
    {
        ABEF_SAVE = STATE0;
        CDGH_SAVE = STATE1;

        MSG0 = _mm_loadu_si128((const __m128i*) (data+0));
        MSG0 = _mm_shuffle_epi8(MSG0, MASK);
        MSG = _mm_add_epi32(MSG0, _mm_set_epi64x(0xE9B5DBA5B5C0FBCFULL, 0x71374491428A2F98ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);

        MSG1 = _mm_loadu_si128((const __m128i*) (data+16));
        MSG1 = _mm_shuffle_epi8(MSG1, MASK);
        MSG = _mm_add_epi32(MSG1, _mm_set_epi64x(0xAB1C5ED5923F82A4ULL, 0x59F111F13956C25BULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG0 = _mm_sha256msg1_epu32(MSG0, MSG1);

        MSG2 = _mm_loadu_si128((const __m128i*) (data+32));
        MSG2 = _mm_shuffle_epi8(MSG2, MASK);
        MSG = _mm_add_epi32(MSG2, _mm_set_epi64x(0x550C7DC3243185BEULL, 0x12835B01D807AA98ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG1 = _mm_sha256msg1_epu32(MSG1, MSG2);

        MSG3 = _mm_loadu_si128((const __m128i*) (data+48));
        MSG3 = _mm_shuffle_epi8(MSG3, MASK);
        MSG = _mm_add_epi32(MSG3, _mm_set_epi64x(0xC19BF1749BDC06A7ULL, 0x80DEB1FE72BE5D74ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG3, MSG2, 4);
        MSG0 = _mm_add_epi32(MSG0, TMP);
        MSG0 = _mm_sha256msg2_epu32(MSG0, MSG3);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG2 = _mm_sha256msg1_epu32(MSG2, MSG3);

        MSG = _mm_add_epi32(MSG0, _mm_set_epi64x(0x240CA1CC0FC19DC6ULL, 0xEFBE4786E49B69C1ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG0, MSG3, 4);
        MSG1 = _mm_add_epi32(MSG1, TMP);
        MSG1 = _mm_sha256msg2_epu32(MSG1, MSG0);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG3 = _mm_sha256msg1_epu32(MSG3, MSG0);

        MSG = _mm_add_epi32(MSG1, _mm_set_epi64x(0x76F988DA5CB0A9DCULL, 0x4A7484AA2DE92C6FULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG1, MSG0, 4);
        MSG2 = _mm_add_epi32(MSG2, TMP);
        MSG2 = _mm_sha256msg2_epu32(MSG2, MSG1);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG0 = _mm_sha256msg1_epu32(MSG0, MSG1);

        MSG = _mm_add_epi32(MSG2, _mm_set_epi64x(0xBF597FC7B00327C8ULL, 0xA831C66D983E5152ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG2, MSG1, 4);
        MSG3 = _mm_add_epi32(MSG3, TMP);
        MSG3 = _mm_sha256msg2_epu32(MSG3, MSG2);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG1 = _mm_sha256msg1_epu32(MSG1, MSG2);

        MSG = _mm_add_epi32(MSG3, _mm_set_epi64x(0x1429296706CA6351ULL, 0xD5A79147C6E00BF3ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG3, MSG2, 4);
        MSG0 = _mm_add_epi32(MSG0, TMP);
        MSG0 = _mm_sha256msg2_epu32(MSG0, MSG3);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG2 = _mm_sha256msg1_epu32(MSG2, MSG3);

        MSG = _mm_add_epi32(MSG0, _mm_set_epi64x(0x53380D134D2C6DFCULL, 0x2E1B213827B70A85ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG0, MSG3, 4);
        MSG1 = _mm_add_epi32(MSG1, TMP);
        MSG1 = _mm_sha256msg2_epu32(MSG1, MSG0);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG3 = _mm_sha256msg1_epu32(MSG3, MSG0);

        MSG = _mm_add_epi32(MSG1, _mm_set_epi64x(0x92722C8581C2C92EULL, 0x766A0ABB650A7354ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG1, MSG0, 4);
        MSG2 = _mm_add_epi32(MSG2, TMP);
        MSG2 = _mm_sha256msg2_epu32(MSG2, MSG1);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG0 = _mm_sha256msg1_epu32(MSG0, MSG1);

        MSG = _mm_add_epi32(MSG2, _mm_set_epi64x(0xC76C51A3C24B8B70ULL, 0xA81A664BA2BFE8A1ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG2, MSG1, 4);
        MSG3 = _mm_add_epi32(MSG3, TMP);
        MSG3 = _mm_sha256msg2_epu32(MSG3, MSG2);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG1 = _mm_sha256msg1_epu32(MSG1, MSG2);

        MSG = _mm_add_epi32(MSG3, _mm_set_epi64x(0x106AA070F40E3585ULL, 0xD192E819D6990624ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG3, MSG2, 4);
        MSG0 = _mm_add_epi32(MSG0, TMP);
        MSG0 = _mm_sha256msg2_epu32(MSG0, MSG3);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG2 = _mm_sha256msg1_epu32(MSG2, MSG3);

        MSG = _mm_add_epi32(MSG0, _mm_set_epi64x(0x34B0BCB52748774CULL, 0x1E376C0819A4C116ULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG0, MSG3, 4);
        MSG1 = _mm_add_epi32(MSG1, TMP);
        MSG1 = _mm_sha256msg2_epu32(MSG1, MSG0);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);
        MSG3 = _mm_sha256msg1_epu32(MSG3, MSG0);

        MSG = _mm_add_epi32(MSG1, _mm_set_epi64x(0x682E6FF35B9CCA4FULL, 0x748F82EE4ED8AA4AULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG1, MSG0, 4);
        MSG2 = _mm_add_epi32(MSG2, TMP);
        MSG2 = _mm_sha256msg2_epu32(MSG2, MSG1);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);

        MSG = _mm_add_epi32(MSG2, _mm_set_epi64x(0x8CC7020884C87814ULL, 0x78A5636F748F82EEULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        TMP = _mm_alignr_epi8(MSG2, MSG1, 4);
        MSG3 = _mm_add_epi32(MSG3, TMP);
        MSG3 = _mm_sha256msg2_epu32(MSG3, MSG2);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);

        MSG = _mm_add_epi32(MSG3, _mm_set_epi64x(0xC67178F2BEF9A3F7ULL, 0xA4506CEB90BEFFFAULL));
        STATE1 = _mm_sha256rnds2_epu32(STATE1, STATE0, MSG);
        MSG = _mm_shuffle_epi32(MSG, 0x0E);
        STATE0 = _mm_sha256rnds2_epu32(STATE0, STATE1, MSG);

        STATE0 = _mm_add_epi32(STATE0, ABEF_SAVE);
        STATE1 = _mm_add_epi32(STATE1, CDGH_SAVE);

        data += 64;
        length -= 64;
    }

    TMP = _mm_shuffle_epi32(STATE0, 0x1B);       /* FEBA */
    STATE1 = _mm_shuffle_epi32(STATE1, 0xB1);    /* DCHG */
    STATE0 = _mm_blend_epi16(TMP, STATE1, 0xF0); /* DCBA */
    STATE1 = _mm_alignr_epi8(STATE1, TMP, 8);    /* ABEF */

    _mm_storeu_si128((__m128i*) &state[0], STATE0);
    _mm_storeu_si128((__m128i*) &state[4], STATE1);
}

static void sha256(const uint8_t *msg, size_t len, uint8_t out[32]) {
    uint32_t state[8] = {0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19};
    // build padded buffer
    size_t padded = ((len + 8) / 64 + 1) * 64;
    uint8_t *buf = (uint8_t*)malloc(padded);
    memcpy(buf, msg, len);
    buf[len] = 0x80;
    memset(buf+len+1, 0, padded-len-1-8);
    uint64_t bits = (uint64_t)len * 8;
    for (int i=0;i<8;i++) buf[padded-1-i] = (bits >> (8*i)) & 0xff;
    sha256_process(state, buf, (uint32_t)padded);
    for (int i=0;i<8;i++){ out[i*4]=state[i]>>24; out[i*4+1]=state[i]>>16; out[i*4+2]=state[i]>>8; out[i*4+3]=state[i]; }
    free(buf);
}

/* ---- AES-256 decrypt one block via AES-NI ---- */
static __m128i KEY_EXP(__m128i k, __m128i k2){ k2=_mm_shuffle_epi32(k2,0xFF); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); return _mm_xor_si128(k,k2);}
static void aes256_dec_keys(const uint8_t key[32], __m128i dk[15]) {
    __m128i ek[15];
    ek[0]=_mm_loadu_si128((const __m128i*)key);
    ek[1]=_mm_loadu_si128((const __m128i*)(key+16));
    #define EXPAND(i,rc1,rc2) \
        ek[i]=KEY_EXP(ek[i-2], _mm_aeskeygenassist_si128(ek[i-1], rc1)); \
        { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[i], 0x00),0xAA); \
          __m128i k=ek[i-1]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[i+1]=_mm_xor_si128(k,t);} \
        (void)rc2;
    // AES-256 schedule
    ek[2]=KEY_EXP(ek[0], _mm_aeskeygenassist_si128(ek[1],0x01));
    { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[2],0x00),0xAA); __m128i k=ek[1]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[3]=_mm_xor_si128(k,t);}
    ek[4]=KEY_EXP(ek[2], _mm_aeskeygenassist_si128(ek[3],0x02));
    { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[4],0x00),0xAA); __m128i k=ek[3]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[5]=_mm_xor_si128(k,t);}
    ek[6]=KEY_EXP(ek[4], _mm_aeskeygenassist_si128(ek[5],0x04));
    { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[6],0x00),0xAA); __m128i k=ek[5]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[7]=_mm_xor_si128(k,t);}
    ek[8]=KEY_EXP(ek[6], _mm_aeskeygenassist_si128(ek[7],0x08));
    { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[8],0x00),0xAA); __m128i k=ek[7]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[9]=_mm_xor_si128(k,t);}
    ek[10]=KEY_EXP(ek[8], _mm_aeskeygenassist_si128(ek[9],0x10));
    { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[10],0x00),0xAA); __m128i k=ek[9]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[11]=_mm_xor_si128(k,t);}
    ek[12]=KEY_EXP(ek[10], _mm_aeskeygenassist_si128(ek[11],0x20));
    { __m128i t=_mm_shuffle_epi32(_mm_aeskeygenassist_si128(ek[12],0x00),0xAA); __m128i k=ek[11]; k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); k=_mm_xor_si128(k,_mm_slli_si128(k,4)); ek[13]=_mm_xor_si128(k,t);}
    ek[14]=KEY_EXP(ek[12], _mm_aeskeygenassist_si128(ek[13],0x40));
    // decryption keys: dk[0]=ek[14], dk[14]=ek[0], middle = aesimc(ek[14-i])
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
    f=fopen("positions.bin","rb"); fread(&npos,4,1,f); fread(pos,4,npos,f); fclose(f);
    f=fopen("ctiv.bin","rb"); fread(CT,1,64,f); fread(IV,1,16,f); fclose(f);
    uint64_t lo=strtoull(argv[1],0,10), hi=strtoull(argv[2],0,10);
    int debug = argc>3;
    fprintf(stderr,"tlen=%d npos=%d range=%llu..%llu debug=%d\n",tlen,npos,(unsigned long long)lo,(unsigned long long)hi,debug);
    volatile int found=0;
    #pragma omp parallel
    {
        uint8_t buf[8192];
        memcpy(buf,tmpl,tlen);
        #pragma omp for schedule(dynamic,1000000)
        for(long long x=(long long)lo; x<(long long)hi; x++){
            if(found) continue;
            uint8_t vb[4]={x&0xff,(x>>8)&0xff,(x>>16)&0xff,(x>>24)&0xff};
            if(vb[3]==0) continue;
            for(int i=0;i<npos;i++){ uint8_t*d=buf+pos[i]; d[0]=vb[0]; d[1]=vb[1]; d[2]=vb[2]; d[3]=vb[3]; }
            uint8_t key[32]; sha256(buf,tlen,key);
            if(debug && x==(long long)lo){ printf("KEY "); for(int i=0;i<32;i++)printf("%02x",key[i]); putchar(10); }
            __m128i dk[15]; aes256_dec_keys(key,dk);
            // decrypt last block (CT[48:64]) XOR CT[32:48]
            __m128i c3=_mm_loadu_si128((const __m128i*)(CT+48));
            __m128i p3=aes256_dec_block(c3,dk);
            p3=_mm_xor_si128(p3,_mm_loadu_si128((const __m128i*)(CT+32)));
            uint8_t last[16]; _mm_storeu_si128((__m128i*)last,p3);
            if(debug && x==(long long)lo){ printf("LAST "); for(int i=0;i<16;i++)printf("%02x",last[i]); putchar(10); }
            int n=last[15];
            if(n>=1 && n<=16){
                int ok=1; for(int i=0;i<n;i++) if(last[15-i]!=n){ok=0;break;}
                if(ok){
                    // full decrypt to check ascii/flare
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
                          if(fl) found=1;
                        }
                    }
                }
            }
        }
    }
    fprintf(stderr,"done\n");
    return 0;
}
