#include <stdio.h>
#include <stdbool.h>
#define MAX 50
#define NULL -1

// USED IN STORAGE DISK MANAGEMENT

typedef struct
{
    int key;
} REGISTER;

typedef struct
{
    REGISTER reg;
    int next;
} ELEMENT;

typedef struct
{
    ELEMENT A[MAX];
    int start;
    int available;
} LIST;

void listInit(LIST *l)
{
    for (int i = 0; i < MAX - 1; i++)
    {
        l->A[i].next = i + 1;
    }
    l->A[MAX - 1].next = NULL;
    l->start = NULL;
    l->available = 0;
}

int returnElements(LIST *l)
{
    int elements;
    int i = l->start;
    while (i != NULL)
    {
        elements++;
        i = l->A[i].next;
    }
    return elements;
}

void listPrint(LIST *l)
{
    int i = l->start;
    while (i != NULL)
    {
        printf("Register %i.\n", l->A[i].reg.key);
        i = l->A[i].next;
    }
}

int listSearch(LIST *l, int key)
{
    int i = l->start;
    while (i != NULL && l->A[i].reg.key < key) // E se for o primeiro elemento? (No caso de A[0] ter key = 0). Seria interessante usar <= ?
    {
        i = l->A[i].next;
        if (i != NULL && l->A[i].reg.key == key)
        {
            return i;
        }
        else
        {
            return NULL;
        }
    }
}

// Will find the available node, and set the correct "next" value to the list.
bool getNode(LIST *l)
{
    int node = l->available;
    if (l->available != NULL)
    {
        l->available = l->A[l->available].next;
    }
    return node;
}

// Check is list is full -> Find position -> Check for duplicate -> Insert (if previous or not previous).
bool listInsert(LIST *l, REGISTER reg)
{
    // Checks if list is full
    if (l->available == NULL)
    {
        return NULL;
    }

    // Finds position to insert element
    int previous;
    int i = l->start;
    int key = reg.key;
    while ((i != NULL) && (l->A[i].reg.key < key))
    {
        previous = i;
        i = l->A[i].next;
    }

    // Checks if element is a duplicate
    if (i != NULL && l->A[i].reg.key == key)
    {
        return false;
    }

    // Inserts element
    else
    {
        i = getNode(l);
        l->A[i].reg = reg;
        // If element doesn't have a previous
        if (previous == NULL)
        {
            l->A[i].next = l->start;
            l->start = i;
        }
        // If it does
        else
        {
            l->A[i].next = l->A[previous].next;
            l->A[previous].next = i;
        }
        return true;
    }
}

// Makes deleted node available again
void makeNodeAvailable(LIST *l, int i)
{
    l->A[i].next = l->available;
    l->available = i;
}

bool listDelete(LIST *l, int key)
{
    // Finds position of element
    int previous = NULL;
    int i = l->start;
    while ((i != NULL) && (l->A[i].reg.key < key))
    {
        previous = i;
        i = l->A[i].next;
    }

    // Checks if position is null or key is different (element doesn't exist)
    if (i == NULL || l->A[i].reg.key != key)
    {
        return false;
    }

    // Deletes element
    else
    {
        // If element doesn't have a previous
        if (previous == NULL)
        {
            l->start = l->A[i].next;
        }
        // If it does
        else
        {
            l->A[previous].next = l->A[i].next;
        }
        makeNodeAvailable(l, i);
        return true;
    }
}

void listReset(LIST *l)
{
    listInit(l);
}

int main()
{

    return 0;
}