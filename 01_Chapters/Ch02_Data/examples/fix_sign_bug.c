#include <stddef.h>
float sum_elements(float a[], unsigned length)
{
    float result = 0;
    for (int i = 0; i < length /*i<=length-1*/; i++)
        result += a[i];
    return result;
}

int strlonger(char *s, char *t)
{
    return strlen(s) > strlen(t); // return strlen(s) - strlen(t) > 0;
}