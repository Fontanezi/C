#include <stdio.h>

int main()
{
    float x, y, z;

    printf("Entre com três inteiros:");
    scanf("%f %f %f", &x, &y, &z);
    if (x > y && x > z)
    {
        printf("%.2f", x);
    }
    else if (y > x && y > z)
    {
        printf("%.2f", y);
    }
    else
    {
        printf("%.2f", z);
    }
}