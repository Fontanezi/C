#include <stdio.h>

int largura, altura;

void ret(int largura, int altura)
{
    for (int j = 0; j < altura; j++)
    {
        for (int i = 0; i < largura; i++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    printf("Insira a largura e a altura do retângulo: \n");
    scanf("%i %i", &largura, &altura);
    ret(largura, altura);
    return 0;
}