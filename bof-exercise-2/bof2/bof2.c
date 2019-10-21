#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void win()
{
 printf("\nc0d3 fl0w 5ucc355fully ch4n63d\n");
 exit(0);
}

int main(int argc, char *argv[])
{
  char buffer[64];
  if(argc == 1)
  {
    printf("Usage: %s argument\n", argv[0]);
    exit(1);
  }
  strcpy(buffer,argv[1]);
  printf("%s",buffer);
}
