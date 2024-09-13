#include <stdio.h>

int main()
{
    int nusp = 14747191;
    printf("Imprimindo inteiro: %i\n", nusp);
    printf("Imprimindo numero: %d\n", nusp);
    printf("Imprimindo float (com cast): %f\n", (float)nusp);
    printf("Imprimindo quociente: %i\n", nusp / 2);
    printf("Imprimindo resto: %d\n", nusp % 2);
    printf("Imprimindo quadrado: %d\n", nusp * nusp);
    return 0;
}

// SAÍDA

/*Imprimindo inteiro: 14747191
  Imprimindo numero: 14747191
  Imprimindo float (com cast): 14747191.000000
  Imprimindo quociente: 7373595
  Imprimindo resto: 1
  Imprimindo quadrado: -321609775 (Maior do que o máximo suportado por INT)*/