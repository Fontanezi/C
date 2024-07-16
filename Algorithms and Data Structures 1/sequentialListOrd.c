#include <stdio.h>
#define MAX 50

typedef struct
{
    int chave;
    // outros campos...
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX];
    int noElem;
} LISTA;

// Initializes the sequential list
// USE DYNAMIC IMPLEMENTATION. IF YOU USE THE STATIC IMPLEMENTATION, YOU'LL BE MODIFYING A COPY OF THE STRUCT
void listInit(LISTA *l)
{
    l->noElem = 0;
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

// Inserts a key in the list based on a specified position using INSERTION SORT
int listInsertSort(REGISTRO reg, LISTA *l)
{
    if (l->noElem >= MAX)
    {
        return 0;
    }
    int pos = l->noElem;
    while (pos > 0 && l->A[pos - 1].chave > reg.chave)
    {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
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
    l->noElem = 0;
}

// A linear list is a structure where every element has an element before and after itself
// A sequential list is a structure where the order of the elements in the memory is the same as in the real world
int main()
{

    return 0;
}
