#include <stdio.h>

int buscaBinaria(int *A, int n, int ch)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid == ch)
        {
            return mid;
        }
        else if (ch > A[mid])
        {
            start = mid + 1;
        }
        else if (ch < A[mid])
        {
            end = mid - 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}