/*********************************************************************/
/**   ACH2024 - Algoritmos e Estruturas de Dados II                 **/
/**   EACH-USP - Primeiro Semestre de 2025                          **/
/**   Prof. Luciano Digiampietri                                    **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   João Fontanezi                               14747191         **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define NUM_CARACT 10
#define MAX_VALOR 99

#define true 1
#define false 0

typedef int bool;

/* Estrutura para representar nosso grafo usando matriz binaria de adjacencias */
typedef struct
{
    int numVertices;
    int numArestas;
    bool **matriz;
    int **caracteristicas;
} Grafo;

/* Funcao auxiliar para o sistema de correcao automatica (nao mexer) */
void printf123()
{
    // Funcao usada pelo sistema de correcao automatica (nao mexer)
}

/* Funcao que inicializa o grafo cujo endereco foi passado como parametro.
   Isto e, cria a matriz de adjacencias (preenchida com false),
   e atribui valor para numVertices (recebendo o valor passado por parametro)
   e numArestas igual a zero.
*/
bool inicializaGrafo(Grafo *g, int vertices)
{
    if (g == NULL || vertices < 1)
        return false;
    g->numVertices = vertices;
    g->numArestas = 0;
    int x, y;
    g->matriz = (bool **)malloc(sizeof(bool *) * vertices);
    g->caracteristicas = (int **)malloc(sizeof(int *) * vertices);
    for (x = 0; x < vertices; x++)
    {
        g->matriz[x] = (bool *)malloc(sizeof(bool) * vertices);
        for (y = 0; y < vertices; y++)
        {
            g->matriz[x][y] = false;
        }
        g->caracteristicas[x] = (int *)malloc(sizeof(int) * NUM_CARACT);
        for (y = 0; y < NUM_CARACT; y++)
        {
            g->caracteristicas[x][y] = -1;
        }
    }
    return true;
}

/* Funcao que libera a memoria da matriz de adjacencia do grafo cujo endereco
   foi passado como parametro.
*/
bool liberaGrafo(Grafo *g)
{
    if (g == NULL)
        return false;
    int x;
    for (x = 0; x < g->numVertices; x++)
    {
        free(g->matriz[x]);
        free(g->caracteristicas[x]);
    }
    free(g->matriz);
    free(g->caracteristicas);
    g->numVertices = 0;
    g->numArestas = 0;
    g->matriz = NULL;
    g->caracteristicas = NULL;
    return true;
}

/* Funcao que retorna o numero de vertices do grafo apontado por g, caso o
   endereco armazenado em g seja diferente de NULL. Caso contrario, retorna -1.
*/
int numeroDeVertices(Grafo *g)
{
    if (g != NULL)
        return g->numVertices;
    else
        return -1;
}

/* Funcao que retorna o numero de arestas do grafo apontado por g, caso o
   endereco armazenado em g seja diferente de NULL. Caso contrario, retorna -1.
*/
int numeroDeArestas(Grafo *g)
{
    if (g != NULL)
        return g->numArestas;
    else
        return -1;
}

/* Funcao que retorna true se o vertice v possui um ou mais
   vertices adjacentes (vizinhos).
*/
bool possuiVizinhos(Grafo *g, int v)
{
    if (!g || v < 0 || v >= g->numVertices)
        return false;
    int x;
    for (x = 0; x < g->numVertices; x++)
        if (g->matriz[v][x])
            return true;
    return false;
}

/* Funcao que insere uma nova aresta no grafo.
   Se os vertices passados como parametro forem validos, ha duas possibilidades:
   - a aresta nao existia;
   - a aresta existia.
*/
bool insereAresta(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || v1 == v2)
        return false;
    if (g->matriz[v1][v2] == false)
    {
        g->matriz[v1][v2] = true;
        g->matriz[v2][v1] = true;
        g->numArestas++;
    }
    return true;
}

/* Funcao que exclui a aresta entre v1 e v2 (caso exista uma aresta valida
   entre v1 e v2) e retorna true; ou retorna false, caso contrario.
*/
bool removeAresta(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || g->matriz[v1][v2] == false)
        return false;
    g->matriz[v1][v2] = false;
    g->matriz[v2][v1] = false;
    g->numArestas--;
    return true;
}

/* Funcao que adiciona atualiza o valor de da caracteristica c do vertice v.
 */
bool atualizaCaracteristica(Grafo *g, int v, int c, int valor)
{
    if (!g || v < 0 || c < 0 || v >= g->numVertices || c >= NUM_CARACT || valor < -1)
        return false;
    g->caracteristicas[v][c] = valor;
    return true;
}

/* Funcao que retorna true se existe uma aresta valida entre v1 e v2
   e false caso contrario.
*/
bool arestaExiste(Grafo *g, int v1, int v2)
{
    if (!g || v1 < 0 || v2 < 0 || v1 >= g->numVertices || v2 >= g->numVertices || g->matriz[v1][v2] == false)
        return false;
    return true;
}

/* Funcao que cria um grafo com o numero de vertices e
   numero de arestas passados como parametro e retorna seu endereco.
*/
Grafo *criaGrafoAleatorio(int numVertices, int numArestas)
{
    printf("### Criando grafo: v=%i e a=%i ###\n", numVertices, numArestas);
    int x, y, a = 0;
    if (numVertices < 1 || numArestas >= numVertices * (numVertices - 1) / 2)
    {
        printf("Parametros invalidos, o grafo nao sera gerado.\n");
        return NULL;
    }
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    inicializaGrafo(g, numVertices);
    while (a < numArestas)
    {
        x = rand() % numVertices;
        y = rand() % numVertices;
        if (x != y && g->matriz[x][y] == false)
        {
            g->matriz[x][y] = true;
            g->matriz[y][x] = true;
            a++;
        }
    }
    g->numArestas = numArestas;
    for (x = 0; x < numVertices; x++)
    {
        for (y = 0; y < NUM_CARACT; y++)
        {
            if (rand() % 3 < 2)
            {
                g->caracteristicas[x][y] = rand() % 5;
            }
        }
    }
    return g;
}

/* Funcao desenvolvida para exibir um grafo, no formato de uma matriz
   de adjacencia.
*/
void exibeGrafo(Grafo *g)
{
    if (!g)
        return;
    int x, y;
    printf("\nImprimindo grafo (v=%i; a=%i)\n   ", g->numVertices, g->numArestas);
    for (x = 0; x < g->numVertices; x++)
        printf(" %3i", x);
    printf("\n");
    for (x = 0; x < g->numVertices; x++)
    {
        printf("%3i", x);
        for (y = 0; y < g->numVertices; y++)
            printf(" %3i", g->matriz[x][y]);
        printf("\n");
    }
    printf("\nCaracteristicas:\n");

    for (x = 0; x < g->numVertices; x++)
    {
        printf("[%2i]", x);
        for (y = 0; y < NUM_CARACT; y++)
            printf(" %3i", g->caracteristicas[x][y]);
        printf("\n");
    }
}

/* Funcao que exibe os valores de um arranjo de numeros reais */
void exibeArranjoReais(double *arranjo, int n)
{
    int x;
    for (x = 0; x < n; x++)
        printf("  v%i\t", x);
    printf("\n");
    for (x = 0; x < n; x++)
    {
        printf("%3.2f\t", arranjo[x]);
    }
    printf("\n\n");
}

/* Funcao que exibe os valores de um arranjo de numeros inteiros */
void exibeArranjoInteiros(int *arranjo, int n)
{
    int x;
    for (x = 0; x < n; x++)
        printf(" v%i\t", x);
    printf("\n");
    for (x = 0; x < n; x++)
    {
        printf("%3i\t", arranjo[x]);
    }
    printf("\n\n");
}

/* Funcao que calcula a homofilia entre o vertice v e os demais */
void homofilia(Grafo *g, int v, int *valores)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        int cont = 0;
        for (int j = 0; j < NUM_CARACT; j++)
        {
            if (g->caracteristicas[v][j] != -1 &&
                g->caracteristicas[v][j] == g->caracteristicas[i][j])
            {
                cont++;
            }
        }
        valores[i] = cont;
    }
}

/* Funcao que pondera as caracteristicas comuns entre o vertice v e os demais
   de acordo com sua raridade. */
void raridade(Grafo *g, int v, double *valores)
{
    int n = g->numVertices;
    for (int i = 0; i < n; i++)
    {
        double soma = 0;
        for (int j = 0; j < NUM_CARACT; j++)
        {
            int val = g->caracteristicas[v][j];
            if (val == -1 || g->caracteristicas[i][j] != val)
                continue;

            int cont = 0;
            for (int k = 0; k < n; k++)
            {
                if (g->caracteristicas[k][j] == val)
                    cont++;
            }
            if (cont > 0)
                soma += 1.0 / cont;
        }
        valores[i] = soma;
    }
}

/* Funcao que da mais pesos as caracteristicas mais presentes nos amigos
   do vertice v e calcula a influencia social entre o vertice v e os demais */
void influenciaSocial(Grafo *g, int v, int *valores)
{
    int n = g->numVertices;
    for (int i = 0; i < n; i++)
    {
        int soma = 0;
        for (int j = 0; j < NUM_CARACT; j++)
        {
            int val = g->caracteristicas[i][j];
            if (val == -1)
                continue;

            int cont = 0;
            for (int k = 0; k < n; k++)
            {
                if (g->matriz[v][k] && g->caracteristicas[k][j] == val)
                    cont++;
            }
            soma += cont;
        }
        valores[i] = soma;
    }
}

/* Funcao que calcula o numero de amigos em comum entre o vertice v
   e os demais */
void amizadesEmComum(Grafo *g, int v, int *valores)
{
    int n = g->numVertices;
    for (int i = 0; i < n; i++)
    {
        int comum = 0;
        for (int j = 0; j < n; j++)
        {
            if (g->matriz[v][j] && g->matriz[i][j])
                comum++;
        }
        valores[i] = comum;
    }
}

/* Funcao que calcula a distancia entre o vertice v e os demais */
void proximidadeSocial(Grafo *g, int v, int *valores)
{
    int n = g->numVertices;
    int fila[n], visitado[n], dist[n];
    int ini = 0, fim = 0;

    for (int i = 0; i < n; i++)
    {
        visitado[i] = 0;
        dist[i] = n; 
    }

    fila[fim++] = v;
    visitado[v] = 1;
    dist[v] = 0;

    while (ini < fim)
    {
        int u = fila[ini++];
        for (int i = 0; i < n; i++)
        {
            if (g->matriz[u][i] && !visitado[i])
            {
                visitado[i] = 1;
                dist[i] = dist[u] + 1;
                fila[fim++] = i;
            }
        }
    }

    for (int i = 0; i < n; i++)
        valores[i] = dist[i];
}

/* Funcao que usa o principio da conexao preferencial e calcula
   o grau de cada vertice */
void conexaoPreferencial(Grafo *g, int v, int *valores)
{
    int n = g->numVertices;
    for (int i = 0; i < n; i++)
    {
        int grau = 0;
        for (int j = 0; j < n; j++)
        {
            if (g->matriz[i][j])
                grau++;
        }
        valores[i] = grau;
    }
}

/* Funcao que invoca e exibe os valores de cada uma das funcoes que voces
   devem implementar neste EP.
*/
void testaFuncoes(Grafo *g, int n, int v)
{

    int *valoresInteiros = (int *)malloc(sizeof(int) * n);
    double *valoresReais = (double *)malloc(sizeof(double) * n);

    printf("\nRealizando analise em relacao ao vertice %i.\n", v);

    printf("Homofilia:\n");
    homofilia(g, v, valoresInteiros);
    exibeArranjoInteiros(valoresInteiros, n);

    printf("Raridade:\n");
    raridade(g, v, valoresReais);
    exibeArranjoReais(valoresReais, n);

    printf("Influencia Social:\n");
    influenciaSocial(g, v, valoresInteiros);
    exibeArranjoInteiros(valoresInteiros, n);

    printf("Amizades em Comum:\n");
    amizadesEmComum(g, v, valoresInteiros);
    exibeArranjoInteiros(valoresInteiros, n);

    printf("Proximidade Social:\n");
    proximidadeSocial(g, v, valoresInteiros);
    exibeArranjoInteiros(valoresInteiros, n);

    printf("Conexao Preferencial:\n");
    conexaoPreferencial(g, v, valoresInteiros);
    exibeArranjoInteiros(valoresInteiros, n);

    free(valoresInteiros);
    free(valoresReais);
}

/* Funcao main para testar as funcoes implementadas neste EP.
   Esta parte do codigo nao sera usada na correcao do EP e nao contempla
   todos os testes possiveis.
   Fique a vontade para realizar testes adicionais.
*/
int main()
{

    int n = 5;
    int *valoresInteiros = (int *)malloc(sizeof(int) * n);
    double *valoresReais = (double *)malloc(sizeof(double) * n);

    Grafo g1;

    printf("PRIMEIRO EXEMPLO\n");

    inicializaGrafo(&g1, n);
    insereAresta(&g1, 0, 1);
    insereAresta(&g1, 0, 2);
    insereAresta(&g1, 1, 4);
    insereAresta(&g1, 1, 3);
    insereAresta(&g1, 2, 3);

    atualizaCaracteristica(&g1, 0, 2, 2);
    atualizaCaracteristica(&g1, 0, 1, 1);
    atualizaCaracteristica(&g1, 1, 1, 1);
    atualizaCaracteristica(&g1, 1, 2, 2);
    atualizaCaracteristica(&g1, 1, 3, 3);
    atualizaCaracteristica(&g1, 2, 2, 2);
    atualizaCaracteristica(&g1, 3, 2, 2);
    atualizaCaracteristica(&g1, 4, 3, 3);
    atualizaCaracteristica(&g1, 4, 2, 5);
    atualizaCaracteristica(&g1, 4, 4, 4);

    exibeGrafo(&g1);

    testaFuncoes(&g1, n, 0);

    printf("\n\nSEGUNDO EXEMPLO\n");

    // Excluindo duas arestas do grafo
    removeAresta(&g1, 0, 2);
    removeAresta(&g1, 2, 3);

    exibeGrafo(&g1);

    testaFuncoes(&g1, n, 0);

    printf("\n\nTERCEIRO EXEMPLO\n");
    // Analisando outro vertice

    exibeGrafo(&g1);

    testaFuncoes(&g1, n, 3);

    /* Grafo gerado aleatoriamente - pode ficar diferente
       de acordo com o compilador usado.                 */
    printf("\n\nQUARTO EXEMPLO\n\n");
    n = 6;
    int arestas = 8;

    Grafo *g2 = criaGrafoAleatorio(n, arestas);

    exibeGrafo(g2);

    testaFuncoes(g2, n, 1);

    free(g2); // Implementando o free do grafo g2, alocado dinamicamente (não podemos deixar nenhum endereço pra trás).
    free(valoresInteiros);
    free(valoresReais); // Implementando free dos valores alocados dinamicamente na main.

    return 0;
}
