#include <stdio.h>
#include <stdlib.h>

typedef enum{esquerdo, direito} LADO;

typedef struct aux{
    int chave
    struct aux *esq, *dir;
} NO;

void criaNo(int chave) {
    NO* no = (NO *)malloc(sizof(NO));
    no -> chave = chave;
    no -> esq = null;
    no -> dir = null;
    return no;
};

void criaArvore ((NO*)* raiz, int chave){
    *raiz = criaNo(chave);
}

void buscaChave(NO* raiz, int ch){
    if (raiz == null) return NULL;
    if (raiz -> chave == ch) return raiz;
    PONT aux = buscaChave(raiz->esq, ch);
    if (aux) return aux;
    return buscaChave(raiz->dir, ch);
}

bool insereNo(NO* raiz, int ch, int chPai, LADO lado){
    NO* pai = buscaChave(raiz, chPai);
    if (!pai) return 0;
    NO* novo = criaNo(ch);
    if (lado == esquerdo){
        // E se tiver alguém lá? Depende do combinado.
        pai->esq = novo;
    } else {
        // E se tiver alguém lá? Depende do combinado.
        pai->dir = novo;
    }
    return true;
}

int main(){
    NO* raiz;
    criaArvore(&raiz, 40);
}