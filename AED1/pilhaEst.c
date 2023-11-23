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
    int topo;
} PILHA;

// Inicializa a pilha
void pilhaInit(PILHA *p)
{
    p->topo = -1;
}

// Retorna número de elementos da pilha
void noElem(PILHA *p)
{
    return p->topo + 1;
}

// Exibe a pilha
void pilhaPrint(PILHA *p)
{
    for (int i = p->topo; i >= 0; i--)
    {
        printf("%i", p->A[i].chave);
    }
}

// Insere elemento na pilha (se tive espaço)
bool pilhaInsert(PILHA *p, int ch)
{
    if (p->topo = MAX - 1)
    {
        return false;
    }
    else
    {
        p->topo = p->topo + 1;
        p->A[p->topo].chave = ch;
        return true;
    }
}

// Remove elemento da pilha
bool pilhaRemote(PILHA *p, int ch)
{
    if (p->topo == -1)
    {
        return false;
    }
    else
    {
        p->A[p->topo].chave = ch;
        p->topo = p->topo - 1;
        return true;
    }
}

// Reinicializa a pilha
void pilhaDelete(PILHA *p)
{
    p->topo = -1;
}

int main()
{

    return 0;
}