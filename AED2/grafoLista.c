#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct aux
{
    int vertice;
    struct aux *prox;
} ElemLista, *PONT;

typedef struct
{
    int numVertices;
    int numArestas;
    ElemLista **A;
} Grafo;

bool inicializaGrafo(Grafo *g, int vertices)
{
    if (g == NULL || vertices < 1)
        return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    g->A = (ElemLista **)malloc(sizeof(ElemLista *) * vertices);
    int x;
    for (x = 0; x < vertices; x++)
    {
        g->A[x] = NULL;
    }
    return true;
}

void exibeGrafo(Grafo *g)
{
    if (!g)
        return;
    printf("\nImprimindo grafo (vertices : % i; arestas : % i).\n", g->numVertices, g->numArestas);
    ElemLista *atual;
    int x;
    for (x = 0; x < g->numVertices; x++)
    {
        printf("[%2i]", x);
        atual = g->A[x];
        while (atual)
        {
            printf(" ->%3i ", atual->vertice);
            atual = atual->prox;
        }
        printf("\n");
    }
}

bool liberaGrafo(Grafo *g)
{
    if (g == NULL)
        return false;
    ElemLista *atual, *apagar;
    int x;
    for (x = 0; x < g->numVertices; x++)
    {
        atual = g->A[x];
        while (atual)
        {
            apagar = atual;
            atual = atual->prox;
            free(apagar);
        }
    }
    free(g->A);
    g->numVertices = 0;
    g->numArestas = 0;
    g->A = NULL;
    return true;
}

bool insereArestaAux(Grafo *g, int v1, int v2)
{
    ElemLista *novo, *ant = NULL;
    ElemLista *atual = g->A[v1];
    while (atual && atual->vertice < v2)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2)
        return false;
    novo = (ElemLista *)malloc(sizeof(ElemLista));
    novo->vertice = v2;
    novo->prox = atual;
    if (ant)
        ant->prox = novo;
    else
        g->A[v1] = novo;
    return true;
}

bool insereAresta(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 ||
        v1 >= g->numVertices || v2 >= g->numVertices ||
        v1 == v2)
        return false;
    if (insereArestaAux(g, v1, v2))
    {
        insereArestaAux(g, v2, v1);
        g->numArestas++;
    }
    return true;
}

bool removeArestaAux(Grafo *g, int v1, int v2)
{
    ElemLista *ant = NULL;
    ElemLista *atual = g->A[v1];
    while (atual && atual->vertice < v2)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual && atual->vertice == v2)
    {
        if (ant)
            ant->prox = atual->prox;
        else
            g->A[v1] = atual->prox;
        free(atual);
        return true;
    }
    return false;
}

bool removeAresta(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 ||
        v1 >= g->numVertices || v2 >= g->numVertices)
        return false;
    if (removeArestaAux(g, v1, v2))
    {
        removeArestaAux(g, v2, v1);
        g->numArestas--;
        return true;
    }
    return false;
}

bool arestaExiste(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 ||
        v1 >= g->numVertices || v2 >= g->numVertices)
        return false;
    ElemLista *atual = g->A[v1];
    while (atual && atual->vertice < v2)
        atual = atual->prox;
    if (atual && atual->vertice == v2)
        return true;
    return false;
}

int numeroDeVertices(Grafo *g)
{
    if (g != NULL)
        return g->numVertices;
    else
        return -1;
}

int numeroDeArestas(Grafo *g)
{
    if (g != NULL)
        return g->numArestas;
    else
        return -1;
}

bool possuiVizinhos(Grafo *g, int v)
{
    if (!g || v < 0 || v >= g->numVertices || !(g->A[v]))
        return false;
    return true;
}

int retornaGrauDoVertice(Grafo *g, int v)
{
    if (!g || v < 0 || v >= g->numVertices)
        return -1;
    int grau = 0;
    ElemLista *atual = g->A[v];
    while (atual)
    {
        grau++;
        atual = atual->prox;
    }
    return grau;
}