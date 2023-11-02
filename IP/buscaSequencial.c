#include <stdio.h>

int lista[] = {2, 12, 20, 15, 23, 8, 30};
int buscaSequencial(int *lista, int n, int x);

int main()
{
    buscaSequencial(lista, 7, 15);
}

int buscaSequencial(int *lista, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (lista[i] == x)
        {
            printf("Encontrado na posição %i.\n", i);
            return 1;
        }
    }
    printf("Nao encontrado.\n");
    return 0;
}