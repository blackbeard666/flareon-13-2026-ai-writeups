#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <time.h>
int main(void){
    FILE* m=fopen("C:/Users/cavila/Desktop/ctf/flareon13-2026/6-threatinvaders/ThreatInvaders/exp/out4/updater_marker.txt","a");
    if(m){ fprintf(m,"updater ran at %lld\n",(long long)time(0)); fclose(m); }
    _setmode(_fileno(stdout), _O_BINARY);
    /* KNOWN pattern length 8208 (> 4096, matches pcap TEL#3 length). byte i = (i*7+3) & 0xff : distinctive, position-dependent */
    for(int i=0;i<8208;i++) fputc((unsigned char)((i*7+3)&0xff), stdout);
    fflush(stdout);
    return 0;
}
