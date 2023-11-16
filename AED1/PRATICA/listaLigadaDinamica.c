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
    NO *inicio;
} LISTA;

// Inicializa a lista
void listaInit(LISTA *l)
{
    l->inicio = NULL;
}

// Retorna número de elementos da lista
int noElem(LISTA *l)
{
    NO *end = l->inicio;
    int size = 0;
    while (end != NULL)
    {
        size++;
        end = end->prox;
    }
    return size;
}

// Exibe a lista
void listaPrint(LISTA *l)
{
    NO *current = l->inicio;
    while (current != NULL)
    {
        printf("%i", current->chave);
        current = current->prox;
    }
    printf("\n");
}

// Busca elemento em lista sortida
int buscaSequencial(LISTA *l, int ch)
{
    NO *pos = l->inicio;
    while (pos != NULL)
    {
        if (pos->chave == ch)
        {
            return ch;
        }
        else
        {
            pos = pos->prox;
        }
    }
    return NULL;
}

// Busca elemento em lista ordenada
int buscaSequencialOrd(LISTA *l, int ch)
{
    NO *pos = l->inicio;
    while (pos != NULL && pos->chave < ch)
    {
        pos = pos->prox;
        if (pos != NULL && pos->chave == ch)
        {
            return pos;
        }
    }
    return NULL;
}

// Busca auxiliar pra inserção
NO *buscaAux(LISTA *l, int ch, NO **ant)
{
    *ant = NULL;
    NO *atual = l->inicio;
    while ((atual != NULL) && (atual->chave < ch))
    {
        *ant = atual;
        atual = atual->prox;
    }
    if ((atual != NULL) && (atual->chave == ch))
    {
        return atual;
    }
    else
    {
        return NULL;
    }
}

// Insere elementos na lista
bool listaInsert(LISTA *l, int ch)
{
    NO *ant;
    NO *i = buscaAux(l, ch, &ant);
    if (i != NULL)
    {
        return false;
    }
    NO *new = (NO *)malloc(sizeof(NO));
    i->chave = ch;
    if (ant == NULL)
    {
        i->prox = l->inicio;
        l->inicio = i;
    }
    else
    {
        i->prox = ant->prox;
        ant->prox = i;
    }
    return true;
}

// Exclui elementos da lista
bool listaRemove(LISTA *l, int ch)
{
    NO *ant;
    NO *i = buscaAux(l, ch, &ant);
    if (i == NULL)
    {
        return false;
    }
    if (ant == NULL)
    {
        l->inicio = i->prox;
    }
    else
    {
        ant->prox = i->prox;
        free(i);
    }
    return true;
}

// Reinicia lista
void listaRestart(LISTA *l)
{
    NO *end = l->inicio;
    while (end != NULL)
    {
        NO *delete = end;
        end = end->prox;
        free(delete);
    }
    l->inicio = NULL;
}

int main()
{

    return 0;
}
