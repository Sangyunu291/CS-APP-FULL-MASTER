#include <stdio.h>

int main()
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    
    printf("%X\n", (0xFFFFFF00 & y) | (0x000000FF & x));
    
    return 0;


}