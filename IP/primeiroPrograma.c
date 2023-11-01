/*
Programa para calcular a área
de uma casa (e seus cômodos)
de 3 cômodos: uma sala de
10X10m, um banheiro e um
quarto de 5X7m cada.
*/

#include <stdio.h>

int main()
{
    printf("Programa para cálculo da área da casa\n");
    printf("A área da sala é %i\n", 10 * 10);
    printf("A área do quarto é %i\n", 5 * 7);
    printf("A área do banheiro é %i\n", 5 * 7);
    printf("A área total é %i\n", 10 * 10 + 5 * 7 + 5 * 7);

    return 0;
}