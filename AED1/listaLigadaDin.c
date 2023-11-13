#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Para evitar a necessidade de definição antecipada do tamanho máximo da estrutura de implementação estática
(i.e., o vetor), podemos tirar proveito dos recursos de alocação dinâmica de memória das linguagens de
programação como C, deixando o gerenciamento de nós livres / ocupados a cargo do ambiente de
programação. Esta técnica constitui à implementação dinâmica de listas ligadas, e requer o uso das funções
disponibilizadas em malloc.h: */

typedef struct estrutura
{
    int chave;
    int info;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO *inicio;
} LISTA;

// Inicialização
void inicializarLista(LISTA *l)
{
    l->inicio = NULL;
}

// Exibição da lista completa
void exibirLista(LISTA l)
{
    NO *p = l.inicio;
    while (p)
    {
        printf("%d ", p->chave);
        p = p->prox;
    }
}

// Retornar o primeiro elemento da lista
NO *primeiroElemLista(LISTA l)
{
    return (l.inicio);
}

// Retornar o último elemento da lista
NO *ultimoElemLista(LISTA l)
{
    NO *p = l.inicio;
    if (p)
        while (p->prox)
            p = p->prox;
    return (p);
}

// Retornar o enésimo elemento da lista
NO *enesimoElemLista(LISTA l, int n)
{
    NO *p = l.inicio;
    int i = 1;
    if (p)
        while ((p->prox) && (i < n))
        {
            p = p->prox;
            i++;
        }
    if (i != n)
        return (NULL);
    else
        return (p);
}

// Quantos elementos existem na lista
int tamanhoLista(LISTA l)
{
    NO *p = l.inicio;
    int tam = 0;
    while (p)
    {
        tam++;
        p = p->prox;
    }
    return (tam);
}

// Busca pela chave ch na lista (ordem crescente) retornando p e ant
NO *buscaSeqOrd(int ch, LISTA l, NO **ant)
{
    NO *p = l.inicio;
    *ant = NULL;
    while (p)
    {
        if (p->chave >= ch)
            break;
        *ant = p;
        p = p->prox;
    }
    if (p)
        if (p->chave == ch)
            return (p);
    return (NULL);
}

// Inserção da chave ch na lista ordenada sem duplicações
bool inserirElemListaOrd(int ch, LISTA *l)
{
    NO *novo;
    NO *ant;
    novo = buscaSeqOrd(ch, *l, &ant);
    if (novo)
        return (false);
    novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    if (!l->inicio)
    { // 1a. inserção em lista vazia
        l->inicio = novo;
        novo->prox = NULL;
    }
    else
    {
        if (!ant)
        { // inserção no início da lista
            novo->prox = l->inicio;
            l->inicio = novo;
        }
        else
        { // inserção após um nó existente
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }
    return (true);
}

// Anexar novo elemento ao final da lista, duplicado ou não
void anexarElemLista(int ch, LISTA *l)
{
    NO *novo;
    NO *ant;
    ant = ultimoElemLista(*l);
    novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    if (!ant)
        l->inicio = novo;
    else
        ant->prox = novo;
}

// Exclusão da chave dada
bool excluirElemLista(int ch, LISTA *l)
{
    NO *ant;
    NO *elem;
    elem = buscaSeqOrd(ch, *l, &ant);
    if (!elem)
        return (false); // nada a excluir
    if (!ant)
        l->inicio = elem->prox; // exclui 1o. elemento da lista
    else
        ant->prox = elem->prox; // exclui elemento que possui ant
    free(elem);                 // exclusão “física”
    return (true);
}

// Destruição da lista
void destruirLista(LISTA *l)
{
    NO *atual;
    NO *prox;
    atual = l->inicio;
    while (atual)
    {
        prox = atual->prox; // guarda próxima posição
        free(atual);        // libera memória apontada por atual
        atual = prox;
    }
    l->inicio = NULL; // ajusta início da lista (vazia)
}

int main()
{

    return 0;
}