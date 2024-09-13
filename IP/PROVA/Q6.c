#include <stdio.h>
int num;

int digitSum(int num)
{
    int sum = 0;
    while (num % 10 != 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int main()
{
    printf("Por favor digite um número natural:\n");
    scanf("%d", &num);
    printf("A soma dos dígitos do número %d é %d\n", num, digitSum(num));
    return 0;
}