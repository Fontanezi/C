#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef struct
{
    int chave;
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
void listPrint(LISTA *l)
{
    for (int i = 0; i < l->noElem; i++)
    {
        printf("Índice %i, chave %i.\n", i, l->A[i].chave);
    }
}

// Searches for a key 
bool listSearch(int ch, LISTA *l)
{
    for (int i = 0; i < l->noElem; i++)
    {
        if (l->A[i].chave == ch)
        {
            return i;
        }
    }
    return false;
}

// Inserts a key in the list based on a position
bool listInsert(int ch, int pos, LISTA *l)
{
    if (l->noElem >= MAX || pos < 0 || pos > l->noElem)
    {
        return false;
    }
    else
    {
        for (int i = l->noElem; i > pos; i--)
        {
            l->A[i] = l->A[i - 1];
        }
        l->A[pos].chave = ch;
        l->noElem++;
    }
    return true;
}

// Removes a key from the list based on a specified position
bool listDelete(int ch, LISTA *l)
{
    int pos = listSearch(ch, l);
    if (pos == false)
    {
        return false;
    }
    else
    {
        for (int i = pos; i < l->noElem - 1; i++)
        {
            l->A[i] = l->A[i + 1];
        }
        l->noElem--;
        return true;
    }
}

void listReset(LISTA *l)
{
    l->noElem = 0;
}

int main()
{
    LISTA lista1;
    LISTA *lista = &lista1;
    listInit(lista);
    printf("Lista inicializada com %i elementos.\n", returnElements(lista));
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
    return 0;
}