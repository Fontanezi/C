#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// tamanho máximo do vetor estático
#define MAX 50

/* Uma lista linear ligada (ou simplesmente lista ligada) é uma lista linear na qual a ordem (lógica) dos
elementos da lista (chamados “nós”) não necessariamente coincide com sua posição física (em memória).
Pode ser implementada de forma estática (usando-se um vetor) ou, em linguagens de programação que
oferecem suporte à alocação dinâmica, com uso de ponteiros. */

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

void inicializarListaLigadaEstatica(LISTA *l) // Inicialização
{
    l->inicio = -1;
    l->dispo = 0;
    for (int i = 0; i < MAX - 1; i++)
        l->A[i].prox = i + 1;
    l->A[MAX - 1].prox = -1;
}

void exibirLista(LISTA l) // Exibição da lista completa
{
    int i = l.inicio;
    while (i > -1)
    {
        printf("%d ", l.A[i].chave);
        i = l.A[i].prox;
    }
}

int buscaSeqOrd(int ch, LISTA l, int *ant) // Busca sequencial, retornando a posição da chave e do anterior
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

int obterNó(LISTA *l)
{
    int result = l->dispo; // Obter nó disponível - a lista é alterada
    if (l->dispo > -1)
    {
        l->dispo = l->A[l->dispo].prox;
    }
    return (result);
}

// Devolver nó p/ dispo – a lista é alterada
void devolverNo(LISTA *l, int j)
{
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

// Exclusão do elemento de chave indicada
bool excluirElemListaEnc(int ch, LISTA *l)
{
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if (i < 0)
        return (false);
    if (ant == -1)
        l->inicio = l->A[i].prox;
    else
        l->A[ant].prox = l->A[i].prox;
    devolverNo(l, i);
    return (true);
}

// inserção em lista ordenada sem duplicações
bool inserirElemListaEncOrd(int ch, LISTA *l)
{
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if ((l->dispo < 0) || (i != -1))
        return (false);
    i = ObterNo(l);
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

int main()
{
    LISTA l1;
    LISTA *l = &l1;
    inicializarListaLigadaEstatica(l);
    return 0;
}