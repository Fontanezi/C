#include <stdio.h>

int main()
{
    int identificador;
    printf("Digite um identificador.\n");
    scanf("%i", &identificador);
    switch (identificador)
    {
    case 1:
        printf("Verde\n");
        break;
    case 2:
        printf("Amarelo\n");
        break;
    case 3:
        printf("Azul\n");
        break;
    case 4:
        printf("Branco\n");
        break;
    default:
        printf("Identificador Inválido\n");
        break;
    }
}
