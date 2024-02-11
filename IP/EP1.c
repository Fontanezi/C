/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Prof. Marcos Lordello Chaim                                   **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   João Fontanezi                   14747191                     **/
/**                                                                 **/
/*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
int diasMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void verificaBissexto(int ano)
{
    if (ano % 4 == 0)
    {
        diasMeses[1] = 29;
    }
}

int verificaDataValida(int d, int m, int a)
{
    if (a < 0 || m < 1 || m > 12 || d < 1 || d > diasMeses[m - 1])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int contaDias(int d, int m, int a)
{
    printf("Próximos dias de encontro de todos os clubes:\n");
    while (m < 12)
    {
        for (int i = 0; i < 60; i++)
        {
            ++d;
            if (d > diasMeses[m - 1])
            {
                m++;
                d = 1;
            }
        }
        if (m > 12)
        {
            break;
        }
        printf("%d/%d/%d\n", d, m, a);
    }
}

int main()
{
    int dia, mes, ano;

    printf("Entre com a data de inicio do ano letivo:\n");
    printf("Entre com o dia: ");
    scanf("%d", &dia);
    printf("Entre com o mes: ");
    scanf("%d", &mes);
    printf("Entre com o ano: ");
    scanf("%d", &ano);

    verificaBissexto(ano);
    if (!verificaDataValida(dia, mes, ano))
    {
        printf("Dados incorretos\n");
        exit(1);
    }
    contaDias(dia, mes, ano);
    return 0;
}