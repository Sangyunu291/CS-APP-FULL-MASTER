#include <stdio.h>
#include <limits.h>
int temp(int x, int y) {
    int sub_value = x + (~y+1);
    int is_overflow = !!((x>>31)^(y>>31)) & !!((sub_value>>31)^(x>>31));
    int msb_of_sub_value = (sub_value>>31)&0X1;

    return is_overflow ^ (msb_of_sub_value ^ !sub_value);
}

int main()
{
    printf("%d\n", 0X10000000);
    printf("%d\n", temp(0X10000000,0));
    //printf("%d\n", temp(INT_MIN,INT_MAX));
    //printf("%d\n", temp(INT_MAX,INT_MIN));
    return 0;
}
