#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Como não há ordem de inserção, a busca não é eficiente. Buscaremos a partir da raiz.

typedef enum
{
    esq,
    dir
} LADO;

typedef struct aux
{
    int chave;
    struct aux *esq, *dir;
} NO;

// Busca chave na árvore
NO *buscarChave(NO *raiz, int ch)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else if (raiz->chave == ch)
    {
        return raiz;
    }
    NO *aux = buscarChave(raiz->esq, ch);
    if (aux)
    {
        return aux;
    }
    else
    {
        return buscarChave(raiz->dir, ch);
    }
}

// Cria um nó
NO *criaNo(int ch)
{
    NO *new = (NO *)malloc(sizeof(NO));
    new->chave = ch;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}

// Cria o nó raiz
void arvoreInit(NO **raiz, int ch)
{
    *raiz = criaNo(ch);
}

// Insere nó filho
bool arvoreInsert(NO **raiz, int ch, int chPai, LADO lado)
{
    NO *pai = buscarChave(raiz, chPai);
    if (!pai)
    {
        return false;
    }
    NO *new = criaNo(ch);
    if (lado == esq)
    {
        new->esq = pai->esq; // Se o filho já estiver lá
        pai->esq = new;
    }
    else
    {
        new->esq = pai->dir; // Se o filho já estiver lá
        pai->dir = new;
    }
    return true;
}

int main()
{
    return 0;
}