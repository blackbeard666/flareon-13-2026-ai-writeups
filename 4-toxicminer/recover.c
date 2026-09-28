/* FLARE-On 13 #4 ToxicMiner flag recovery.
 * The binary derives an RC4 key from the C: volume serial (a uint32) via a
 * word-oriented SHA-256d, then RC4-decrypts a 0x33-byte blob and prints it as
 * "Accepted: <flag>". We search the 2^32 serial space for the one that yields
 * a plaintext containing "flare-on.com".
 *
 * Key derivation (matches FUN_140134ca0 / FUN_140135240):
 *   SHA-256 compression operating on uint32 word arrays, no input byte-swap.
 *   round1 W = { serial, 0x0b501e7e, 0x80000000, 0..., 0x40 }
 *   round2 W = { round1_state[0..7], 0x80000000, 0..., 0x100 }
 *   key = LE bytes of round2_state[0..3]  (16 bytes)
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const uint32_t IV[8] = {
    0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,
    0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19};

static const uint32_t Kc[64] = {
0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};

#define ROTR(x,n) (((x)>>(n))|((x)<<(32-(n))))
#define EP0(x) (ROTR(x,2)^ROTR(x,13)^ROTR(x,22))
#define EP1(x) (ROTR(x,6)^ROTR(x,11)^ROTR(x,25))
#define S0(x)  (ROTR(x,7)^ROTR(x,18)^((x)>>3))
#define S1(x)  (ROTR(x,17)^ROTR(x,19)^((x)>>10))

static void compress(uint32_t H[8], const uint32_t Win[16]) {
    uint32_t w[64];
    for (int i=0;i<16;i++) w[i]=Win[i];
    for (int i=16;i<64;i++) w[i]=S1(w[i-2])+w[i-7]+S0(w[i-15])+w[i-16];
    uint32_t a=H[0],b=H[1],c=H[2],d=H[3],e=H[4],f=H[5],g=H[6],h=H[7];
    for (int i=0;i<64;i++){
        uint32_t t1=h+EP1(e)+((e&f)^(~e&g))+Kc[i]+w[i];
        uint32_t t2=EP0(a)+((a&b)^(a&c)^(b&c));
        h=g;g=f;f=e;e=d+t1;d=c;c=b;b=a;a=t1+t2;
    }
    H[0]+=a;H[1]+=b;H[2]+=c;H[3]+=d;H[4]+=e;H[5]+=f;H[6]+=g;H[7]+=h;
}

/* 0x33 = 51 bytes ciphertext */
static const unsigned char CT[51] = {
0xf4,0xf9,0x65,0x9f,0x31,0xf3,0xda,0x5c,0xf1,0x37,0xa1,0xb8,0xcf,0x90,0xa1,0x58,
0x1e,0xeb,0xe4,0x99,0xa7,0xc1,0x1b,0x15,0x02,0xaf,0x74,0x63,0xd3,0xb2,0x19,0x28,
0x66,0xde,0x3d,0xe9,0x71,0x63,0xe7,0x75,0xdf,0xe4,0xab,0x61,0x6f,0xb9,0x0c,0x27,
0x89,0xfc,0x87};

static int has_flare(const unsigned char* p){
    for (int off=0; off+12<=51; off++)
        if (memcmp(p+off,"flare-on.com",12)==0) return 1;
    return 0;
}

int main(int argc, char** argv){
    uint64_t lo = strtoull(argv[1],0,0);
    uint64_t hi = strtoull(argv[2],0,0);
    for (uint64_t s=lo; s<hi; s++){
        uint32_t H1[8]; memcpy(H1,IV,sizeof IV);
        uint32_t W1[16]={0};
        W1[0]=(uint32_t)s; W1[1]=0x0b501e7e; W1[2]=0x80000000; W1[15]=0x40;
        compress(H1,W1);
        uint32_t H2[8]; memcpy(H2,IV,sizeof IV);
        uint32_t W2[16]={0};
        for(int i=0;i<8;i++) W2[i]=H1[i];
        W2[8]=0x80000000; W2[15]=0x100;
        compress(H2,W2);
        unsigned char key[16];
        for(int i=0;i<4;i++){ key[i*4]=H2[i]&0xff; key[i*4+1]=(H2[i]>>8)&0xff;
                              key[i*4+2]=(H2[i]>>16)&0xff; key[i*4+3]=(H2[i]>>24)&0xff; }
        /* RC4 */
        unsigned char S[256];
        for(int i=0;i<256;i++) S[i]=(unsigned char)i;
        int j=0;
        for(int i=0;i<256;i++){ j=(j+S[i]+key[i&15])&0xff; unsigned char t=S[i];S[i]=S[j];S[j]=t; }
        unsigned char pt[52]; int ii=0,jj=0;
        for(int k=0;k<51;k++){ ii=(ii+1)&0xff; jj=(jj+S[ii])&0xff;
            unsigned char t=S[ii];S[ii]=S[jj];S[jj]=t;
            pt[k]=CT[k]^S[(S[ii]+S[jj])&0xff]; }
        pt[51]=0;
        if (has_flare(pt)) {
            printf("SERIAL %08x : %.51s\n",(uint32_t)s,pt);
            fflush(stdout);
        }
    }
    return 0;
}
