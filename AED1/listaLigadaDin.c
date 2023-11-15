#include <stdio.h>
#include <stdlib.h>

// tamanho máximo do vetor estático
#define MAX 50

/* Em uma lista ligada de implementação dinâmica, não há mais uso de vetores. Cada elemento da lista é uma
estrutura do tipo NO, que contém os dados de cada elemento (inclusive a chave) e um ponteiro prox para o
próximo nó da lista. Um nome auxiliar (estrutura) é usado para permitir a auto-referência ao tipo NO que está
sendo definido. */

// ESTRUTURA NÓ DA LISTA (OS PRÓPRIOS ELEMENTOS)
typedef struct estrutura
{
    int chave;
    int info;
    struct estrutura *prox;
} NO;

// LISTA EM SI (PONTEIRO PRO PRIMEIRO NÓ
typedef struct
{
    NO *inicio;
} LISTA;

// NO *p = (NO *)malloc(sizeof(NO)); // cria um novo nó em memória, apontado por p
// free(p);                          // a área de memória apontada por p é liberada;

int main()
{

    return 0;
}