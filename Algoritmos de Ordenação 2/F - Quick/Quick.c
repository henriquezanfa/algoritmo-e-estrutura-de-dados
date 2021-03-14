#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int size);
void swap(int *a, int *b);
int partition(int arr[], int low, int high, int size);
void quickSort(int arr[], int low, int high, int size);

int main()
{
    int n, i;
    int *vector;

    scanf("%d\n", &n);

    vector = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &vector[i]);
    }

    print(vector, n);

    quickSort(vector, 0, n - 1, n);

    print(vector, n);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int size)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }

        print(arr, size);
    }
    swap(&arr[i + 1], &arr[high]);
    print(arr, size);

    return (i + 1);
}

void quickSort(int arr[], int low, int high, int size)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, size);

        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

void print(int vector[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d%s", vector[i], i < size - 1 ? " " : "");

    printf("\n");
}