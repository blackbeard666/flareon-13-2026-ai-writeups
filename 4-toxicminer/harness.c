/* Load ToxicMiner's mapped image at its preferred base and call the binary's
 * own key-derivation (FUN_140134ca0) and RC4 (FUN_140134d70) directly, so the
 * (modified) SHA is guaranteed byte-exact. Brute the volume-serial space for a
 * plaintext containing "flare-on.com". */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMGBASE 0x140000000ULL
#define KEYFN   (IMGBASE + 0x134ca0)
#define DECFN   (IMGBASE + 0x134d70)
#define CTVA    (IMGBASE + 0x1bd3b0)

typedef void (*keyfn_t)(uint32_t serial, uint32_t magic, void* out32);
typedef void (*decfn_t)(void* key, uint64_t keylen, void* ct, uint64_t ctlen, void* out);

int main(int argc, char** argv){
    uint64_t lo = strtoull(argv[1],0,0);
    uint64_t hi = strtoull(argv[2],0,0);

    FILE* f = fopen("image.bin","rb");
    if(!f){ fprintf(stderr,"no image.bin\n"); return 2; }
    fseek(f,0,SEEK_END); long sz=ftell(f); fseek(f,0,SEEK_SET);
    void* base = VirtualAlloc((LPVOID)IMGBASE, (SIZE_T)((sz+0xffff)&~0xffff),
                              MEM_RESERVE|MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if(base != (void*)IMGBASE){ fprintf(stderr,"alloc failed at base, got %p\n",base); return 3; }
    if(fread(base,1,sz,f)!=(size_t)sz){ fprintf(stderr,"read fail\n"); return 4; }
    fclose(f);

    keyfn_t keyfn = (keyfn_t)KEYFN;
    decfn_t decfn = (decfn_t)DECFN;
    unsigned char* ct = (unsigned char*)CTVA;

    unsigned char key[32];
    unsigned char pt[64];

    if(argc>3){ /* debug: dump key+pt for serial=lo */
        keyfn((uint32_t)lo, 0x0b501e7e, key);
        printf("key  "); for(int i=0;i<16;i++) printf("%02x",key[i]); printf("\n");
        decfn(key,0x10,ct,0x33,pt); pt[0x33]=0;
        printf("pt   "); for(int i=0;i<0x33;i++) printf("%02x",pt[i]); printf("\n");
        return 0;
    }
    for(uint64_t s=lo; s<hi; s++){
        keyfn((uint32_t)s, 0x0b501e7e, key);
        decfn(key, 0x10, ct, 0x33, pt);
        pt[0x33]=0;
        for(int off=0; off+12<=0x33; off++){
            if(memcmp(pt+off,"flare-on.com",12)==0){
                printf("SERIAL %08x : %.51s\n",(uint32_t)s,pt);
                fflush(stdout);
                break;
            }
        }
    }
    return 0;
}
