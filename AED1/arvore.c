#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Permitem o uso da busca binária em estruturas de alocação dinâmica.
// Um conjunto de nós. Temos um nó raiz e subárvores.
// O grau de cada nó consiste no número de subárvores que ele contém.
// Nós de grau 0 são chamados de folhas ou externos. Os outros são internos.
// Nós abaixo de outro são chamados de descendentes.
// A árvore vai crescendo por níveis.
// A altura de um nó é o comprimento do caminho mais longo entre ele e uma folha.
// SEMPRE PERCORRE DA RAIZ PRA FOLHA.
// A altura da árvore é a altura do nó raiz. O endereço da árvore é o endereço do nó raiz.
// A profunidade de um nó é a distância dele até a raiz.

// ÁRVORE BINÁRIA - Abaixo de cada nó existem no máximo duas subárvores. Grau 0, 1 ou 2.

typedef struct aux
{
    int chave;
    struct aux *esq, *dir;
} NO;

int main()
{
    return 0;
}