#include <stdio.h>

int num[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int buscaSequencial(int n, int v[], int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
        if (v[i] > x)
        {
            break;
        }
    }
    return -1;
}

int main()
{
    printf("%i\n", buscaSequencial(11, num, 11));
    printf("%i\n", buscaSequencial(11, num, 37));
    return 0;
}