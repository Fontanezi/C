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

// Searches for a key in the list
int listSearch(int key, LISTA *l)
{
    for (int i = 0; i < l->noElem; i++)
    {
        if (l->A[i].chave == key)
        {
            return i;
        }
    }
    return 0;
}

// Inserts a key in the list based on a specified position
int listInsert(int key, int pos, LISTA *l)
{
    if (l->noElem >= MAX || pos < 0 || pos > l->noElem)
    {
        return 0;
    }
    else
    {
        for (int i = l->noElem; i > pos; i--)
        {
            l->A[i] = l->A[i - 1];
        }
        l->A[pos].chave = key;
        l->noElem++;
        return 1;
    }
}

// Removes a key from the list based on a specified position
int listDelete(int key, LISTA *l)
{
    int pos = listSearch(key, l);
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
    LISTA lista1;
    LISTA *lista = &lista1;
    listInit(lista);
    printf("Lista inicializada com %i elementos.\n", listPrint(lista));
    listInsert(1, 0, lista);
    listInsert(2, 1, lista);
    listInsert(3, 2, lista);
    listInsert(4, 3, lista);
    listPrint(lista);
    printf("%i\n", returnElements(lista));
    printf("%i\n", listSearch(2, lista));
    listInsert(5, 1, lista);
    listPrint(lista);
    printf("%i\n", returnElements(lista));
    printf("%i\n", listSearch(2, lista));
    listDelete(5, lista);
    listPrint(lista);
    printf("%i\n", returnElements(lista));
    printf("%i\n", listSearch(2, lista));
    listReset(lista);
    printf("%i\n", returnElements(lista));
    return 0;
}