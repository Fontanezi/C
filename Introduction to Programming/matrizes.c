#include <stdio.h>

int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

int main()
{
    int **matriz2 = (int **)malloc(sizeof(int) * 3);
    matriz2[0] = (int *)malloc(sizeof(int) * 3);
    matriz2[1] = (int *)malloc(sizeof(int) * 3);
    matriz2[2] = (int *)malloc(sizeof(int) * 3);
    return 0;
}

