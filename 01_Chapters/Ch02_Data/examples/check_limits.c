#include <stdio.h>
#include <limits.h>

int main() 
{  
    printf(" %-15s | %-5d | %-20d | %-20d\n", "int", (int)sizeof(int), INT_MIN, INT_MAX);
    printf(" %-15s | %-5d | %-20d | %-20u\n", "unsigned int", (int)sizeof(unsigned int), 0, UINT_MAX);
    return 0;
}