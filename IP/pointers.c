#include <stdio.h>
#include <stdlib.h>

int n = 10;
int *p = &n;

int main()
{
    int *end3 = (int *)malloc(sizeof(int));

    printf("Valor de n: %i\n", n);
    printf("Endereço de memória de n: %p\n", &p);
    printf("Valor de p: %i\n", *p);
    printf("\n");
    *end3 = 11;
    printf("Valor de end3: %p\n", end3);
    printf("Endereço de end3: %p\n", &end3);
    printf("Conteúdo apontado por end3: %i\n", *end3);
    free(end3);
}