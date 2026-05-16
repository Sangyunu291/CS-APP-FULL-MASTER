#include <stddef.h>
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}


void show_short(short sv)
{
    show_bytes((byte_pointer)&sv, sizeof(short));   
}

void show_long(long lv)
{
    show_bytes((byte_pointer)&lv, sizeof(long));   
}

void show_double(double dv)
{  
    show_bytes((byte_pointer)&dv, sizeof(double));   
}

int main()
{
    short sv = 12345;
    long lv = sv;
    double dv = (double)sv;
    
    show_short(sv);
    show_long(lv);
    show_double(dv);
    
    return 0;
}