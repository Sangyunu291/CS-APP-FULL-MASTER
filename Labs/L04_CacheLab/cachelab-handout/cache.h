#include "cache_address.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

extern int CACHE_EVICTION;
extern int CACHE_HIT;
extern int CACHE_MISS;

typedef struct _Entry {
    int valid_bit;
    unsigned long tag;
    int LRU_field;
} Entry;

typedef struct _Set {
    Entry *entry_arr;
    int visit_cnt;
} Set;

typedef struct _Cache {
    int entry_num;
    Cache_address *cache_address_parser;
    Set *set_arr;
} Cache;

void Entry_init(Entry* entry);

void set_init(Set* set, int entry_num);

void cache_init(Cache* cache, Cache_address* cache_address_parser, int entry_num);
int cache_load(Cache* cache, unsigned long start_address, int size);
int cache_store(Cache* cache, unsigned long start_address, int size);
void free_cache(Cache* cache);


