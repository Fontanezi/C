#include <stdio.h>
#include <stdlib.h>
// Memórias têm endereços expressos em hexadecimal.

int x = 10;
int *y = &x;

int main()
{
    int *w = (int *)malloc(sizeof(int));
    *w = 30;
    printf("%p é o endereço da variável PONTEIRO W.\n", &w);
    printf("%p é o endereço pra onde o PONTEIRO W aponta.\n", w);
    printf("%i é o valor da variável apontada pelo PONTEIRO W.\n", *w);
    printf("%i é o valor da variável X.\n", x);
    printf("%p é o endereço da variável X.\n", &x);
    printf("%p é o valor da variável PONTEIRO Y.\n", y);
    printf("%p é o endereço da variável PONTEIRO Y.\n", &y);
    printf("%i é o valor da variável apontada pelo PONTEIRO Y.\n", *y);
    free(w);
    return 0;
}