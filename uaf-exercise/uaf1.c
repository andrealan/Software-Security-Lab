#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void free_memory(char *secret){ free(secret) ; }


char *input print_input(){

	char print[20] ;

	gets(input) ;
	strcpy(print, input) ;
	printf("%s\n", input) ;

}

void build_secret(int *k)
{
  int i;
  for (i=0; i<7; i++)
    k[i] = rand() %100+1;
  k[7] = '\0' ;
}
	



int main(int argc, char *argv[]){

 char *secret, input_secret ;
 char input[120] ;


 	printf("Successful exploit use after free vulnerabiliy\n") ;
 	secret = malloc(24) ;
	build_secret(secret) ;

	input =	get_input(str) ;
	input_secret = malloc(24) ;

	if(!strcmp(input_secret, secret))
	{
		printf("input secret is:%s\n", input_secret) ;
		printf("secret is:%s\n", secret) ;
		printf("You got high priviledge") ;
	}

}
