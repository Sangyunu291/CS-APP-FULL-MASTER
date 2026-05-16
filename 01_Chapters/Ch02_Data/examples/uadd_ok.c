#include <stdio.h>


int uadd_ok(unsigned x, unsigned y)
{
    return (x+y>=x);
}

int main()
{
    printf("%d\n", uadd_ok((unsigned)0xFFFFFFFF, (unsigned)0x00000000));
    printf("%d\n", uadd_ok((unsigned)0xFFFFFFFF, (unsigned)0x00000001));

    return 0;
}