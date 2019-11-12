#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>

void winner()
{
  puts("\nKeep Calm and Free The memory\n");
  exit(0);
}

void build_key(int *k)
{
  int i;
  for (i=0; i<7; i++)
    k[i] = rand() %100+1;
}
void crypt(char *f, int *k, int *s)
{
    int i;
    for (i=0; i<7;i++)
        s[i] = k[i]+f[i];

}

int check_keys(int *s, int *s1)
{
  int i=0;
  for(;i<7;i++)
    if(s[i]!=s1[i])
      return 0;
  return 1;

}

char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) 
    {
        --size;
        size_t n;
        for (n = 0; n < size; n++) 
        {
          int key = rand() % (int) (sizeof charset - 1);
          str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}


int main()
{
    srand ((unsigned) time(NULL) * getpid());
    int i,addr,k[8],keyinput[7],secret[7];

    build_key(k);
    char input[9],leak[10];
    char *p = malloc(24);
    rand_string(p,8);
    crypt(p,k,secret);
    strncpy(p+8,p,8);
    strncpy(p+16,p,8);
    free(p);
    while(1)
    {
      printf("Address: ");
      fgets(leak,12,stdin);
      addr = atoi(leak);
      printf("\n%s\n",addr);
      puts("Now insert Secret: ");
      fgets(input,9, stdin);
      crypt(input,k,keyinput);
      if (check_keys(keyinput,secret))
        winner();
      else
        printf("\nNope\n");
           
    }
    return 0;
}
