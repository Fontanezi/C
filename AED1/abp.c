#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum{esquerda, direita} LADO

typedef struct aux{
    int chave;
    struct aux esq*, dir*;
} NO;

NO* init(){
    return NULL;
} 

NO* insereNo(NO* raiz, NO* no){
    if (raiz == NULL) return no;
    if (no -> chave < raiz -> chave){
        raiz -> esq = insereNo(raiz -> esq, no);
    } else {
        raiz -> dir = insereNo(raiz -> dir, no);
    }
    // Ignora chaves iguais
    return raiz;
}

NO* criaNo(int ch){
    NO* no = (NO*)malloc(sizeof(NO));
    no -> esq = NULL;
    no -> dir = NULL;
    no -> chave = ch;
    return no;
}

NO* buscaNo(int ch, NO* raiz){
    if (raiz == NULL) return NULL;
    if (raiz -> chave == ch) return raiz;
    if (raiz -> chave > ch) return buscaNo(ch, raiz -> esq);
    return buscaNo(ch, raiz -> dir);
}

int contaNos(NO* raiz){
    if (!raiz) return 0;
    return (contaNos(raiz -> esq) + 1 + contaNos(raiz -> dir));
}

int main(){
    NO* raiz = init();
    NO* no = criaNo(23)
    raiz = insereNo(raiz, no)
    no = criaNo(12);
    raiz = insereNo(raiz, no)
    return 0; 
}