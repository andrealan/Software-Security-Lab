#include <stdio.h>
#include <string.h>

void echo()
{
    char buffer[20] ;
    char buffer1[100] ;
    
    printf("Enter some text:\n");
    fflush(stdout);
    scanf("%s", buffer1);
    strcpy(buffer, buffer1) ;
    printf("You entered: %s\n", buffer);
    fflush(stdout);
}

int main()
{
    echo();

    return 0;
}
