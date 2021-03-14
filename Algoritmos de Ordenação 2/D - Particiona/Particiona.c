#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high, int pivot);
void print(int vector[], int from, int to);

int main()
{
    int q, p, i, menor = 1000000, maior = 0, indexMenor = 0, indexMaior = 0;
    // int vectorU[10000], vectorAux[10000];
    //
    scanf("%d\n", &q);
    scanf("%d\n", &p);

    // printf("q1 %d\n", q1);
    // printf("q2 %d\n", q2);

    int vactor[q];

    for (i = 0; i < q; i++)
    {
        scanf("%d", &vactor[i]);
    
    }
    swap(&vactor[p], &vactor[q - 1]);
    // print(vactor, 0, q);

    // print(vactor, 0, q);
    // printf("Maior: %d\n", indexMenor);
    // printf("Menor: %d\n", indexMaior);
    partition(vactor, 0, q - 1, vactor[p]);
    print(vactor, 0, q);
}

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int pivsot)
{

    int pivot = arr[high];    // pivot 
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
            // printf("swap ");
        }

        // printf("i: %d, j: %d", i, j);
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void print(int *vector, int from, int to)
{
    int i;
    for (i = from; i < to; i++)
    {
        printf("%d%s", vector[i], i < to - 1 ? "\n" : "\n");
    }
}