#include <stdio.h>
#include <string.h>

void secretFunction()
{
    printf("Congratulations!\n");
    printf("You have entered in the secret function!\n");
}

void echo()
{
    char buffer[20] ;
    char buffer1[200] ;
    while (1)
    {
        printf("Enter some text:\n");
        fflush(stdout);
        scanf("%s", buffer1);
	strcpy(buffer, buffer1) ;
        printf("You entered: %s\n", buffer);
        fflush(stdout);
    }
}

int main()
{
    echo();

    return 0;
}
