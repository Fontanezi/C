#include <stdio.h>

double areaRetangulo(double base, double altura)
{
    double area = base * altura;
    return area;
}

double areaQuadrado(double lado)
{
    double area = areaRetangulo(lado, lado);
    return area;
}

int main()
{
    double base, altura;
    printf("Entre com a base e a altura do retângulo:\n");
    scanf("%lf %lf", &base, &altura);
    printf("A área do retângulo é: %.2lf\n", areaRetangulo(base, altura));
    return 0;
}