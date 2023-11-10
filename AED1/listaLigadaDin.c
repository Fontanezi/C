#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    LISTA l1;
    LISTA *l = &l1;
    inicializarListaLigadaEstatica(l);
    return 0;
}