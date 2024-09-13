#include <stdio.h>
int num[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int buscaBinaria(int num[], int n, int x)
{
    int start = 0;
    int end = n - 1;
    int mid = (end + start) / 2;
    while (start <= end)
    {
        if (num[mid] == x)
        {
            return mid;
        }
        else if (num[mid] > x)
        {
            end = mid - 1;
            mid = (end + start) / 2;
        }
        else
        {
            start = mid + 1;
            mid = (end + start) / 2;
        }
    }
    return -1;
}

int main()
{
    printf("%i\n", buscaBinaria(num, 12, 13));
    printf("%i\n", buscaBinaria(num, 12, 3));
    printf("%i\n", buscaBinaria(num, 12, 31));
    printf("%i\n", buscaBinaria(num, 12, 42));
    return 0;
}

/* Usar quando há muitas buscas, quando dados sofrem pouca alteração na chave de busca,
e quando inserções ou remoções não são frequentes.*/