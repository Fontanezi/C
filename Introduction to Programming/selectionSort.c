#include <stdio.h>
int num[] = {9, 8, 4, 6, 3};

void selectionSort(int v[], int tam)
{
    int i, p, aux, posMenor;
    for (i = 0; i < tam - 1; i++)
    {
        posMenor = i;
        for (p = i + 1; p < tam; p++)
        {
            if (v[p] < v[posMenor])
            {
                posMenor = p;
            }
        }
        aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;
    }
}

int main()
{
    selectionSort(num, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}