#include <stdio.h>

int main()
{
    int option;
    printf("Digite 0 ou 1, por favor.\n");
    scanf("%i", &option);
    if (option == 0)
    {
        printf("Falso\n");
        return 0;
    }
    else
    {
        printf("Verdadeiro\n");
        return 1;
    }
}

// OPERADORES CONDICIONAIS: >, <, >=, <=, ==, !=
// OPERADORES LÓGICOS: &&, ||, !