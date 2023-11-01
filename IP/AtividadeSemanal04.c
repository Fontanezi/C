#include <stdio.h>

double areaTrapezio(double baseMaior, double baseMenor, double altura)
{
    double area = ((baseMaior + baseMenor) * altura) / 2;
    return area;
}

double areaRetangulo(double base, double altura)
{
    double area = areaTrapezio(base, base, altura);
    return area;
}

double areaQuadrado(double lado)
{
    double area = areaRetangulo(lado, lado);
    return area;
}

int main()
{
    printf("Área do trapézio: %f\n", areaTrapezio(3, 2, 1));
    printf("Área do trapézio: %f\n", areaRetangulo(11, 27));
    printf("Área do quadrado: %f\n", areaQuadrado(5));
}