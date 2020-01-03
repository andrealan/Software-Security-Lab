#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char string[100];

void lazy() {
  system(string);
}

void food(int magic) {
  if (magic == 0xdeadbeef) {
    strcat(string, "/bin");
  }
}

void feeling_sick(int magic1, int magic2, char *filename) {
  if (magic1 == 0xd15ea5e && magic2 == 0x0badf00d) {
    strcat(string, "/cat ");
    strcat(string, filename) ;
  }
}

void vuln(char *string) {
  char buffer[100] = {0};
  strcpy(buffer, string); 
}

int main(int argc, char** argv) {
  string[0] = 0;
  char filename[]="filename";
  char buf[50] ;

  printf("me Can I read the secret file?! \n\n");
  if (argc > 2) {
    strcpy(buf, argv[2]) ;
    vuln(argv[1]);
  } else {
    printf("You forgot to read me!!!\n");
  }
  return 0;
}
