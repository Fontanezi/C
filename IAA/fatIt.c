#include <stdio.h>

int n;
int result;
int fatorial(int n);

int main()
{
    printf("Choose a number to calculate its factorial:");
    scanf("%d", &n);
    result = fatorial(n);
    printf("%d\n", result);
    return 0;
}

int fatorial(int n)
{
    int fat = 1;
    for (int i = 2; i <= n; i++)
    {
        fat = fat * i;
    }
    return fat;
}