#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct estrutura
{
    int chave;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO *cabeca;
} LISTA;

// Inicializa a lista
void listaInit(LISTA *l)
{
    l->cabeca = (NO *)malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
}

// Retorna número de elementos da lista
int noElem(LISTA *l)
{
    int tam = 0;
    NO *end = l->cabeca->prox;
    while (end != l->cabeca)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

// Exibe a lista
void listaPrint(LISTA *l)
{
    NO *end = l->cabeca->prox;
    printf("Lista: \n");
    while (end != l->cabeca)
    {
        printf("%i", end->chave);
        end = end->prox;
    }
    printf("/n");
}

// Busca elemento na lista
int buscaSequencial(LISTA *l, int ch)
{
    NO *end = l->cabeca->prox;
    l->cabeca->chave = ch;
    while (end->chave != ch)
    {
        end = end->prox;
    }
    if (end != l->cabeca)
    {
        return end;
    }
    return NULL;
}

// Busca elemento na lista ordenada
int buscaSequencialOrd(LISTA *l, int ch)
{
    NO *end = l->cabeca->prox;
    l->cabeca->chave = ch;
    while (end->chave < ch)
    {
        end = end->prox;
    }
    if (end != l->cabeca && end->chave == ch)
    {
        return end;
    }
    return NULL;
}

// Busca auxiliar pra inserção
int buscaSequencialAux(LISTA *l, int ch, NO **ant)
{
    *ant = l->cabeca;
    NO *atual = l->cabeca->prox;
    l->cabeca->chave = ch;
    while (atual->chave < ch)
    {
        *ant = atual;
        atual = atual->prox;
    }
    if (atual != l->cabeca && atual->chave == ch)
    {
        return atual;
    }
    return NULL;
}

// Insere elemento na lista sem duplicação
bool listaInsert(LISTA *l, int ch)
{
    NO *ant, *i;
    i = buscaSequencialAux(l, ch, &ant);
    if (i != NULL)
    {
        return false;
    }
    else
    {
        i = (NO *)malloc(sizeof(NO));
        i->chave = ch;
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

// Remove elemento da lista
bool listaRemove(LISTA *l, int ch)
{
    NO *ant, *i;
    i = buscaSequencialAux(l, ch, &ant);
    if (i == NULL)
    {
        return false;
    }
    else
    {
        ant->prox = i->prox;
        free(i);
    }
}

// Reinicia lista
void listaRestart(LISTA *l)
{
    NO *ant;
    NO *end = l->cabeca->prox;
    while (end != l->cabeca)
    {
        ant = end;
        end = ant->prox;
        free(ant);
    }
    l->cabeca->prox = l->cabeca;
}

int main()
{

    return 0;
}
