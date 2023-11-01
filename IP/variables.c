#include <stdio.h>
#include <math.h>

int main()
{
    double raio = 2;
    double areap;
    float lateral = 11;
    float cquarto = 7;
    float areaq;
    float areas;
    float areat;
    printf("Programa para cálculo da área da casa\n");
    areas = lateral * lateral;
    printf("A área da sala é %f\n", areas);
    areaq = cquarto * (lateral / 2);
    printf("A área do quarto é %f\n", areaq);
    printf("A área do banheiro é %f\n", areaq);
    areap = M_PI * raio * raio;
    printf("A área da piscina é %f\n", areap);
    areat = areas + (2 * areaq) + areap;
    printf("A área total é %f\n", areat);
    return 0;
}