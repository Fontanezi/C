#include <stdio.h>

float validTri(float x, float y, float z)
{
    if (x + y < z || x + z < y || y + z < x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float triType(float x, float y, float z)
{
    if (x == y && y == z)
    {
        return 1;
    }
    else if (x == y || x == z || y == z)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int main()
{
    float x, y, z;
    printf("Entre com os valores dos lados do triângulo:\n");
    scanf("%f %f %f", &x, &y, &z);
    if (validTri(x, y, z) == 1)
    {
        printf("Os valores não formam um triângulo válido.\n");
    }
    else
    {
        printf("Os valores formam um triângulo válido.\n");
        if (triType(x, y, z) == 1)
        {
            printf("O triângulo é equilátero.\n");
        }
        else if (triType(x, y, z) == 2)
        {
            printf("O triângulo é isósceles.\n");
        }
        else
        {
            printf("O triângulo é escaleno.\n");
        }
    }
    return 0;
}