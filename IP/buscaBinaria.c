#include <stdio.h>

int lista[] = {-78, -4, 0, 32, 52, 55, 63, 69, 125, 200};
int buscaBinaria(int *lista, int n, int x); // O ARRANJO PRECISA ESTAR ORDENADO!!!

int main()
{
    int result = buscaBinaria(lista, 10, 200);
    printf("%i\n", result);
    return 0;
}

int buscaBinaria(int *lista, int n, int x)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (lista[mid] < x)
            start = mid + 1;
        else if (lista[mid] > x)
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}
