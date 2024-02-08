#include <stdio.h>

int main()
{
    int num, cont = 0;
    printf("Digite um número inteiro positivo:\n");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cont++;
        }
    }
    if (cont == 2)
    {
        printf("O número %d é primo.\n", num);
    }
    else
    {
        printf("O número %d não é primo.\n", num);
    }
    return 0;
}