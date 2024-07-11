#include <stdio.h>

int main()
{
    int option;
    printf("Digite um número, por favor.\n");
    scanf("%i", &option);
    switch (option)
    {
    case 1:
        printf("Opção 1\n");
        break;
    case 2:
        printf("Opção 2\n");
        break;
    case 3:
        printf("Opção 3\n");
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
}
