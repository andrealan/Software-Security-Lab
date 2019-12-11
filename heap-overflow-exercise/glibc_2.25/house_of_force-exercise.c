#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <malloc.h>

void win()
{
  printf("Congratulations, you win!!! You successfully changed the code flow\n\n");
}

int main(int argc, char *argv[])
{
   unsigned long return_address = 0xbffff224;
   char *buf1, *buf2, *buf3 ;
   int *c ;
   unsigned long evilsize ;
   int real_size ;

   if(argc != 4) return 0;
  
   printf("The goal of this attack is to execute the win function!!!\n") ;

   buf1 = malloc(256) ;
   strcpy(buf1, argv[1]) ;

   printf("%.8x[%.8x]\n", &return_address, *(&return_address)) ;
   printf("%.8x[%.8x]\n", &return_address+4, *(&return_address+4)) ;
   printf("%.8x[%.8x]\n", &return_address+8, *(&return_address+8)) ;
   printf("%.8x[%.8x]\n", &return_address+12, *(&return_address+12)) ;
   printf("%.8x[%.8x]\n", &return_address+16, *(&return_address+16)) ;

   real_size = malloc_usable_size(buf1) ; 

   printf("The chunk of 256 bytes has been allocated at %p.\n", buf1 - 2);
   printf("Real size (aligned and all that jazz) of our allocated chunk is %ld.\n", real_size + sizeof(long)*2);	

   intptr_t *ptr_top = (intptr_t *) ((char *)buf1 + real_size - sizeof(long)) ;
   printf("Top chunck is: %p\n", ptr_top) ;
   printf("New size of top chunk %#.8x\n", *((unsigned long long int *)((char *)ptr_top + sizeof(long))));

   evilsize = (unsigned long)return_address - sizeof(long)*4 - (unsigned long)ptr_top;
   printf("0x%.8x\n", evilsize) ;
   buf2 = malloc(strtoul(argv[2], NULL, 16)) ;
   printf("As expected, the new pointer is at the same place as the old top chunk: %p\n", buf2 - sizeof(long)*2);
 
   buf3 = malloc(256) ;
   printf("Pointer to the return address value: %p\n", buf3);
   strcpy(buf3, argv[3]) ;

   printf("return:%.8x:[%.8x]\n", return_address, *((int *)(return_address))) ;
   printf("buf3:%.8x:[%.8x]\n", buf3, *((int *)(buf3))) ;
   // address of win


   //free(buf3) ;
   //free(buf2) ;
   //free(buf1) ;

   return 0;


}
