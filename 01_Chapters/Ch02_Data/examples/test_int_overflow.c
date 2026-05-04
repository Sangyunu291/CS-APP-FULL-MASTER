/*[단순히 int(4byte) overflow를 확인하는 프로그램]*/
#include <stdio.h>

int main()
{
    int overflowed_value = 200 * 300 * 400 * 500;
    printf("%d\n", overflowed_value);
    return 0;
}