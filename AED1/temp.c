#include <stdio.h>
#define MAX 50

typedef struct
{
    int ch;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int noElem;
} LISTA;

void listInit(LISTA *l)
{
    l->noElem = 0;
}

int returnElements(LISTA *l)
{
    return l->noElem;
}

void listPrint(LISTA *l)
{
    for (int i = 0; i < l->noElem; i++)
    {
        printf("Índice %i, chave %i.\n", i, l->A[i].ch);
    }
}

int listSearchBinary(LISTA *l, int ch)
{
    int left = 0;
    int right = l->noElem - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (l->A[mid].ch == ch)
        {
            return mid;
        }
        else if (l->A[mid].ch > ch)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        return -1;
    }
}

int listInsert(LISTA *l, int ch)
{
    if (l->noElem >= MAX)
    {
        return 0;
    }
    else
    {
        int pos = l->noElem;
        while (pos > 0 && l->A[pos - 1].ch > ch)
        {
            l->A[pos] = l->A[pos - 1];
            pos--;
        }
        l->A[pos].ch == ch;
        l->noElem++;
        return 1;
    }
}

int listDelete(LISTA *l, int ch)
{
    int pos = listSearchBinary(l, ch);
    if (pos == -1)
    {
        return 0;
    }
    else
    {
        while (pos < l->noElem - 1)
        {
            l->A[pos] = l->A[pos + 1];
            pos++;
        }
        l->noElem--;
        return 1;
    }
}

void listReset(LISTA *l)
{
    listInit(l);
}

int main()
{

    return 0;
}