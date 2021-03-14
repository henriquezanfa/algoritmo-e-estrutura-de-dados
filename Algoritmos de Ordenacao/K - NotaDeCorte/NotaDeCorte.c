#include <stdlib.h>
#include <stdio.h>

void invert(int *a, int *b);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int notaDeCorte(int notas[], int numeroDeNotas, int numeroDeAlunos);

int main()
{
    unsigned int numeroDeAlunos, numeroDeNotas, i;
    unsigned int *notas, *aux;

    scanf("%d %d", &numeroDeNotas, &numeroDeAlunos);

    notas = (unsigned int *)malloc(sizeof(unsigned int) * numeroDeNotas);
    aux = (unsigned int *)malloc(sizeof(unsigned int) * numeroDeNotas);

    for (i = 0; i < numeroDeNotas; i++)
        scanf("%d", &notas[i]);

    mergeSort(notas, 0, numeroDeNotas - 1);

    printf("%d\n", notaDeCorte(notas, numeroDeNotas, numeroDeAlunos));
}

int notaDeCorte(int notas[], int numeroDeNotas, int numeroDeAlunos)
{
    int i, resultado = 0;

    for (i = numeroDeNotas - 1; i >= numeroDeNotas - numeroDeAlunos; i--)
    {
        resultado += notas[i];
    }

    return resultado / numeroDeAlunos;
}

void merge(int arr[], int l, int m, int r)
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
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void invert(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}