#include <stdlib.h>
#include <stdio.h>

typedef struct aux
{
    int id;
    struct aux *mae;
    struct aux *pai;
} PESSOA;

PESSOA *inicializar(int id)
{
    PESSOA *person = (PESSOA *)malloc(sizeof(PESSOA));
    person->id = id;
    person->mae = NULL;
    person->pai = NULL;
    return person;
}

void registrar(PESSOA *filho, PESSOA *mae, PESSOA *pai)
{
    filho->mae = mae;
    filho->pai = pai;
}

int main()
{
    PESSOA *m = inicializar(1);
    PESSOA *p = inicializar(2);
    PESSOA *f = inicializar(3);

    registrar(f, m, p);

    printf("%p %p %p\n", f, f->mae, f->pai);

    return 0;
}