#include <stdio.h>

void rectangle(int l, int h)
{
    printf("\n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    rectangle(6, 5);
    return 0;
}