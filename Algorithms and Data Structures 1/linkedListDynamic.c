#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int key;
} REGISTER;

typedef struct aux
{
    REGISTER reg;
    struct aux *next;
} ELEMENT;

typedef struct
{
    ELEMENT *start;
} LIST;

void listInit(LIST *l)
{
    l->start = NULL;
}

int returnElements(LIST *l)
{
    int i = 0;
    ELEMENT *addr = l->start;
    while (addr != NULL)
    {
        i++;
        addr = addr->next;
    }
    return i;
}

void listPrint(LIST *l)
{
    int i = 1;
    ELEMENT *addr = l->start;
    while (addr != NULL)
    {
        printf("Element %i: Key %i\n", i, addr->reg.key);
        addr = addr->next;
    }
}

ELEMENT *listSearch(LIST *l, int key)
{
    ELEMENT *addr = l->start;
    while (addr != NULL && addr->reg.key < key)
    {
        addr = addr->next;
    }
    if (addr != NULL && addr->reg.key == key)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}

ELEMENT *insertionSearch(LIST *l, int key, ELEMENT *previous)
{
    previous = NULL;
    ELEMENT *current = l->start;
    while ((current != NULL) && (current->reg.key < key))
    {
        previous = current;
        current = current->next;
    }
    if ((current != NULL) && (current->reg.key == key))
    {
        return current;
    }
    else
    {
        return NULL;
    }
}

// Find position -> Insert (if previous or not previous).
bool listInsert(LIST *l, REGISTER reg)
{
    int key = reg.key;
    ELEMENT *previous, *current;
    current = insertionSearch(l, reg.key, &previous);
    if (current != NULL)
    {
        return false;
    }
    else
    {
        ELEMENT *new = (ELEMENT *)malloc(sizeof(ELEMENT));
        new->reg = reg;
        if (previous == NULL)
        {
            current->next = l->start;
            l->start = current;
        }
        else
        {
            current->next = previous->next;
            previous->next = current;
        }
        return true;
    }
}

bool listDelete(LIST *l, int key)
{
    ELEMENT *previous, *current;
    current = insertionSearch(l, key, &previous);
    if (current == NULL)
    {
        return false;
    }
    if (previous == NULL)
    {
        l->start = current->next;
    }
    else
    {
        previous->next = current->next;
    }
    free(current);
    return true;
}

void listReset(LIST *l)
{
    ELEMENT *temp;
    ELEMENT *addr = l->start;
    while (addr != NULL)
    {
        temp = addr;
        addr = addr->next;
        free(temp);
    }
    l->start = NULL;
}

int main()
{

    return 0;
}