#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int security_check = 0 ;

int disable_security_check() {
security_check = 0 ;
}
int enable_security_check() {return 1;}


void win(){
	printf("Congratulation, you win!!!!\n") ;
}

void print_function(char *src){

        char dst[230] ;

	printf("dst is at %08x, now checking security\n", &dst);

        if (security_check)
	{
               strncpy(dst, src, 229);
	       dst[230] ='\0' ;
	       printf("%s\n", dst) ;	
	}

     else
	{
                /* Debugging only */
                strcpy(dst, src);
	}

}



int main(int argc, char *argv[]){

 
 int (*fp)() = NULL;
 char str[260] ;
 short check =0; 
 int i ;
 char index = 0;

        security_check = enable_security_check() ;

	for(i = 0; i < 268; i++) {
	  str[i] = getchar();
	  if(str[i] == 10) break;
	}
	str[i] = 0;
	
	if (fp != win && fp != NULL) fp() ;
	printf("Security Check:%d\n", security_check) ;

	/* print function name */
	print_function(str) ;

	exit(0) ;
 	printf("Never return from main\n") ;	
}
