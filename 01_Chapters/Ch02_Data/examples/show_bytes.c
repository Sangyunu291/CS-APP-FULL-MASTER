/*
 * [바이트 순서를 확인하는 프로그램]
 * show_bytes()를 통해 x86_64환경에서 바이트 출력 순서는 리틀 엔디안이라는걸 확인할 수 있었다.
 * 또한 부동소수점과 정수 데이터 모두 같은 수를 인코딩할지는 몰라도 인코딩 방식이 다르므로 다른 바이트 페턴을 갖는다.
*/

#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main()
{ 
    test_show_bytes(12345);

    //const char *m = "mnopqr";
    //show_bytes("12345\0", 6);
    //show_bytes((byte_pointer)m, strlen(m));

    return 0;
}