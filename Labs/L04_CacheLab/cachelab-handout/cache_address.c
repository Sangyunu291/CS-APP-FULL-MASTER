#include "cache_address.h"

void cache_address_init(Cache_address *ca, int tag_bit_num, int set_bit_num, int block_bit_num)
{
    ca->tag_bit_num = tag_bit_num;
    ca->set_bit_num = set_bit_num;
    ca->block_bit_num = block_bit_num;
    ca->address_size = 64;
}

unsigned long get_tag(Cache_address *ca, unsigned long start_address)
{
    int right_shift_size = (ca->address_size) - (ca->tag_bit_num);
    return start_address >> right_shift_size;
}

unsigned long get_set(Cache_address *ca, unsigned long start_address)
{
    int left_shift_size = ca->tag_bit_num;
    int right_shift_size = (ca->address_size) - (ca->set_bit_num);
    return (start_address << left_shift_size) >> right_shift_size;
}