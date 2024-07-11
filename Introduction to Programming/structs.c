#include <stdio.h>

struct exemplo
{
    int dado1;
    int dado2;
};

// ou

typedef struct
{
    int dado1;
    int dado2;
} exemplo2;

typedef struct auxT
{
    int dado1;
    int dado2;
    struct auxT *proximo;
} exemplo3;

int main()
{
    struct exemplo e1;
    e1.dado1 = 10;
    e1.dado2 = 20;

    exemplo2 e2;
    e2.dado1 = 30;
    e2.dado2 = 40;
    return 0;

    exemplo3 *e3 = (exemplo3 *)malloc(sizeof(exemplo3));
    e3->dado1 = 50;
}