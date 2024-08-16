#include <stdio.h>

#define MAX 50
#define ERRO -1
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
}

void exibirLista(LISTA *l)
{
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++)
        printf("%i ", l->A[i].chave);
    printf("\"\n");
}

// Implementa ordenação utilizando insertionSort
void ordenar(LISTA *l)
{
    for (int i = 1; i < MAX; ++i)
    {
        int temp = l->A[i].chave;
        int j = i - 1;

        while (j >= 0 && l->A[j].chave > temp)
        {
            l->A[j + 1].chave = l->A[j].chave;
            j--;
        }
        l->A[j + 1].chave = temp;
    }
}

int main()
{

    return 0;
}