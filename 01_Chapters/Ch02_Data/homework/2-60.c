#include <stdio.h>

unsigned byte(unsigned x, int i, unsigned char b)
{  
    int w = sizeof(unsigned);
    return (~(0xFF << (i*8)) & x) | (b << (i*8));
}

int main()
{
    printf("%8.X\n", byte(0x12345678,3,0xAB));
    printf("%8.X\n", byte(0x12345678,2,0xAB));
    printf("%8.X\n", byte(0x12345678,0,0xAB));
}