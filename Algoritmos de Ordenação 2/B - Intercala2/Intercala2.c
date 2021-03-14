#include <stdio.h>
#include <stdlib.h>

void intercala(int vector[], int size);
// void mergeSort(long int arr[], int l, int r);
int * merge(int *arr, int l, int m, int r);
void print(int vector[], int from, int to);

int main()
{
    int q1, q2, i, size;
    // int vectorU[10000], vectorAux[10000];
    //
    scanf("%d\n", &q1);
    scanf("%d\n", &q2);

    // printf("q1 %d\n", q1);
    // printf("q2 %d\n", q2);
    size = q1 + q2;

    int vactor[size];

    for (i = 0; i < size; i++)
    {
        scanf("%d", &vactor[i]);
    }

    merge(vactor, 0, q1 - 1, size);

    print(vactor, 0, size);
}

void print(int *vector, int from, int to)
{
    int i;
    for (i = from; i < to; i++)
    {
        printf("%d%s", vector[i], i < to - 1 ? "\n" : "\n");
    }
}

int * merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
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

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return arr;
}

// /* l is for left index and r is right index of the 
//    sub-array of arr to be sorted */
// void mergeSort(long int arr[], int l, int r)
// {
//     if (l < r)
//     {
//         // Same as (l+r)/2, but avoids overflow for
//         // large l and h
//         int m = l + (r - l) / 2;

//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m + 1, r);

//         merge(arr, l, m, r);
//     }
// }
