/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   João Fontanezi                             14747191           **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int dia, mes, ano;
int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int diasAno = 365;

int verificaDataValida(int d, int m, int a);
void contador(int d, int m, int a);

int main()
{
    printf("Entre com a data de inicio do ano letivo:\n");
    printf("Entre com o dia: ");
    scanf("%d", &dia);
    printf("Entre com o mes: ");
    scanf("%d", &mes);
    printf("Entre com o ano: ");
    scanf("%d", &ano);

    if (!verificaDataValida(dia, mes, ano))
    {
        printf("Dados incorretos\n");
        exit(1);
    }

    printf("Data de inicio do ano letivo: %d/%d/%d\n", dia, mes, ano);

    printf("Proximos dias de encontro de todos os clubes:\n");
    contador(dia, mes, ano);
}

int verificaDataValida(int d, int m, int a)
{
    if (a % 4 == 0)
    {
        diasMes[1] = 29;
        diasAno += 1;
    }

    if (a < 0 || m < 1 || m > 12)
    {
        return 0;
    }

    if (d < 1 || d > diasMes[m - 1])
    {
        return 0;
    }

    for (int i = 0; i < (m - 1); i++)
    {
        diasAno -= diasMes[i];
        diasAno -= d;
    }
    return 1;
}

void contador(int d, int m, int a)
{
    for (int i = 1; i <= diasAno; i++)
    {
        d++;
        if (d > diasMes[m - 1])
        {
            d = 1;
            m++;
        }
        if (i % 60 == 0)
        {
            printf("%d/%d/%d\n", d, m, a);
        }
    }
}