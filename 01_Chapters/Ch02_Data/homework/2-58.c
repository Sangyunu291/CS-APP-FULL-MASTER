#include <stdio.h>

typedef char *byte_pointer;


int is_little_endian()
{
    int v = 1; 
    byte_pointer p = (byte_pointer)&v;
    
    if (p[0] == 1) {
        return 1; 
    } else {
        return 0;
    }
}


int main()
{
    printf("%d\n", is_little_endian());
    return 0;
}
