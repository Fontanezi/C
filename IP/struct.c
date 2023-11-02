#include <stdio.h>

struct casa
{
    float lateral;
    float quarto;
};

typedef struct aux
{
    float lateral;
    float cquarto;
} casa;

int main()
{
    struct casa c1;
    casa c2;
    c1.lateral = 11;
    c2.lateral = 15;
    printf("A lateral da casa1 vale: %.2f\n", c1.lateral);
    printf("A lateral da casa2 vale: %.2f\n", c2.lateral);
    return 0;
}