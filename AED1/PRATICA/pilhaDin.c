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
    NO *topo;
} PILHA;

// Inicializa a pilha
void pilhaInit(PILHA *p)
{
    p->topo = NULL;
}

// Retorna número de elementos da pilha
int noElem(PILHA *p)
{
    int tam = 0;
    NO *end = p->topo;
    while (end != NULL)
    {
        tam++;
        end = end->prox;
    }
    return tam;
}

// Verifica se a pilha está vazia
bool pilhaVazia(PILHA *p)
{
    if (p->topo == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Exibe a pilha
void pilhaPrint(PILHA *p)
{
    NO *end = p->topo;
    while (end != NULL)
    {
        printf("%i\n", end->chave);
        end = end->prox;
    }
}

// Insere elemento na pilha
bool pilhaInsert(PILHA *p, int ch)
{
    NO *new = (NO *)malloc(sizeof(NO));
    new->chave = ch;
    new->prox = p->topo;
    p->topo = new;
    return true;
}

// Remove elemento da pilha
bool pilhaRemove(PILHA *p)
{
    if (p->topo == NULL)
    {
        return false;
    }
    NO *remove = p->topo;
    p->topo = remove->prox;
    free(remove);
    return true;
}

// Reinicializa a pilha
void pilhaDelete(PILHA *p)
{
    NO *ant;
    NO *end = p->topo;
    while (end != NULL)
    {
        ant = end;
        end = end->prox;
        free(ant);
    }
    p->topo = NULL;
}

int main()
{

    return 0;
}