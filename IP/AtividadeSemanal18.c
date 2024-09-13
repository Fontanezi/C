#include <stdio.h>

typedef struct aux
{
    float baseMenor;
    float baseMaior;
    float altura;
} TRAPEZIO;

float areaTrapezio1(TRAPEZIO t1)
{
    float area = ((t1.baseMaior + t1.baseMenor) * t1.altura) / 2;
    return area;
}

float areaTrapezio2(TRAPEZIO *r1)
{
    float area = ((r1->baseMaior + r1->baseMenor) * r1->altura) / 2;
    return area;
}

int main()
{
    TRAPEZIO trap;
    trap.baseMenor = 3.5;
    trap.baseMaior = 4.5;
    trap.altura = 2.125;
    printf("Area do trapezio: %.2f\n", areaTrapezio1(trap));

    printf("Area do trapezio: %.2f\n", areaTrapezio2(&trap));

    return 0;
}

/* SAIDA
Area do trapezio: 8.50
Area do trapezio: 8.50
*/