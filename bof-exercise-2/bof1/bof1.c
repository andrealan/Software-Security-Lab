#include <stdio.h>

int main() {
    int cookie;
    char buf[80];

    printf("buf: %08x cookie: %08x\n", &buf, &cookie);
    gets(buf);

    if (cookie == 0x01020305)
        printf("y0u w1n!\n");
}
