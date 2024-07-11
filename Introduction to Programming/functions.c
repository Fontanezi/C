#include <stdio.h>

int mult(int num)
{
    num = num * 2;
    return num;
}

int main()
{
    int value = 10;
    value = mult(value);
    printf("%d\n", value);
    return 0;
}