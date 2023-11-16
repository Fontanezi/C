#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura
{
    int chave;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO *cabeca;
} LISTA;

void listaInit(LISTA *l)
{
    l->cabeca = (NO *)malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
}

int main()
{

    return 0;
}