#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int chave;
    // outros campos...
} REGISTRO;

typedef struct
{
    REGISTRO *A;
    int noElem;
    int maxElem;
} LISTA;

// Initializes the sequential list
// USE DYNAMIC IMPLEMENTATION. IF YOU USE THE STATIC IMPLEMENTATION, YOU'LL BE MODIFYING A COPY OF THE STRUCT
void listInit(LISTA *l, int tam)
{
    l->noElem = 0;
    l->maxElem = tam;
    l->A = (REGISTRO *)malloc(sizeof(REGISTRO) * tam);
}

// Returns number of elements in the list
int returnElements(LISTA *l)
{
    return l->noElem;
}

// Prints list elements
int listPrint(LISTA *l)
{
    for (int i = 0; i < l->noElem; i++)
    {
        printf("%i ", l->A[i].chave);
        printf("\"\n");
    }
}

// Searches for a key using binary search
int listSearchBinary(LISTA *l, int key)
{
    int esq, dir, meio;
    esq = 0;
    dir = l->noElem - 1;
    while (esq <= dir)
    {
        meio = ((esq + dir) / 2);
        if (l->A[meio].chave == key)
            return meio;
        else
        {
            if (l->A[meio].chave < key)
                esq = meio + 1;
            else
                dir = meio - 1;
        }
    }
    return -1;
}

// Inserts a key in the list based on an ordered position using INSERTION SORT
int listInsertSort(int key, LISTA *l)
{
    if (l->noElem >= l->maxElem)
    {
        return 0;
    }
    int pos = l->noElem;
    while (pos > 0 && l->A[pos - 1].chave > key)
    {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos].chave = key;
    l->noElem++;
    return 1;
}

// Removes a key from the list based on a specified position
int listDelete(int key, LISTA *l)
{
    int pos = listSearchBinary(key, l); // Could use either binary or sequential
    if (pos == -1)
    {
        return 0;
    }
    else
    {
        for (int i = pos; i < l->noElem - 1; i++)
        {
            l->A[i] = l->A[i + 1];
        }
        l->noElem--;
        return 1;
    }
}

// Resets the list
void listReset(LISTA *l)
{
    free(l->A);
    l->A = NULL;
    l->noElem = 0;
    l->maxElem = 0;
}

// A linear list is a structure where every element has an element before and after itself
// A sequential list is a structure where the order of the elements in the memory is the same as in the real world
int main()
{

    return 0;
}
