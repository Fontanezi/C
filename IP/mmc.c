#include <stdio.h>
int opt;
int n1, n2;

void mmc(n1, n2)
{
    int resto, a, b;

    a = n1;
    b = n2;

    do
    {
        resto = a % b;

        a = b;
        b = resto;

    } while (resto != 0);

    printf("%i\n", (n1 * n2) / a);
}

void mdc(n1, n2)
{
    int resto;

    do
    {
        resto = n1 % n2;

        n1 = n2;
        n2 = resto;

    } while (resto != 0);

    printf("%i\n", n1);
}

int main()
{
    printf("Escolha seu cálculo:\n 1 - MMC\t 2 - MDC\n");
    scanf("%i", &opt);

    switch (opt)
    {
    case 1:
        printf("Insira os números: ");
        scanf("%i %i", &n1, &n2);
        mmc(n1, n2);
        break;
    case 2:
        printf("Insira os números: ");
        scanf("%i %i", &n1, &n2);
        mdc(n1, n2);
        break;

    default:
        printf("Escolha uma opção válida.");
        break;
    }
}