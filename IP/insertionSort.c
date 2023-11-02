#include <stdio.h>

int arr[] = {9, 8, 4, 6, 3};

void insertionSort(int *arr, int n);

int main()
{
    insertionSort(arr, 5);
    return 0;
}

void insertionSort(int *arr, int n)
{
    int i, j, aux;
    for (i = 0; i < n; j++)
    {
        for (j = 0; j < n - 1; i++)
        {
            if (arr[j + 1] < arr[j])
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