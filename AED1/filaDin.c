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
    NO *fim;
} FILA;

// Inicializa a fila
void filaInit(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

// Retorna número de elementos da fila
int noElem(FILA *f)
{
    int tam = 0;
    NO *end = f->inicio;
    while (end->prox != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

// Exibe a fila
void filaPrint(FILA *f)
{
    NO *end = f->inicio;
    while (end->prox != NULL)
    {
        printf("%i\n", end->chave);
        end = end->prox;
    }
}

// Insere elemento na fila
bool filaInsert(FILA *f, int ch)
{
    NO *end = f->inicio;
    NO *new = (NO *)malloc(sizeof(NO));
    new->chave = ch;
    new->prox = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = new;
    }
    else
    {
        f->fim->prox = new;
        f->fim = new;
    }
    return true;
}

// Remove elemento da fila
bool filaRemove(FILA *f)
{
    if (f->inicio == NULL)
    {
        return false;
    }
    else
    {
        NO *remove = f->inicio;
        f->inicio = f->inicio->prox;
        free(remove);
        if (f->inicio == NULL)
        {
            f->fim = NULL;
        }
        return true;
    }
}

// Reinicializa a fila

bool filaDelete(FILA *f)
{
    NO *end = f->inicio;
    while (end != NULL)
    {
        NO *remove = end;
        end = end->prox;
        free(remove);
    }
    f->inicio = NULL;
    f->fim = NULL;
    return true;
}
int main()
{

    return 0;
}