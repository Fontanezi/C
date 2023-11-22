#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura
{
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct
{
    NO *cabeca;
} DEQUE;

// Inicializa o deque
void dequeInit(DEQUE *d)
{
    d->cabeca = (NO *)malloc(sizeof(NO));
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
}

// Retorna o número de elementos do deque
int noElem(DEQUE *d)
{
    int tam = 0;
    NO *end = d->cabeca->prox;
    if (end == d->cabeca)
    {
        return 0;
    }
    else
    {
        while (end != d->cabeca)
        {
            tam++;
            end = end->prox;
        }
        return tam;
    }
}

// Exibe o deque
void noElem(DEQUE *d)
{
    NO *end = d->cabeca->prox;
    if (end == d->cabeca)
    {
        return 0;
    }
    else
    {
        while (end != d->cabeca)
        {
            printf("%i\n", end->chave);
            end = end->prox;
        }
    }
}

// Insere elemento no fim do deque
bool dequeInsertFim(DEQUE *d, int ch)
{
    NO *new = (NO *)malloc(sizeof(NO));
    new->chave = ch;
    new->prox = d->cabeca;
    new->ant = d->cabeca->ant;
    d->cabeca->ant = new;
    new->ant->prox = new;
}

// Remove elemento do início do deque
bool dequeRemoveInicio(DEQUE *d, int ch)
{
    if (d->cabeca->prox == d->cabeca)
    {
        return false;
    }
    else
    {
        NO *delete = d->cabeca->prox;
        d->cabeca->prox = delete->prox;
        delete->prox->ant = d->cabeca;
        free(delete);
        return true;
    }
}

// Reincializa o deque
bool dequeDelete(DEQUE *d)
{
    NO *ant;
    NO *end = d->cabeca->prox;
    while (end != d->cabeca)
    {
        ant = end;
        end = end->prox;
        free(ant);
    }
    d->cabeca->prox = d->cabeca;
    d->cabeca->ant = d->cabeca;
    return true;
}

int main()
{

    return 0;
}