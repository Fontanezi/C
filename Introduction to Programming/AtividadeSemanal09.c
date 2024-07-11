#include <stdio.h>

int calculaMDC(int x, int y)
{
    int resto;

    do
    {
        resto = x % y;

        x = y;
        y = resto;
    } while (resto != 0);

    return x;
}

int calculaMMC(int x, int y, int mdc)
{
    return (x * y) / mdc;
}

int main()
{
    int a, b, mdc, mmc;
    printf("Entre com dois valores separados por espaço, enter ou tab:\n");
    scanf("%d %d", &a, &b);

    mdc = calculaMDC(a, b);
    mmc = calculaMMC(a, b, mdc);
    printf("O MDC entre %d e %d é: %d\n", a, b, mdc);
    printf("O MMC entre %d e %d é: %d\n", a, b, mmc);

    return 0;
}

// MDC - Divida um valor pelo outro até o resto ser 0. O último divisor é o MDC.
// MMC - Multiplique os valores e divida pelo MDC.