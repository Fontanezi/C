#include <stdio.h>
#include <stdbool.h>

// tamanho máximo do vetor estático
#define MAX 50

/* Uma lista linear é uma série de elementos ordenados na qual cada elemento exceto o primeiro possui um e
apenas um antecessor, e cada elemento exceto o último possui um e apenas um sucessor. */

typedef struct
{
    int chave;
    // outros campos... // O QUE VAI DENTRO DA LISTA (Dentro do vetor A[])
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX]; // ESTRUTURA DA LISTA (Contém o vetor de tamanho MAX e o número de elementos)
    int nroElem;
} LISTA;

void iniciaLista(LISTA *l) // CRIA LISTA
{
    l->nroElem = 0;
}

void exibeLista(LISTA *l) // EXIBE ELEMENTOS
{
    for (int i = 0; i < l->nroElem; i++)
    {
        printf("Elemento %i, chave %i.\n", i, l->A[i].chave);
    }
}

void tamanhoLista(LISTA *l) // EXIBE TAMANHO DA LISTA
{
    printf("Tamanho da lista: %i elementos.\n", l->nroElem);
}

void chavePrimeiro(LISTA *l) // EXIBE CHAVE DO PRIMEIRO ELEMENTO DA LISTA
{
    if (l->nroElem > 0)
        printf("Chave do primeiro elemento: %i.\n", l->A[0].chave);
    else
        return (-1); // Lista vazia
}

void chaveUltimo(LISTA *l) // EXIBE CHAVE DO ÚLTIMO ELEMENTO DA LISTA
{
    if (l->nroElem > 0)
        printf("Chave do último elemento: %i.\n", l->A[l->nroElem - 1].chave);
    else
        return (-1); // Lista vazia
}

void chaveN(LISTA *l, int n) // EXIBE CHAVE DO N-ÉSIMO ELEMENTO DA LISTA
{
    if (l->nroElem > 0)
        printf("Chave do elemento %i: %i.\n", n, l->A[n - 1].chave);
    else
        return (-1); // Lista vazia
}

void destroiLista(LISTA *l) // DESTRÓI A LISTA SEQUENCIAL
{
    l->nroElem = 0;
}

bool inserirElemListaSeq(int ch, int i, LISTA *l) // Inserção "direta" na posição i
{
    int j;
    if ((l->nroElem >= MAX) || (i < 0) || (i > (l->nroElem)))
        return (false); // lista cheia ou índice inválido
    if ((l->nroElem > 0) && (i < l->nroElem))
        for (j = l->nroElem; j >= (i + 1); j--)

            l->A[j] = l->A[j - 1];
    l->A[i].chave = ch;
    l->nroElem++;
    return (true);
}

int buscaSeq(int ch, LISTA l) // Busca sequencial em lista (ordenada por chave ou não)
{
    int i = 0;
    while (i < l.nroElem)
    {
        if (ch == l.A[i].chave)
            return (i); // achou
        else
            i++;
    }
    return (-1); // não achou
}

int buscaSent(int ch, LISTA l) // Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posições)
{
    int i = 0;
    l.A[l.nroElem].chave = ch; // sentinela
    while (l.A[i].chave < ch)
        i++;
    if ((i > (l.nroElem - 1)) || (l.A[i].chave != ch))
        return (-1); // não achou
    else
        return (i);
}

int buscaBin(int ch, LISTA l) // Busca binária em lista ordenada
{
    int inf, sup, meio;
    inf = 0;
    sup = l.nroElem - 1;
    while (inf <= sup)
    {

        meio = ((inf + sup) / 2);
        if (l.A[meio].chave == ch)
            return (meio); // achou
        else
        {
            if (l.A[meio].chave < ch)
                inf = meio + 1;

            else
                sup = meio - 1;
        }
    }
    return (-1);
}

bool inserirElemListaOrd(int ch, LISTA *l) // Inserção em lista ordenada COM SENTINELA sem duplicação
{
    int i = 0;
    if (l->nroElem >= MAX)
        return (false);          // lista cheia
    l->A[l->nroElem].chave = ch; // sentinela
    while (l->A[i].chave < ch)
        i++;
    if ((l->A[i].chave == ch) && (i < l->nroElem))
        return (false);
    else
        return (inserirElemListaSeq(ch, i, l));
}

bool excluirElemLista(int ch, LISTA *l) // Exclusão
{
    int pos, j;
    pos = buscaSeq(ch, *l);
    if (pos == -1)
        return (false); // não existe
    for (j = pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j + 1];
    l->nroElem--;
    return (true);
}

int main()
{
    LISTA l1;
    LISTA *l = &l1;
    iniciaLista(l);

    return 0;
}