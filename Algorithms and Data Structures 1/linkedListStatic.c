#include <stdio.h>
#include <stdbool.h>
#define MAX 50
#define NULL -1

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

bool listSearch(LIST *l, int key){

}

bool listInsert(LIST *l, int key){

}

bool listDelete(LIST *l, int key){
    
}

void listReset(LIST *l){

}

int main()
{

    return 0;
}