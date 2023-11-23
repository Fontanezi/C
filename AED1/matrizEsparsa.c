#include <stdio.h>
#include <stdlib.h>

typedef struct tempNo
{
    int valor;
    int coluna;
    struct tempNo *prox;
} NO;

typedef struct
{
    NO *A;
    int linhas;
    int colunas;
} MATRIZ;

int main()
{

    return 0;
}