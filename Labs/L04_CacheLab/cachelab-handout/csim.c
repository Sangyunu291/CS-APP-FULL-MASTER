#include "cachelab.h"
#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SET_INDEX = 2;
int ENTRY_INDEX = 4;
int BLOCK_INDEX = 6;
int TRACE_FILE_INDEX = 8;

int ADDRESS_SIZE = 64;

int BUFF_SIZE = 256;

int main(int argc, char **argv)
{
    int tag_bit_num, set_bit_num, entry_num, block_bit_num;
    FILE *fp;

    set_bit_num = atoi(argv[SET_INDEX]);
    entry_num = atoi(argv[ENTRY_INDEX]);
    block_bit_num = atoi(argv[BLOCK_INDEX]);
    tag_bit_num = ADDRESS_SIZE - (set_bit_num + block_bit_num);
    fp = fopen(argv[TRACE_FILE_INDEX], "r");

    printf("%d %d %d %d %d\n", set_bit_num, entry_num, block_bit_num, tag_bit_num, set_bit_num+tag_bit_num+block_bit_num);

    char buffer[BUFF_SIZE];

    char *mode;
    unsigned long start_address;
    int data_size;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        mode = strtok(buffer, " ");
        start_address = strtoul(strtok(NULL, ","), NULL, 16);
        data_size = atoi(strtok(NULL, "\n"));
        
        printf("%s %lx %d\n", mode, start_address, data_size);
    }


    fclose(fp);
    printSummary(0, 0, 0);
    return 0;
}
