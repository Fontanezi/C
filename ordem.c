#include <stdio.h>
int arr[] = {4, 3, 7, 22, 17, 82};

void insertionSort(int v[], int tam)
{
    int key, step, j;
    j = 0;

    for (step = 1; step < tam; ++step)
    {
        key = v[step], j = step - 1;
        while (j >= 0 && key < v[j])
        {
            v[j + 1] = v[j];
            v[j] = key;
            --j;
        }
    }
    for (int i = 0; i < tam; ++i)
    {
        printf("%d ", v[i]);
    }
}
int main()
{
    insertionSort(arr, 6);
    return 0;
}