/* 
* [2.11 솔루션 프로그램]
* 두 개의 포인터가 같은 메모리를 가리키지 못하게 for문을 수정하는
* 방법도 있지만 if (x == y) return;을 추가하여 같은 메모리를 가리킬시 
* 반환하게만 해도 될거같다. 
*/

#include <stdio.h>

void inplace_swap(int* x, int* y)
{
    
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void reverse_array(int a[], int cnt) 
{
    int first, last;
    for (first = 0, last = cnt-1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    reverse_array(a, 5);

    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}