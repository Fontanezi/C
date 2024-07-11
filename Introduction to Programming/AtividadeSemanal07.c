#include <stdio.h>

int main()
{
    int x, y, z;

    printf("Entre com três inteiros:");

    scanf("%d %d %d", &x, &y, &z);
    if (x > y && x > z)
    {
        printf("O maior número é %d.\n", x);
    }
    else if (y > x && y > z)
    {
        printf("O maior número é %d.\n", y);
    }
    else if (z > x && z > y)
    {
        printf("O maior número é %d.\n", z);
    }
    else
    {
        printf("Os números são iguais.\n");
    }
}
