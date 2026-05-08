/* 
sx = -12345: c7 cf
usx = 53191 c7 cf 
ix = -12345 c7 cf ff ff <- 부호확장
uix = 53191 c7 cf 00 00 <- 0의확장
*/

#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int main()
{
    short sx = -12345;
    unsigned short usx = sx;

    printf("sx = %d:", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));
    printf("usx = %d", usx);
    show_bytes((byte_pointer)&usx, sizeof(unsigned short));

    int ix = sx;
    unsigned int uix = usx;

    printf("ix = %d", ix);
    show_bytes((byte_pointer)&ix, sizeof(int));
    printf("uix = %d", uix);
    show_bytes((byte_pointer)&uix, sizeof(unsigned int));

    return 0;
}