#include <stdio.h>

int arr[] = {9, 8, 4, 6, 3};

void bubbleSort(int *arr, int n);

int main()
{
    bubbleSort(arr, 5);
    return 0;
}

void bubbleSort(int *arr, int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - (i + 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%i ", arr[i]);
}