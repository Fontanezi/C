#include <stdio.h>

int buscaSequencial(int *A, int n, int ch)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == ch)
        {
            return i;
        }
    }
    return 0;
}

// O(n)

int main()
{
    return 0;
}