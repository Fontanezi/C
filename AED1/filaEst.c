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
    int inicio;
    int noElem;
} FILA;

// Inicializa a fila
void filaInit(FILA *f)
{
    f->inicio = 0;
    f->noElem = 0;
}

// Retorna elementos da fila
int noElem(FILA *f)
{
    return f->noElem;
}

// Exibe a fila
void filaPrint(FILA *f)
{
    int i = f->inicio;
    int temp;
    for (temp = 0; temp < f->noElem; temp++)
    {
        printf("%i\n", f->A[i].chave);
        i = (i + 1) % MAX;
    }
}

// Insere elemento na fila
bool filaInsert(FILA *f, int ch)
{
    if (f->noElem >= MAX)
    {
        return false;
    }
    else
    {
        int posicao = (f->inicio + f->noElem) % MAX;
        f->A[posicao].chave = ch;
        f->noElem++;
        return true;
    }
}

// Remove elemento da fila
bool filaRemove(FILA *f, int ch)
{
    if (f->noElem == 0)
    {
        return false;
    }
    else
    {
        f->inicio = (f->inicio + 1) % MAX;
        f->noElem--;
        return true;
    }
}

// Reinicializa fila
bool filaDelete(FILA *f)
{
    f->inicio = 0;
    f->noElem = 0;
}

int main()
{
    return 0;
}