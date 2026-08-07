#include "cache.h"


int CACHE_HIT = 1;
int CACHE_MISS = 0;

void Entry_init(Entry* entry) 
{
    entry->valid_bit = 0;
    entry->tag = 0;
    entry->LRU_field = INT_MAX;
}

void set_init(Set *set, int entry_num)
{
    int i;

    set->visit_cnt = 0;
    set->entry_arr = malloc(sizeof(Entry)*entry_num);

    for (i = 0; i < entry_num; i++)
        Entry_init(&(set->entry_arr[i]));
}

void cache_init(Cache* cache, Cache_address* cache_address_parser, int set_num, int entry_num)
{
    int i;

    cache->entry_num = entry_num;
    cache->cache_address_parser = cache_address_parser;
    cache->set_arr = malloc(sizeof(Set)*set_num);
    
    for (i = 0; i < set_num; i++)
        set_init(&cache->set_arr[i], entry_num);
}

int cache_load(Cache* cache, unsigned long start_address, int size)
{
    int i;
    unsigned long tag = get_tag(cache->cache_address_parser, start_address);
    unsigned long set = get_set(cache->cache_address_parser, start_address);
    
    Entry *entry_arr = cache->set_arr[set].entry_arr;
    Entry *empty_entry = NULL;

    cache->set_arr[set].visit_cnt++;

    for (i = 0; i < cache->entry_num; i++) {
        if (!entry_arr[i].valid_bit)
            empty_entry = &entry_arr[i];

        if (entry_arr[i].valid_bit && tag == entry_arr[i].tag) {
            entry_arr[i].LRU_field = cache->set_arr[set].visit_cnt;
            return CACHE_HIT;
        }
    }

    int LRU_index = 0;

    if (empty_entry) {
        empty_entry->valid_bit = 1;
        empty_entry->tag = tag;
        empty_entry->LRU_field = cache->set_arr[set].visit_cnt;
    }

    else {
        /*LRU간단구현*/
        for (i = 0; i < cache->entry_num; i++) {
            if (entry_arr[LRU_index].LRU_field > entry_arr[i].LRU_field)
                LRU_index = i;
        }
        entry_arr[LRU_index].tag = tag;
        entry_arr[LRU_index].LRU_field = cache->set_arr[set].visit_cnt;
    }
    
    return CACHE_MISS;
}

int cache_store(Cache* cache, unsigned long start_address, int size)
{
          
    

}