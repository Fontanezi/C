#include <stdio.h>
#include <stdlib.h>

int arrEst[3] = {0, 1, 2};

int main()
{
    int *arrDin = (int *)malloc(sizeof(int) * 3);
    arrDin[0] = 0;
    arrDin[1] = 1;
    arrDin[2] = 2;

    for (int i = 0; i < 3; i++)
    {
        printf("arrEst[%d] = %d\n", i, arrEst[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("arrDin[%d] = %d\n", i, arrDin[i]);
    }
    return 0;
}

// Passagem de parâmetro por cópia - Não modifica o valor original.
// Passagem de parâmetro por referência - Modifica o valor original.