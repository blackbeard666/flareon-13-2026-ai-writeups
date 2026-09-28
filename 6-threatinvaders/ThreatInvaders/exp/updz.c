#include <stdio.h>
#include <io.h>
#include <fcntl.h>
int main(void){ _setmode(_fileno(stdout),_O_BINARY);
  for(int i=0;i<6000;i++) fputc(0x00, stdout); fflush(stdout); return 0; }
