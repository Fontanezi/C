#include <stdio.h>

void conjecturaDeCollatz(int n)
{
    printf("Imprimindo sequencia iniciando em %i\n", n);
    while (n > 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        printf("%i\n", n);
    }
}

int main()
{
    conjecturaDeCollatz(92);
    // Serão impressos os valores 46, 23, 70, 35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1.

    return 0;
}