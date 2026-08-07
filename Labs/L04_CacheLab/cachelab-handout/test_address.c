#include <stdio.h>
#include "cache_address.h"

int ADDRESS_SIZE = 64;

int main()
{
    unsigned long address = 0x123456789ABCDEF0;

    int s = 8;
    int b = 4;
    int t = ADDRESS_SIZE - (s + b);

    
    Cache_address ca;

    cache_address_init(&ca, t, s, b);
    
    printf("%lx\n", get_tag(&ca, address));
    printf("%lx\n", get_set(&ca, address));
    return 0;
}