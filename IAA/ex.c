#include <stdio.h>
int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int buscaBinaria(int A[], int b);

int main()
{
    int result = buscaBinaria(A, 11);
    printf("%d\n", result);
    return 0;
}

int buscaBinaria(int A[], int b)
{
    int i = 1;
    int j = 10;
    while (i <= j)
    {
        int m = (i + j) / 2;
        if (b < A[m])
        {
            j = m - 1;
        }
        else if (b > A[m])
        {
            i = m + 1;
        }
        else
        {
            return m;
        }
    }

    return -1;
}