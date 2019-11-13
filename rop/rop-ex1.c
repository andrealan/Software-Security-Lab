#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


char str1[]= "Congratulations             " ;
char str2[] = "you win!" ;
char str3[] = "                           " ;

void join_string(char *dst, char *src) 
{
	strcat(dst, src) ;
}

void win()
{
  printf("%s\n", str3);
}

int main(int argc, char **argv)
{
  char buffer[128];

  printf("You win this game if you are able to compose the string Congratulations you win by using rop technique'\n");

  gets(buffer);

  printf("%s\n", buffer) ;

}
