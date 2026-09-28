#ifndef MD5_H
#define MD5_H
#include <stdint.h>
#include <string.h>
typedef struct { uint32_t a,b,c,d; } md5ctx;
static const uint32_t K[64]={
0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,
0x698098d8,0x8b44f7af,0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,
0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,
0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,0xf6bb4b60,0xbebfbc70,
0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,
0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,
0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
static const int S[64]={7,12,17,22,7,12,17,22,7,12,17,22,7,12,17,22,
5,9,14,20,5,9,14,20,5,9,14,20,5,9,14,20,
4,11,16,23,4,11,16,23,4,11,16,23,4,11,16,23,
6,10,15,21,6,10,15,21,6,10,15,21,6,10,15,21};
#define ROTL(x,c) (((x)<<(c))|((x)>>(32-(c))))
// md5 of msg of len<=55 (single block)
static void md5_small(const uint8_t*msg,int len,uint8_t out[16]){
    uint8_t blk[64]; memset(blk,0,64);
    memcpy(blk,msg,len); blk[len]=0x80;
    uint64_t bits=(uint64_t)len*8;
    memcpy(blk+56,&bits,8);
    uint32_t M[16]; memcpy(M,blk,64);
    uint32_t a=0x67452301,b=0xefcdab89,c=0x98badcfe,d=0x10325476;
    uint32_t A=a,B=b,C=c,D=d;
    for(int i=0;i<64;i++){
        uint32_t F; int g;
        if(i<16){F=(B&C)|(~B&D);g=i;}
        else if(i<32){F=(D&B)|(~D&C);g=(5*i+1)&15;}
        else if(i<48){F=B^C^D;g=(3*i+5)&15;}
        else {F=C^(B|~D);g=(7*i)&15;}
        F=F+A+K[i]+M[g];
        A=D;D=C;C=B;B=B+ROTL(F,S[i]);
    }
    a+=A;b+=B;c+=C;d+=D;
    memcpy(out,&a,4);memcpy(out+4,&b,4);memcpy(out+8,&c,4);memcpy(out+12,&d,4);
}
#endif
