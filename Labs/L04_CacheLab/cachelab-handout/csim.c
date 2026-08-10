#include "cachelab.h"
#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int SET_INDEX = 2;
int ENTRY_INDEX = 4;
int BLOCK_INDEX = 6;
int TRACE_FILE_INDEX = 8;

int ADDRESS_SIZE = 64;

int BUFF_SIZE = 256;

int HIT_CNT = 0;
int MISS_CNT = 0;
int EVIC_CNT = 0;

void count_cache_res(int cache_res)
{
    if (cache_res == CACHE_MISS) MISS_CNT++;
    else if (cache_res == CACHE_HIT) HIT_CNT++;
    else {EVIC_CNT++; MISS_CNT++;}
}

int main(int argc, char **argv)
{
    int tag_bit_num, set_bit_num, entry_num, block_bit_num;
    FILE *fp;

    set_bit_num = atoi(argv[SET_INDEX]);
    entry_num = atoi(argv[ENTRY_INDEX]);
    block_bit_num = atoi(argv[BLOCK_INDEX]);
    tag_bit_num = ADDRESS_SIZE - (set_bit_num + block_bit_num);
    fp = fopen(argv[TRACE_FILE_INDEX], "r");

    Cache *cache = malloc(sizeof(Cache));
    Cache_address *cache_address = malloc(sizeof(Cache_address));
    cache_address_init(cache_address, tag_bit_num, set_bit_num, block_bit_num);
    cache_init(cache, cache_address, entry_num);

    char mode, buffer[BUFF_SIZE];
    unsigned long start_address;
    int data_size, cache_res;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        mode = strtok(buffer, " ")[0];
        start_address = strtoul(strtok(NULL, ","), NULL, 16);
        data_size = atoi(strtok(NULL, "\n"));
        
        switch (mode) {
            case 'L':
            cache_res = cache_load(cache, start_address, data_size);
            count_cache_res(cache_res);
            break;

            case 'S':
            cache_res = cache_store(cache, start_address, data_size);
            count_cache_res(cache_res);              
            break;

            case 'M':
            cache_res = cache_load(cache, start_address, data_size);
            count_cache_res(cache_res);
            cache_res = cache_store(cache, start_address, data_size);
            count_cache_res(cache_res);
            break;
        }
    }


    fclose(fp);
    printSummary(HIT_CNT, MISS_CNT, EVIC_CNT);

    free_cache(cache);

    return 0;
}
