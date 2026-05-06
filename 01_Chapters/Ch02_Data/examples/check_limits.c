/* [컴퓨터, 컴파일러에 따른 자료형의 최소, 최대치를 확인하는 프로그램] */

#include <stdio.h>
#include <limits.h>

int main() 
{  
    printf(" %-15s | %-5d | %-20d | %-20d\n", "int", (int)sizeof(int), INT_MIN, INT_MAX);
    printf(" %-15s | %-5d | %-20d | %-20u\n", "unsigned int", (int)sizeof(unsigned int), 0, UINT_MAX);
    return 0;
}