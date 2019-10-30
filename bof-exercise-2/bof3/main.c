#include <stdio.h>
#include <string.h>

void echo()
{
    char buffer[50] ;
    char buffer1[100] ;
    
    printf("buffer:%p\n", buffer) ;
    printf("buffer1:%p\n", buffer1) ;
    printf("Enter some text:\n");
    gets(buffer1);
    strcpy(buffer, buffer1) ;
    printf("You entered: %s\n", buffer);
}

int main()
{
    echo();

    return 0;
}
