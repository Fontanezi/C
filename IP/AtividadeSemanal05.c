#include <stdio.h>
int identificador;

int main()
{
    printf("Insira o identificador: ");
    scanf("%i", &identificador);
    switch (identificador)
    {
    case 1:
        printf("Verde.\n");
        break;
    case 2:
        printf("Amarelo.\n");
        break;
    case 3:
        printf("Azul.\n");
        break;
    case 4:
        printf("Branco.\n");
        break;
    default:
        printf("Identificador inválido.\n");
        break;
    }

    return 0;
}