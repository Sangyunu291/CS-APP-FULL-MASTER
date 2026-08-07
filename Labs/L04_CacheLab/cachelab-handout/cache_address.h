typedef struct _Cache_address {
    int address_size;
    int tag_bit_num;
    int set_bit_num;
    int block_bit_num;
} Cache_address;


void cache_address_init(Cache_address *ca, int tag_bit_num, int set_bit_num, int block_bit_num);


unsigned long get_tag(Cache_address *ca, unsigned long start_address);
unsigned long get_set(Cache_address *ca, unsigned long start_address); 