#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>



int main(int argc, char *argv[])
{
   char *buf1, *buf2, *buf3 ;
   int *c ;
   int real_size ;

   if(argc != 4) return 0;

   buf1 = malloc(256) ;
   strcpy(buf1, argv[1]) ;

   real_size = malloc_usable_size(buf1) ; 
   intptr_t *ptr_top = (intptr_t *) ((char *)buf1 + real_size - sizeof(long)) ;
   printf("Top chunck is: %p\n", ptr_top) ;
   
   
   buf2 = malloc(strtoul(argv[2], NULL, 16)) ;
   buf3 = malloc(256) ;
   strcpy(buf3, argv[3]) ;

   free(buf3) ;
   free(buf2) ;
   free(buf1) ;

   return 0;


}
