#include <stdio.h>

int buscaSequencial(int x, int v[], int n);

int main()
{
    int n;
    int x;
    int result;
    printf("Choose a number to search in the array:");
    scanf("%d", &x);
    printf("Choose the size of the array:");
    scanf("%d", &n);
    int v[n];
    printf("Choose the elements of the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    result = buscaSequencial(x, v, n);
    printf("%d\n", result);
    return 0;
}

int buscaSequencial(int x, int v[], int n)
{
    if (v[0] == x)
        return 0;
    else if (v[n - 1] == x)
        return n - 1;
    return buscaSequencial(x, v, n - 1);
}