#include <stdio.h>

int int_shifts_are_arithmetic()
{
    int v = -1;
    int shifted = v >> 1;

    return v == shifted;
}


int main()
{
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}