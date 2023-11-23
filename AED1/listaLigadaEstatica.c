#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct
{
    int chave;
    int prox;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int inicio;
    int dispo;
} LISTA;

// Inicializa lista
void listaInit(LISTA *l)
{
    l->inicio = -1;
    l->dispo = 0;
    for (int i = 0; i < MAX - 1; i++)
    {
        l->A[i].prox = i + 1;
    }
    l->A[MAX - 1].prox = -1;
}

// Obter nó disponível - a lista é alterada
int obterNo(LISTA *l)
{
    int result = l->dispo;
    if (l->dispo > -1)
    {
        l->dispo = l->A[l->dispo].prox;
    }
    return result;
}

// Devolver nó p/ dispo – a lista é alterada
int devolverNo(LISTA *l, int j)
{
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

// Busca sequencial, retornando a posição da chave e do anterior
int buscaSeq(int ch, LISTA l, int *ant)
{
    int i = l.inicio;
    *ant = -1;
    while (i != -1)
    {
        if (l.A[i].chave >= ch)
            break;
        *ant = i;
        i = l.A[i].prox;
    }
    if (i == -1)
        return -1;
    if (l.A[i].chave == ch)
        return (i);
    else
        return -1;
}

// inserção em lista ordenada sem duplicações
bool listaInsert(int ch, LISTA *l)
{
    int ant, i;
    i = buscaSeq(ch, *l, &ant);
    if ((l->dispo < 0) || (i != -1))
        return (false);
    i = obterNo(l);
    l->A[i].chave = ch;
    if (l->inicio < 0)
    {

        // inserção do primeiro elemento de lista vazia

        l->inicio = i;
        l->A[i].prox = -1;
    }
    else
    {
        if (ant < 0)
        {

            // inserção no início de lista já existente

            l->A[i].prox = l->inicio;

            l->inicio = i;
        }
        else
        {

            // inserção entre dois elementos
            l->A[i].prox = l->A[ant].prox;
            l->A[ant].prox = i;
        }
    }
    return (true);
}

// Exclusão do elemento de chave indicada
bool listaDelete(int ch, LISTA *l)
{
    int ant, i;
    i = buscaSeq(ch, *l, &ant);
    if (i < 0)
        return (false);
    if (ant == -1)
        l->inicio = l->A[i].prox;
    else
        l->A[ant].prox = l->A[i].prox;
    devolverNo(l, i);
    return (true);
}

// Exibe lista
void listaPrint(LISTA l)
{
    int i = l.inicio;
    while (i > -1)
    {
        printf("%i\n", l.A[i].chave);
        i = l.A[i].prox;
    }
}

int main()
{
    LISTA l;
    LISTA *p = &l;
    listaInit(p);
    for (int i = 0; i < MAX; i++)
    {
        listaInsert(i * 10, p);
    }
    listaPrint(l);
    for (int i = 0; i < MAX; i++)
    {
        listaDelete(i * 10, p);
    }
    return 0;
}