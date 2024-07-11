#include <stdio.h>
int num[] = {9, 8, 4, 6, 3};

int bubbleSort(int v[], int n)
{
    int ult, i, temp;
    for (ult = n - 1; ult > 0; ult--)
    {
        for (i = 0; i < ult; i++)
        {
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}

int main()
{
    bubbleSort(num, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}
