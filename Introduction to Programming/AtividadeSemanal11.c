#include <stdio.h>

int somaImpares(int x)
{
    int result = x * x;
    return result;
}
int main()
{
    int n;
    printf("Digite quantos ímpares deseja somar:\n");
    scanf("%d", &n);
    printf("A soma dos %d primeiros números ímpares é: %d.\n", n, somaImpares(n));
    return 0;
}