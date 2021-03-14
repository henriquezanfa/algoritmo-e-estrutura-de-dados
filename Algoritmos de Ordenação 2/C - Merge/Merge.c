#include <stdio.h>
#include <stdlib.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int, int);
void print(int *, int);

int main()
{
    int n, *arr;
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    print(arr, n);
    mergeSort(arr, 0, n - 1, n);
    print(arr, n);

    return 0;
}

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r, int n)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, n);
        mergeSort(arr, m + 1, r, n);

        print(arr, n);
        merge(arr, l, m, r);
    }
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
}