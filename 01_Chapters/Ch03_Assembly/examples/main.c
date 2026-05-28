#include <stdio.h>

void multstore(long, long, long *);

int main() {
    long d;
    multstore(2, 3, &d);
    printf("result : %ld\n", d);
    return 0;
}

long mult2(long x, long y) {
    long s = x * y;
    return s;
}