#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct
{
    int id;
    float media; // Elemento registro (o que queremos na lista)
} Registro;

Registro novo(int id, float media)
{
    Registro res;
    res.id = id;
    res.media = media; // Cria elemento registro
    return res;
}

typedef struct aux
{
    Registro reg;
    struct aux *prox; // Nó da lista, cada pedacinho que contém os elementos
} No;

typedef struct
{
    No *inicio;
    int elementos; // Lista em si
} Lista;

void inicializa(Lista *l)
{
    l->inicio = NULL;
    l->elementos = 0; // Define que o endereço inicial é NULL (lista vazia) e tem 0 elementos
}

void insere(Lista *l, Registro reg)
{
    No *novo = (No *)malloc(sizeof(No)); // Aloca memória para o novo nó
    novo->reg = reg;                     // Cria elemento registro no nó
    novo->prox = l->inicio;              // Cria a referência pro próximo nó (no início é ele mesmo)
    l->inicio = novo;                    // O início da lista passa a ser o novo nó (ele mesmo)
    l->elementos++;                      // Agora temos mais um elemento (nó)
}

int main()
{
    Lista l1;        // Cria a lista
    inicializa(&l1); // Inicializa a lista
    insere(&l1, novo(4, 8.5));
    insere(&l1, novo(7, 6.5));
    insere(&l1, novo(9, 7.5));
    No *n = l1.inicio;
    while (n != NULL)
    {
        printf("%i\n", n->reg.id);
        n = n->prox;
    }
    return 0;
}