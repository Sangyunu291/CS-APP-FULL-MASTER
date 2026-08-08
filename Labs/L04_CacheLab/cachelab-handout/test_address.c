#include <stdio.h>
#include "cache.h"

int ADDRESS_SIZE = 64;

int main()
{
    int tag_bit_num = 54, block_bit_num = 6, set_bit_num = 4, entry_num = 5;

    Cache *cache = malloc(sizeof(Cache));
    Cache_address *cache_address = malloc(sizeof(Cache_address));
    cache_address_init(cache_address, tag_bit_num, set_bit_num, block_bit_num);
    cache_init(cache, cache_address, entry_num);
    //cache_init(cache, cache_address, (int)pow(2, set_bit_num), entry_num);
}