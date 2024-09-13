#include <stdio.h>

int c;
float converte(int c)
{
    float f = (c * 1.8) + 32;
    return f;
}
int main()
{
    printf("Digite a temperatura em Celsius:\n");
    scanf("%d", &c);
    printf("A temperatura em Fahrenheit é: %.1f\n", converte(c));
    return 0;
}