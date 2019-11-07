#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void win()
{
printf("Congratulations, you win!!! You successfully changed the code flow\n");
}

void overflow_function (char *str)
{
  char buffer[20];

  strcpy(buffer, str);  // Function that copies str to buffer
}

int main()
{
  char big_string[128];
  int i;

  gets(big_string) ;
  big_string[128] = '\0';
  overflow_function(big_string);
  exit(0);
}
