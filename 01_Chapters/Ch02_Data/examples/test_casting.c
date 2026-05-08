/*
* [비부호형과 2의보수 사이의 캐스팅을 확인하는 프로그램]
* T2U(-12345) = 53191 | U2T(4294967295) = -1
* U2T(53191) = -12345 | T2U(-1) = 4294967295
* show_bytes함수를 통해 확인할 수 있는 내용은 변수를 표현하는 비트는 모드 같지만
* 그 비트를 인코딩하는 방식이 다르다. 
*/

/* 실행결과 : 
v =  c7 cf
uv =  c7 cf
v = -12345, uv = 53191
u =  ff ff ff ff
tu =  ff ff ff ff
u = 4294967295, tu = -1
---------------------
t = 4294967295 = -1
u = 2147483648 = -2147483648
*/

#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void ex_1()
{
    short int v = -12345;
    unsigned short uv = (unsigned)v;

    printf("v = ");
    show_bytes((byte_pointer)&v, sizeof(short));
    printf("uv = ");
    show_bytes((byte_pointer)&uv, sizeof(unsigned short));
    printf("v = %d, uv = %u\n", v, uv);

    unsigned int u = 4294967295u;
    int tu = (int)u;

    printf("u = ");
    show_bytes((byte_pointer)&u, sizeof(int));
    printf("tu = ");
    show_bytes((byte_pointer)&tu, sizeof(unsigned int));
    printf("u = %u, tu = %d\n", u, tu);
}

void ex_2()
{
    int t = -1;
    unsigned int u = 2147483648;

    printf("t = %u = %d\n", t, t);
    printf("u = %u = %d\n", u, u);
}

int main()
{
    ex_1();
    printf("---------------------\n");
    ex_2();

    return 0;
}