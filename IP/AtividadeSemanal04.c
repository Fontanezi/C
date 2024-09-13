#include <stdio.h>

double areaTrapezio(double bM, double bm, double h)
{
    double area = (bM + bm) * h / 2;
    return area;
}

double areaRetangulo(double base, double altura)
{
    double area = areaTrapezio(base, base, altura); // Imprimirá 10, a área do retângulo pela formula do trapezio.
    return area;
}

double areaQuadrado(double lado)
{
    double area = areaRetangulo(lado, lado);
    return area;
}

int main()
{
    printf("Area do trapezio: %.2lf\n", areaTrapezio(5, 3, 2));
    printf("Area do retangulo: %.2lf\n", areaRetangulo(5, 2));
    printf("Area do quadrado: %.2lf\n", areaQuadrado(5));
    return 0;
}