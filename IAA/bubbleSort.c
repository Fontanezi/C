#include <stdio.h>

void bubble_sort(int vetor[], int n)
{
    int k, j, aux;

    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - k; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

// O(n^2)
// BOM PRA MUITOS DADOS

int main()
{
    return 0;
}