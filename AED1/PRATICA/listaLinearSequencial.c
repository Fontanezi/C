#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// PRÁTICA DE LISTA LINEAR SEQUENCIAL

typedef struct
{
    int chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int noElem;
} LISTA;

// Inicializa
void listaInit(LISTA *l)
{
    l->noElem = 0;
    printf("Lista iniciada.\n");
}

// Insere na posição i
bool listaInsert(LISTA *l, int i, int ch)
{
    if (i > MAX || i < 0)
    {
        // printf("Índice inválido!\n");
        return false;
    }
    else if (l->noElem == MAX)
    {
        // printf("Lista cheia!\n");
        return false;
    }
    else
    {
        for (int j = l->noElem; j >= (i + 1); i--)
        {
            l->A[j] = l->A[j - 1];
        }
        l->A[i].chave = ch;
        l->noElem++;
        // printf("Chave %i adicionada na posição %i!\n", ch, i);
        return true;
    }
}

// Retorna chave do primeiro elemento
int chavePrimeiro(LISTA l)
{
    int ch = l.A[0].chave;
    // printf("Chave do primeiro elemento: %i.\n", ch);
    return ch;
}

// Retorna chave do último elemento
int chaveUltimo(LISTA l)
{
    int ch = l.A[l.noElem - 1].chave;
    // printf("Chave do último elemento: %i.\n", ch);
    return ch;
}

// Retorna chave do n elemento
void chaveN(LISTA l, int n)
{
    if (n <= l.noElem)
    {
        printf("Chave do elemento na posição %i: %i.\n", n, l.A[n - 1].chave);
    }
    else
    {
        printf("O elemento não possui chave, ou a posição está inválida.\n");
    }
}

// Tamanho da lista
void listaSize(LISTA l)
{
    printf("A lista possui %i elementos.\n", l.noElem);
}

// Exibe
void listaPrint(LISTA l)
{
    if (l.noElem == 0)
    {
        printf("Lista vazia!\n");
    }
    for (int i = 0; i < l.noElem; i++)
    {
        printf("Elemento %i: Chave %i.\n", i, l.A[i].chave);
    }
}

// Busca sequencial em ordenada ou não
int listaBuscaSeq(LISTA l, int ch)
{
    for (int i = 0; i < l.noElem; i++)
    {
        if (l.A[i].chave == ch)
        {
            // printf("Chave %i encontrada na posição %i.\n", ch, i);
            return i;
        }
    }
    // printf("Chave %i não está na lista.\n", ch);
    return -1;
}

// Busca binária em ordenada
int listaBuscaBin(LISTA l, int ch)
{
    int start = 0;
    int end = MAX - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (l.A[mid].chave == ch)
        {
            // printf("Chave %i encontrada na posição %i.\n", ch, mid);
            return mid;
        }
        else
        {
            if (l.A[mid].chave < ch)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    // printf("Chave %i não está na lista.\n", ch);
    return -1;
}

// Busca com sentinela sem duplicação
int listaBuscaSeqSent(LISTA l, int ch)
{
    int temp = l.A[l.noElem - 1].chave;
    l.A[l.noElem - 1].chave = ch;
    int index = 0;

    while (l.A[index].chave != ch)
    {
        index++;
    }
    l.A[l.noElem - 1].chave = temp;

    if (index == l.noElem - 1)
    {
        // printf("Chave %i não está na lista.\n", ch);
        return -1;
    }

    // printf("Chave %i encontrada na posição %i.\n", ch, index);
    return index;
}

// Exclusão
bool listaRemove(LISTA *l, int ch)
{
    int pos, j;
    pos = listaBuscaSeq(*l, ch);

    if (pos == -1)
    {
        // printf("A chave %i não está na lista.\n", ch);
        return false;
    }

    for (j = pos; j < l->noElem; j++)
    {
        l->A[j] = l->A[j + 1];
    }
    l->noElem--;
    // printf("Chave %i removida da lista.\n", ch);
    return true;
}

// Destrói
void listaEnd(LISTA *l)
{
    l->noElem = 0;
    printf("Lista destruída!\n");
}

int main()
{
    LISTA l;
    LISTA *p = &l;
    listaInit(p);
    listaInsert(p, -1, 0);
    for (int i = 0; i < MAX; i++)
    {
        listaInsert(p, i, (i * 10));
    }
    listaInsert(p, 0, 100);
    chavePrimeiro(l);
    chaveUltimo(l);
    chaveN(l, 3);
    chaveN(l, 22);
    listaSize(l);
    listaPrint(l);
    listaBuscaSeq(l, 50);
    listaBuscaSeq(l, 200);
    listaBuscaBin(l, 50);
    listaBuscaBin(l, 200);
    listaBuscaSeqSent(l, 50);
    listaBuscaSeqSent(l, 200);
    listaRemove(p, 200);
    listaRemove(p, 50);
    listaEnd(p);

    return 0;
}