#include <stdio.h>

int main()
{
    float pol = 2.54;
    float p = pol * 12;
    float jar = p * 3;
    float cm;

    printf("Entre com o valor em centímetros desejado para a conversão:\n");
    scanf("%f", &cm);
    printf("O valor em polegadas é: %.2f\n", (cm / pol));
    printf("O valor em pés é: %.2f\n", (cm / p));
    printf("O valor em jardas é: %.2f\n", (cm / jar));

    return 0;
}