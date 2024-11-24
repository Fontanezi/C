/** @file ep.c
 * @brief Solução para o EP
 * 
 * @author João Fontanezi NUSP 14747191
 */

#include "ep.h"

int *grauDoVertice;
int *arestaUsada;

// Função que retorna o nome e NUSP
char *autor (void) {
    return "João Fontanezi ; 14747191";
}

// Verifica se a solução atual é válida (circuito hamiltoniano).
int ehSolucao (struct grafo *G, int verticeAtual, int passos) {
    return passos == G->N && G->A[3 * G->S[G->M - 1]] == verticeAtual;
}

// Implementa a busca por tentativa e erro. 
int tenta(struct grafo *G, int verticeAtual, int passos) {
    if (ehSolucao(G, verticeAtual, passos)) {
        return 1;
    }
    for (int i = 0; i < G->M; i++) {
        if (!arestaUsada[i]) {
            int proxVertice;
            if (G->A[3 * i] == verticeAtual) {
                proxVertice = G->A[3 * i + 1];
            } else if (G->A[3 * i + 1] == verticeAtual) {
                proxVertice = G->A[3 * i];
            } else {
                continue;
            }
            if (grauDoVertice[proxVertice] < 2) {
                grauDoVertice[verticeAtual]++;
                grauDoVertice[proxVertice]++;
                arestaUsada[i] = 1;
                G->S[passos - 1] = i;
                if (tenta(G, proxVertice, passos + 1)) {
                    return 1;
                }
                grauDoVertice[verticeAtual]--;
                grauDoVertice[proxVertice]--;
                arestaUsada[i] = 0;
            }
        }
    }
    return 0;
}

// Inicializa e executa o backtracking.
int iniciaEexecuta(struct grafo *G, int verticeInicial) {
    grauDoVertice = calloc(G->N, sizeof(int));
    arestaUsada = calloc(G->M, sizeof(int));
    int resultado = tenta(G, verticeInicial, 1);
    free(grauDoVertice);
    free(arestaUsada);
    return resultado;
}

// Limpa memória alocada.
void termina() {
    // Não há alocação dinâmica no backtracking; nada a liberar.
}
